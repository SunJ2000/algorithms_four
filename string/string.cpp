// string.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;

template <typename T>
void sort_fornt( T & a,int n)  //根据字符串前n个字母排序；
{
    constexpr  int len = sizeof(a)/sizeof(*a);
    string aux[len+1];
    for (int d = 0; d< n; d++)
    {
        int  count[256] = { 0 };
        for (int i = 0; i < len; i++)
        {
            count[a[i][d]]++;
        }
        for (int i = 0; i < 255; i++)
        {
            count[i + 1] += count[i];
        }
        for (int i = 0; i < len; i++)
        {
       
            aux[count[a[i][d]-1]++] = a[i];
           
        }
        for (int i = 0; i < len; i++)
        {
            a[i] = aux[i];
        }
    
    }

}

string aux[5];
  int charAt(const string& str, int d)
    {
        if (d > str.size()) return -1;
        else return str[d] - 32;
    }
    void sort(string a[], const int lo, const int hig, int d)
    {
        if (lo >= hig) return;
        int count[100] = { 0 };     //可打印的ascii码总共97个，100够用了
        for (int i = lo; i <= hig; i++)
        {
            count[charAt(a[i], d)+2]++;
        }
        for (int i = 1; i < 99; i++)
        {
            count[i + 1] += count[i];
        }
        for (int i = lo; i <= hig; i++)
        {
            aux[count[charAt(a[i], d) +1]++] = a[i];
        }
        for (int i = lo; i <= hig; i++)
        {
            a[i] = aux[i];
        }
        for (int r = 0; r < 98; r++)
        {
            sort(a, lo + count[r], lo + count[r + 1] - 1, d + 1);
        }
    }
    template <typename T>
    void MSD(T& a)
    {
        sort(a, 0, 4, 0);
    }

int main()
{
    string a[5] = { "sun","jian","hao","hao","xue" };
   // sort_fornt(a, 3);
   // MSD(a);
 
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << ends;
    }
    MSD(a);
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
