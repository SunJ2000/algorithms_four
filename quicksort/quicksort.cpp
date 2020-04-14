// quicksort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "../sort.h"

int partition(vector<int>& a, int lo, int hi)
{
    int i = lo, j = hi;
    while (true)
    {
        while (a[lo] > a[i])
        {
            i++;
            if (i = hi)break;       //防止第一个元素比后面所有的元素都大；
        }
        while (a[lo] < a[j])
        {
            j--;
            if (j == lo)break;      //防止第一个元素比后面所有的元素都小；
        }
        if (i >= j) break;              //注意此处
        exch(a, i, j);      
    }
    exch(a, lo, j);
    return j;
}
void sort(vector<int>& a,int lo,int hi)
{
    int j = partition(a, lo, hi);
    sort(a, lo, j);
    sort(a, j + 1, hi);
}
void quicksort(vector<int>& a)
{
    sort(a, 0, a.size() - 1);
}

int main()
{
    text(quicksort);
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
