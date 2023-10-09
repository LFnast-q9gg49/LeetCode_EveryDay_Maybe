#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static bool checkValidGrid(vector<vector<int>>& grid) {
        int max = grid.size();
        int start = 0, end = max * max - 1;
        int start_x = 0, start_y = 0;
        
        while (start < end){
            
            bool flag = 0;
            cout << start_x << '\t' << start_y << endl;

            int posi_pos[8][3] = {
                {start_x+1, start_y+2, 0},
                {start_x-1, start_y+2, 0},
                {start_x+1, start_y-2, 0},
                {start_x-1, start_y-2, 0}, 
                {start_x+2, start_y+1, 0},
                {start_x+2, start_y-1, 0},
                {start_x-2, start_y+1, 0}, 
                {start_x-2, start_y-1, 0}};

            cout << posi_pos << endl;
            for (auto &k : posi_pos){
                if (k[0] < 0 || k [0] > max-1 || k[1] < 0 || k[1] > max-1){
                    k[2] = 1;
                }
            }
            
            for (int i = 0; i < 8; i++){
                if (posi_pos[i][2]){
                    continue;
                }
                if (grid[posi_pos[i][0]][posi_pos[i][1]] == start + 1){
                    flag = true;
                    start_x = posi_pos[i][0];
                    start_y = posi_pos[i][1];
                }
            }
            if (!flag){
                return false;
            }
            start++;
            
        }
        return true;
    }
};

int main(){
    vector<vector<int>> grid = {{0,3,6},{5,8,1},{2,7,4}};
    cout << Solution::checkValidGrid(grid);
}