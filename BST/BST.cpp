// BST.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//应该用智能指针
#include <iostream>
using namespace std;

struct node
{
    node * left;
    node * right;
    int key;
    int val;
    int n;
    node(int key, int val, int n) :key(key), val(val), n(n) {};
};
class BST
{
private:
    node* root;
public:
    int get(int key) { return get(root, key); }
    void put(int key, int val) { root =put(root, key, val); }
    int size() { return size(root); }
    node* select(int k) { return select(root, k); }
private:
    int size(node* x) { if (x == nullptr)return 0; return x->n; }
    int get(node* x, int key);
    node * put(node* x, int key, int val);
    node* select(node* x, int k);
    int rank(node* x, int key);
    node* deletemin(node* x)       
    {
        if (x->left = nullptr) {
            node* t = x->right;
            delete x;
            return t;
        }
        x->left = deletemin(x->left);
        x->n = size(x->left) + size(x->right) + 1;
        return x;
    }
    node* min(node* x) { if (x->left == NULL)return x; else return min(x->left); }
    node* deletenode(node* x,int key);
    
};
int BST::get(node *x, int key)              //get value;
{
    if (x == nullptr)cout << "no node" << endl;
    else if (key == x->key) return x->val;
    else if (key > x->key) return get(x->right, key);
    else return get(x->left, key);
}
node* BST::put(node* x, int key, int val)           //if (exist) change value,else add new node;
{
    if (x == nullptr) {
        return new node(key,val,1);
    }
    else if (key == x->key) x->val = val;
    else if (key > x->key) x->right=put(x->right,key,val);
    else  x->left=put(x->left,key,val);
    x->n = size(x->left) + size(x->right) + 1;
    return x;
}
node* BST::select(node* x, int k)           //find  a node whose key'rank is k;
{
    if (x == NULL)cout << "no node" << endl;
    int t = size(x->left);
    if (t == k) return x;
    else if (t > k) return select(x->left, k);
    else return select(x->right, k - t - 1);
}
int BST::rank(node* x, int key)
{
    if (x == nullptr)cout << "no node";
    if (key > x->key) return size(x->left) + 1 + rank(x->right, key);
    else if (key < x->key) return rank(x->left, key);
    else return size(x->left);
}
node* BST::deletenode(node* x,int key)
{
    if (x == NULL)cout << "no node" << endl;
    if (key > x->key) x->right=deletenode(x->right, key);
    else if (key < x->key)x->left=deletenode(x->left, key);
    else {
        node* t = new node(*min(x->right));
        x->right = deletemin(x->right);
        x->key = t->key;
        x->val = t->val;  
    }
    x->n = size(x->left) + size(x->right) + 1;
    return x;
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
