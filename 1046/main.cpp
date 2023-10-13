/*
有一堆石头，每块石头的重量都是正整数。

每一回合，从中选出两块 最重的 石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：

如果 x == y，那么两块石头都会被完全粉碎；
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
最后，最多只会剩下一块石头。返回此石头的重量。如果没有石头剩下，就返回 0。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_stones(vector<int>& stones){
    for (int i = 0; i < stones.size(); i++){
        cout << stones[i] << '\t';
    }        
    cout << endl;
}

int lastStoneWeight(vector<int>& stones) {
    sort(stones.begin(), stones.end());
    while(1){
        int size = stones.size();

        if (size == 1){
            return stones[0];
        }
        if (size == 0){
            break;
        }

        // fetch 2 stones
        int s_1 = stones[size-1], s_2 = stones[size-2];
        int ret = abs(s_1 - s_2);
        stones.pop_back();
        stones.pop_back();
        if (ret){
            // insert
            /*
            stones.emplace_back(ret);
            sort(stones.begin(), stones.end());
            */
            stones.emplace_back(s_1);
            stones.insert(stones.begin(),0);


            for (int j = 0; j < size-1; j++){
                if (stones[j] <= ret && ret <= stones[j+1]){
                    stones.insert(stones.begin()+j+1, ret);
                    break;
                }
            }
            stones.pop_back();
            stones.erase(stones.begin());

        }

    }
    return 0;
}

int main(){
    vector<int> stones = {3,7,9};
    cout << lastStoneWeight(stones) << endl;
    exit(0);
}