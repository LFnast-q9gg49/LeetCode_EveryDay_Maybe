/*
当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。

给定一个整数 n ，返回 小于或等于 n 的最大数字，且数字呈 单调递增 。
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int monotoneIncreasingDigits(int n) {
    // divide the num to an array, if the num is inceased then return it
    // if not, find the first decreased point and return it like xx_9999999...
    vector<int> num;
    int cnt = 0;
    int cnt_2 = 0;
    int out = 0;
    int n_copy = n;
    bool flag = true;
    while (n_copy > 0){
        num.emplace_back(n_copy % 10);
        n_copy /= 10;
        cnt++;
    }
    vector<int> num_cp = num;
    sort(num.rbegin(), num.rend());
    for (int i = 0; i < cnt; i++){
        if (num[i] != num_cp[i]){
            flag = false;
        }
    }
    if (flag){
        return n;
    }

    for (int j = cnt-1; j > 0; j--){
        if (num_cp[j] > num_cp[j-1]){
            cnt_2 = j;
            break;
        }
    }
    cout << cnt << cnt_2 <<endl;
    for (int k = cnt-1; k >= 0; k--){

        out *= 10;
        if (k == cnt_2){
            out += num_cp[k]-1;
            continue;
        }
        if (k < cnt_2){
            out += 9;
            continue;
        }
        out += num_cp[k];
        
    }
    return out;
}


int main(int argc, char **argv){
    int n = 1333332;

    cout << n << endl << monotoneIncreasingDigits(n) << endl;
    exit(0);
}