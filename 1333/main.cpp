#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    
    static vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>> out = {};
        for (auto p = restaurants.begin(); p != restaurants.end(); p++){
            if (veganFriendly == 1){
                if ((*p)[2] == 1 && (*p)[3] <= maxPrice && (*p)[4] <= maxDistance){
                    out.push_back(*p);
                }
            }
            else{
                if ((*p)[3] <= maxPrice && (*p)[4] <= maxDistance){
                    out.push_back(*p);
                }
            }
        }

        // sorting
        sort(out.begin(), out.end(), [](vector<int> &v1, vector<int> &v2) -> bool {
            return v1[1] > v2[1] || (v1[1] == v2[1] && v1[0] > v2[0]);
        });
        vector<int> res;
        for (auto &v : out) {
            res.push_back(v[0]);
        }
        return res;
    }
};

int main(int argc, char **argv){
    vector<vector<int>> rest = {{1,4,1,40,10}, {2,8,0,50,5},{3,8,1,30,4},{4,10,0,10,3},{5,1,1,15,1}};
    int veganFriendly = 1, maxPrice = 50, maxDistance = 10;
    Solution::filterRestaurants(rest, veganFriendly, maxPrice, maxDistance);
}