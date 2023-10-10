/*
下降路径 
可以从第一行中的任何元素开始，并从每一行中选择一个元素。
在下一行选择的元素和当前行所选元素最多相隔一列（即位于正下方或者沿对角线向左或者向右的第一个元素）。
具体来说，位置 (row, col) 的下一个元素应当是 (row + 1, col - 1)、(row + 1, col) 或者 (row + 1, col + 1) 
*/

// dp[i][j] = min{dp[i-1][j] + cost[i][j], dp[i-1][j+1] + cost[i][j], dp[i-1][j-1] + cost[i][j]}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min_num(int a, int b){
    if (a < b){
        return a;
    }
    return b;
}

int min_num_three(int a, int b, int c){
    if (a > b){
        if (b < c){
            return b;
        }
        return c;
    }else {
        if (a < c){
            return a;
        }
        return c;
    }
}

int minFallingPathSum(vector<vector<int>>& matrix) {
    vector<vector<int>> dp = matrix;
    
    for (int row = 1; row < matrix.size(); row++){
        for (int col = 0; col < matrix[0].size(); col++){
            if (col == 0){
                dp[row][col] = min_num(dp[row-1][col], dp[row-1][col+1]) + matrix[row][col];
                continue;
            }
            if (col == matrix[0].size()-1){
                dp[row][col] = min_num(dp[row-1][col], dp[row-1][col-1]) + matrix[row][col];
                continue;
            }
            dp[row][col] = min_num_three(dp[row-1][col], dp[row-1][col+1], dp[row-1][col-1]) + matrix[row][col];
        }
    }
    int min_step = dp[matrix.size()-1][0];
    for (int j = 1; j < matrix[0].size(); j++){
        if (dp[matrix.size()-1][j] < min_step){
            min_step = dp[matrix.size()-1][j];
        }
    }
    return min_step;
}

int main(){
    vector<vector<int>> matrix = {{2,1,3}, {6,5,4}, {7,8,9}};
    cout << minFallingPathSum(matrix) << endl;
    exit(0);
}