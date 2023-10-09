/*
给定长度为 2n 的整数数组 nums ，
你的任务是将这些数分成 n 对, 例如 (a1, b1), (a2, b2), ..., (an, bn) ，
使得从 1 到 n 的 min(ai, bi) 总和最大。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arrayPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int sum = 0;
    for (int i = 0; i < nums.size(); i += 2){
        sum += nums[i];
    }
    return sum;
}

int main(int argc, char **argv){
    vector<int> arr = {1,9,2,3,4,5,1,2,3,4,5,1};
    cout << arrayPairSum(arr) << endl;
    exit(0);
}