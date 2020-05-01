// hashST.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<array>
using namespace std;

struct node
{
    int key;
    int value;
    shared_ptr<node> next;
    node(int key, int value) :key(key), value(value) {};
};
class separateChainST
{
private:
    array<shared_ptr<node>, 20> table;
public:
    void put(int key, int value);
    int get(int key);
    void delt(int key);
};
void separateChainST::put(int key, int value)
{
    int i = key % 20;
    shared_ptr<node> star = table[i];
    while (star != nullptr)
    {
        star = star->next;
    }
    star = make_shared<node>(key, value);
}
void separateChainST::delt(int key)
{
    int i = key % 20;
    shared_ptr<node> first, second;
    if (table[i] != NULL&&table[i]->key==key)
    {
        table[i] = table[i]->next;
    }
    first = second = table[i];  
    while (second!=NULL)
    {
        if (second->key != key)
        {
            first = second;
            second = first->next;

        }
        else
        {
            first->next = second->next;

        }
    } 
}



class lineST
{
private:
    array<int,40> Key,Value;
public:
    void put(int key, int value)
    {
        int i = key % 40;
        for (; Key[i] != NULL; i = (i + 1) % 40)
        {
            if (Key[i] == key)
            {
                Value[i] = value;
                return ;
            }
        }
        Key[i] = key;
        Value[i] = value;
    }
    void delt(int key)
    {
       auto it = find(Key.begin(), Key.end(), key);
        if (it==Key.end())
        {
            return;
        }
        int i = key % 40;
        while (Key[i] != key)
        {
            i = (i + 1) % 40;
        }
        Key[i] = NULL;
        Value[i] = NULL;
        i = (i + 1) % 40;
        while (Key[i] != NULL)
        {
            auto newkey = Key[i];
            auto newvalue = Value[i];
            Key[i] = NULL;
            Value[i] = NULL;
            put(newkey, newvalue);
            i = (i + 1) % 40;
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


