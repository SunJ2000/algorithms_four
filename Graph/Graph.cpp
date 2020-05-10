// Graph.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class Graph
{
private:
    vector<vector <int>> adj;
    vector<bool>marked;
    vector<int> edge;
    int e, v,count;
    //重置edge,多次利用edge这个数组
    void re_edge()
    {
        for (auto item = edge.begin(); item != edge.end(); item++)
        {
            *item = -1;
        }
    }
    //重置marked
    void re_marked()
    {
        for (auto item = marked.begin(); item != marked.end(); item++)
        {
            *item = false;
        }
    }
    //深度优先查找路径
    void dfs(int s)     
    {
        
        marked[s] = true;
        for (int w : adj[s])
        {
            if (!marked[w])
            {
                edge[w] = s;
                dfs(w);
            }
        }
    }
    //广度优先查找最短路径
    void bfs(int s)     
    {
        queue<int> que;
        marked[s] = true;
        que.push(s);
        while (!que.empty())
        {
            int v = que.back();
            que.pop();
            for (auto w : adj[v])
            {
                if (!marked[w])
                {
                    marked[w] = true;
                    edge[w] = v;
                    que.push(w);
                }
            }
        }
    }
    //标记s点的连通图号
    void dfs_link(int s,int count)
    {
        marked[s] = true;
        edge[s] = count;
        for (int w : adj[s])
        {
            if (!marked[w])
            {
                dfs_link(w,count);
            }
        }
    }
    //遍历，将所有点的连通图号都标记出
    void CC()
    {
        for (int i = 0; i < v; i++)
        {
            if (!marked[i])
            {
                dfs_link(i, count);
                count++;
            }
        } 
    }
public:
    Graph(int v) :v(v),e(0), marked(v, false), edge(v, -1),count(0)
    { 
        for (int i = 0; i <= v; i++) 
        { 
            adj.push_back(vector<int>());
        }
       
    }
    void put(int v1, int v2)
    {
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
        e++;
    }
    int V() { return v; };
    int E() { return e; };
    void path_to(int star,int end)
    {
        re_marked();
        re_edge();
        cout << "路径是（dfs):" << endl;
        dfs(star);
        while (edge[end] != -1)
        {
            cout << end << "-";
            end = edge[end];
        }
        cout << end<<endl;
        
    }
    void short_path_to(int star, int end)
    {
        re_marked();
        re_edge();
        cout << "路径是（bfs)" << endl;
        bfs(star);
        while (edge[end] != -1)
        {
            cout << end << "-";
            end = edge[end];
        }
        cout << end<<endl;

    }
    void link_graph()
    {
        re_marked();
        re_edge();
        CC();
        vector<vector<int>> link_graph(count,vector<int>());
        for (size_t i = 0; i < edge.size(); i++)
        {
            link_graph[edge[i]].push_back(i);
        }
        cout << "共有" << count << "个连通图" << endl;
        for (size_t i = 0; i < link_graph.size();i++)
        {
            cout << "num" << i << endl;
            for (auto w : link_graph[i])
            {
                cout << w << ends;
            }
            cout << endl;
        }

    }
};

class union_find    //加权union算法，不用构造树就可计算连通图数量,深度小的树加在深度大的树上面
{
private:
    vector<int> sz;
    vector<int> id;
    int count;
    void union_(int p, int q)
    {
        int i = find(p);
        int j = find(q);
        if (sz[i] > sz[j]) 
        {
            id[j] = i;
        }
        else
        { 
            id[i] = j; 
            if (sz[i] == sz[j])
                sz[j] += 1;   
        }
        count--;
    }
public:
    union_find(int n) :count(n)
    {
        for (int i = 0; i < n; i++)
        {
            sz.push_back(1);
            id.push_back(i);
        }
    }
    int find(int p)
    {
        while (id[p] != p)
        {
            p = id[p];
        }
        return p;
    }
    void put(int a, int b)
    {
        if (find(a) != find(b))
        {
            union_(a, b);
        }
    }
};
int main()
{
    Graph graph(12);
 
    multimap<int, int> e = { {0,1},{0,2},{0,6},{0,5},{5,3} ,{5,4},{3,4} ,
    {9,11},{9,10},{7,8}, {4,6} };
    
    for (auto item = e.begin(); item != e.end(); item++)
    {
       
        graph.put(item->first, item->second);
    }
    
    graph.path_to(0, 3);
    graph.short_path_to(0, 3);
    graph.link_graph();
    return 0;
}

