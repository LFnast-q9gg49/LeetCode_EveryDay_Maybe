/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

网格中的障碍物和空位置分别用 1 和 0 来表示。
*/

#include <iostream>
#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    int grid[m][n];
    for (auto row = 0; row < m; row++){
        for (auto col = 0; col < n; col++){
            grid[row][col] = 0;
        }
    }

    for (auto i = 0; i < m; i++){
        if (obstacleGrid[i][0] == 1){
            break;
        }
        grid[i][0] = 1;
    }
    for (auto i = 0; i < n; i++){
        if (obstacleGrid[0][i] == 1){
            break;
        }
        grid[0][i] = 1;
    }
    
    for (auto row = 1; row < m; row++){
        for (auto col = 1; col < n; col++){
            if (obstacleGrid[row][col] == 1){
                continue;
            }
            grid[row][col] = grid[row-1][col] + grid[row][col-1];
        }
    }
    
    return grid[m-1][n-1];
}

int main(){
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    std::cout << uniquePathsWithObstacles(obstacleGrid) << std::endl;
    exit(0);
}

/*
for (auto row = 0; row < m; row++){
        for (auto col = 0; col < n; col++){
            std::cout << grid[row][col] << '\t';
        }
        std::cout << std::endl;
    }
    */