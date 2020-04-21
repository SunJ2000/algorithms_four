// heapsort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "..\sort.h"

void sink(vector<int>& a,int k, int n)
{
    while (2 * k+1 <= n)
    {
        int j = 2 * k+1;
        if (j+1<=n && a[j] < a[j +1])j++;
        if (a[k] >= a[j])break;
        exch(a, k, j);
        k = j;
    }
}

void heapsort(vector<int>& a)
{
    int n = a.size()-1 ;                    //注意，这里的n是从0开始的，所以子节点的索引时母节点的2k+1；
    for (int k = n/ 2; k >= 0; k--)
    {
        sink(a, k, n);
    }
    while (n > 0)
    {
        exch(a, 0, n--);
        sink(a, 0, n);
    }
}
int main()
{
    vector<int> a = { 9,8,7,5,4,6,3,2,1,0 };
    heapsort(a);
    vector_print(a);
    return 0;
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
