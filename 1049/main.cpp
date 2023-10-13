/*
有一堆石头，用整数数组 stones 表示。其中 stones[i] 表示第 i 块石头的重量。

每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：

如果 x == y，那么两块石头都会被完全粉碎；
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
最后，最多只会剩下一块 石头。返回此石头 最小的可能重量 。如果没有石头剩下，就返回 0。
*/

#include <iostream>
#include <vector>

using namespace std;

int lastStoneWeightII(vector<int>& stones) {
    // create a dp vector, divide the array to two part, in order to make the minus of them get the minimal
    int size = stones.size();
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum += stones[i];
    }
    vector<int> dp;
    for (int i = 0; i <= sum / 2; i++){
        dp.emplace_back(0);
    }
    for (int i = 0; i < size; i++){
        for (int j = dp.size()-1; j >= stones[i]; j--){
            dp[j] = max(dp[j], dp[j-stones[i]] + stones[i]);
        }
    }
    
    return sum - 2 * dp[dp.size()-1];
}

int main(int argc, char **argv){
    vector<int> stones = {1,2};
    cout << lastStoneWeightII(stones) << endl;
    exit(0);
}