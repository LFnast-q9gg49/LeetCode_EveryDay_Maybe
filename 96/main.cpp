/*
给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。
*/

// use dp arr to store the count of kind of Binary Sort Tree

#include <iostream>

using namespace std;

int numTrees(int n) {
    if (n == 0){
        return 1;
    }
    if (n == 1){
        return 1;
    }
    int dp[n+1];
    for (int j = 0; j <= n; j++){
        dp[j] = 0;
    }
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++){
        for (int j = 0; j < i; j++){
            dp[i] += dp[j]*dp[i-j-1];
        }
    }
    return dp[n];
}

int main(int argc, char **argv){
    cout << numTrees(3) << endl;
    exit(0);
}