// Digraph.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <queue>
#include<stack>
using namespace std;

class Digraph
{
private:
    vector<vector <int>> adj;
    vector<bool>marked;
    vector<int> edge;
    stack<int> reverse_post;
    bool hascycle;
    int e, v, count;
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
    //逆后序排序
    void dfs_reversepost(int s)
    {

        marked[s] = true;
        for (int w : adj[s])
        {
            if (!marked[w])
            {
                edge[w] = s;
                dfs(w);
            }
            reverse_post.push(w);

        }
    }
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
    void dfs_cycle(int s, int v)
    {
        marked[s] = true;
        for (auto w : adj[s])
        {
            if (!marked[w])
                dfs_cycle(w, s);
            else if (v != w) hascycle = true;       //其实不用判断是否相等，无向图中才需要。
        }
    }
    void dfs_link(int s, int count)
    {
        marked[s] = true;
        edge[s] = count;
        for (int w : adj[s])
        {
            if (!marked[w])
            {
                dfs_link(w, count);
            }
        }
    }
public:
    Digraph(int v) :v(v), e(0), marked(v, false), edge(v, -1), count(0),hascycle(false)
    {
        for (int i = 0; i <= v; i++)
        {
            adj.push_back(vector<int>());
        }

    }
    void put(int v1, int v2)
    {
        adj[v1].push_back(v2);
        e++;
    }
    int V() { return v; };
    int E() { return e; };
    auto dfs_reversepost()
    {
        for (int i = 0; i < v; i++)
        {
            if (!marked[i])
                dfs_reversepost(i);
        }
        return reverse_post;
    }
    Digraph reverse()
    {
        Digraph graph(v);
        for (int i=0;i<v;i++)
        {
            for (auto w : adj[i])
            {
                graph.put(w, i);
            }
        }
        return graph;
    }
    void kosarajuscc()
    {
        re_marked();
        re_edge();
        Digraph graph = reverse();
        auto sta = graph.dfs_reversepost();
        while (!sta.empty())
        {
            int i = sta.top();
            sta.pop();
            for (int w = 0; w < v; w++) 
            {
                if (!marked[w])
                {
                    dfs_link(w, count);
                    count++;
                }
            }
        }
   }
};


int main()
{
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
