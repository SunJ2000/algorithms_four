// Digraph.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Digraph
{
private:
    vector<vector <int>> adj;
    vector<bool>marked;
    vector<int> edge;
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
            else if (v != w) hascycle = true;
        }
    }
    void dfs_cycle_stack(int s)
    {

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
