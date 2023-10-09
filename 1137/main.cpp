/*
泰波那契序列 Tn 定义如下：

T0 = 0, T1 = 1, T2 = 1, 且在 n >= 0 的条件下 Tn+3 = Tn + Tn+1 + Tn+2

给你整数 n，请返回第 n 个泰波那契数 Tn 的值。
*/
#include <iostream>
#include <vector>

using namespace std;

int tribonacci(int n)
{
    vector<int> tri_arr(4);
    tri_arr[0] = 0;
    tri_arr[1] = 1;
    tri_arr[2] = 1;
    if (n < 3){
        return tri_arr[n];
    }
    for (auto cnt = 3; cnt <= n; cnt++)
    {
        tri_arr[3] = tri_arr[0] + tri_arr[1] + tri_arr[2];
        tri_arr[0] = tri_arr[1];
        tri_arr[1] = tri_arr[2];
        tri_arr[2] = tri_arr[3];
    }
    return tri_arr[3];
}

int tribonacci_0(int n)
{
    vector<int> tri_arr;
    tri_arr.emplace_back(0);
    tri_arr.emplace_back(1);
    tri_arr.emplace_back(1);
    for (auto j = 3; j <= n; j++)
    {
        tri_arr.emplace_back(tri_arr[j - 1] + tri_arr[j - 2] + tri_arr[j - 3]);
    }
    return tri_arr[n];
}

int main(int argc, char **argv)
{
    int n = 25;
    cout << tribonacci(n) << endl;
    exit(0);
}