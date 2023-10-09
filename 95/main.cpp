/*
给你一个整数 n ，请你生成并返回所有由 n 个节点组成且节点值从 1 到 n 互不相同的不同 二叉搜索树 。可以按 任意顺序 返回答案。
*/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// create dp array to store n node position's possible trees

vector<TreeNode*> generateTrees(int n) {
    vector<vector<TreeNode*>> dp(n+1);
    dp[0].emplace_back(nullptr);
    TreeNode first = TreeNode(1);
    dp[1].emplace_back(&first);
    return dp[n];
}

int main(){
    generateTrees(5);
    exit(0);
}