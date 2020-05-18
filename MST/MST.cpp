// MST.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int v, w;
    double weight;
    node(int v, int w, int weight) :v(v), w(w), weight(weight) {};
    node(){};
    int other(int i)
    {
        if (i == v)return w;
        return v;
    }
    bool operator<(node& e)
    {
        return weight < e.weight;
    }
};
class Graph
{
private:
    vector<vector <node>> adj;
    vector<bool>marked;
    vector<node> mst;
    vector<node> pq;
    int e, v;
    //重置marked
    void re_marked()
    {
        for (auto item = marked.begin(); item != marked.end(); item++)
        {
            *item = false;
        }
    }
    node delmin(vector<node>& pq)
    {
        node min = pq[0];
        vector<node>::iterator itemin;
        for (auto ite = pq.begin() + 1; ite != pq.end(); ite++)
        {
            if (*ite < min)
            {
                min = *ite;
                itemin = ite;
            }
        }
        pq.erase(itemin);
        return min;
    }
    void visit(int v)
    {
        marked[v] = true;
        for (auto e: adj[v])
        {
            if (!marked[e.other(v)]) pq.push_back(e);
        }
    }
public:
    Graph(int v) :v(v), e(0), marked(v, false)
    {
        for (int i = 0; i <= v; i++)
        {
            adj.push_back(vector<node>());
        }

    }
    void put(int v1, int v2,int weight)
    {
        adj[v1].push_back(node(v1,v2,weight));
        adj[v2].push_back(node(v2,v1,weight));
        e++;
    }
    void LasyPrimMst()
    {
        visit(0);
        while (!pq.empty())
        {
            node e = delmin(pq);
            int v = e.v;
            int w = e.w;
            if (marked[v] && marked[w]) continue;
            mst.push_back(e);
            if (!marked[v])visit(v);
            else visit(w);
            
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
