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
    int tmp_n = n % 10;
    int tmp_s = 0;
    int out = 0;
    num.emplace_back(tmp_n);
    int sub = 0;
    int n_cp = n;
    int cnt = 0;
    while (n_cp > 0){
        cnt++;
        n_cp /= 10;
        int tmp = n_cp % 10;
        num.emplace_back(tmp);
        if (tmp_n < tmp){
            tmp_n = tmp - 1;
            tmp_s = tmp - 1;
            sub = cnt;
            continue;
        }
        tmp_n = tmp;

    }
    num.pop_back(); // 0

    for (auto m = 0; m < num.size(); m++){
        cout << num[m] << '\t';
    }
    cout << endl;

    for (int i = 0; i < sub; i++){
        num[i] = 9;
    }

    if (sub){
        num[sub] = tmp_s;
    }

    for (auto m = 0; m < num.size(); m++){
        cout << num[m] << '\t';
    }
    cout << endl;

    for (int j = cnt-1; j >= 0; j--){
        out += num[j];
        if (!j){
            break;
        }
        out *= 10;
    }
    return out;
}


int main(int argc, char **argv){
    int n = 1234;

    cout << n << endl << monotoneIncreasingDigits(n) << endl;
    exit(0);
}