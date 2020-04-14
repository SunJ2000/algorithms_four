// mergesort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "../sort.h"

vector<int> aux(100,0);

void merge(vector<int> &a, int lo, int mid, int hi)
{
    int i = lo;
    int j = mid+1;
    for (int k = lo; k <= hi; k++)
    {
        aux[k]=a[k];
    }
    for (int k = lo; k <= hi; k++)
    {
        if (i > mid)           a[k] = aux[j++];
        else if (j >hi)      a[k] = aux[i++];
        else if (a[i] > a[j])  a[k] = aux[j++];
        else                   a[k] = aux[i++];
    }
    
}

void sort(vector<int>& a, int lo,int hi)
{
    if (hi <= lo) return;
    int mid = lo + (hi - lo) / 2;
    sort(a, lo,  mid);
    sort(a, mid + 1, hi);               
    merge(a, lo, mid, hi);
}
void mergesort(vector<int> & a)
{
    int hi = a.size();
    sort(a, 0, hi-1);
}
int main()
{
    vector<int> b = { 8,10,6,9};
    merge(b, 0, 1, 3);
    vector_print(b);
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
