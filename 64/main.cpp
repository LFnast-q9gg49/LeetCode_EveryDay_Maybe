#include <iostream>
#include <vector>

/*
给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。
*/


// make 2-dimension dp array, each cell store the cost has spend
using namespace std;

int lesser(int a, int b){
    if (a>b){
        return b;
    }
    return a;
}

int minPathSum(vector<vector<int>>& grid) {
    int row = grid.size();
    int col = grid[0].size();

    // init
    int dp[row][col];
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            dp[i][j] = 0;
        }
        cout << endl;
    }
    dp[0][0] = grid[0][0];
    
    for (int i = 1; i < row; i++){
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }
    for (int j = 1; j < col; j++){
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }

    for (int i = 1; i < row; i++){
        for (int j = 1; j < col; j++){
            dp[i][j] = lesser(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    }

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cout << dp[i][j] << '\t';
        }
        cout << endl;
    }
    return dp[row-1][col-1];
}

int main(int argc, char ** argv){
    vector<vector<int>> grid = {{1,3,1}, {1,4,1}, {4,5,1}};
    cout << minPathSum(grid) << endl;
    exit(0);
}