/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

问总共有多少条不同的路径？
*/

#include <iostream>

int uniquePaths(int m, int n) {
    int grid[m][n];
    for (auto i = 0; i < m; i++){
        grid[i][0] = 1;
    }
    for (auto i = 0; i < n; i++){
        grid[0][i] = 1;
    }
    for (auto row = 1; row < m; row++){
        for (auto col = 1; col < n; col++){
            grid[row][col] = grid[row-1][col] + grid[row][col-1];
        }
    }

    // for (auto row = 0; row < m; row++){
    //     for (auto col = 0; col < n; col++){
    //         std::cout << grid[row][col] << '\t';
    //     }
    //     std::cout << std::endl;
    // }
    return grid[m-1][n-1];
}

int main(){
    std::cout << uniquePaths(7,3) << std::endl;
    exit(0);
}