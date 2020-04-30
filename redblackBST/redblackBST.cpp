// redblackBST.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
constexpr auto red = false;
constexpr auto black = true;
using namespace std;

struct node
{
    int key;
    int value;
    int n;
    shared_ptr<node> left, right;
    bool color;
    node(int a, int b, int c,bool color) :key(a), value(b), n(c), color(color) {};     
};
class redblackBST
{
private:
    shared_ptr<node> root;
public:
    void put(int key, int value)
    {
        put(root, key, value);
        root->color = black;
    }
private:
    shared_ptr<node> put(shared_ptr<node> h, int key, int value);
    shared_ptr<node> turnleft(shared_ptr<node> h)
    {
        shared_ptr<node> x = h->right;
        h->right = x->left;
        x->left = h;
        x->color = h->color;
        h->color = red;
        x->n = h->n;
        h->n = 1 + h->left->n + h->right->n;
        return x;
    }
    shared_ptr<node> turnright(shared_ptr<node> h)
    {
        shared_ptr<node> x = h->left;
        h->left = x->right;
        x->right = h;
        x->color = h->color;
        h->color = red;
        x->n = h->n;
        h->n = 1 + h->left->n + h->right->n;
        return x;
    }
    void flipcolor(shared_ptr<node> h)
    {
        h->color = red;
        h->left->color = black;
        h->right->color = black;
    }
};
shared_ptr<node> redblackBST::put(shared_ptr<node> h, int key, int value)i
{
    if (h == NULL) h = make_shared<node>(key, value, 1,red);
    if (key < h->key)  put(h->left, key, value);
    else if (key > h->key)   put(h->right, key, value);
    else h->value = value;

    if (h->right->color == red && h->left->color == black) turnleft(h);
    if (h->left->color == red && h->left->left->color == red) turnright(h);
    if (h->left->color == red && h->right->color == red) flipcolor(h);
    h->n = 1 + h->left->n + h->right->n;
    return h;
}
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
