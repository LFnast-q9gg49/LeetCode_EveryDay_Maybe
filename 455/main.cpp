/*
对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；
并且每块饼干 j，都有一个尺寸 s[j] 。如果 s[j] >= g[i]，
我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。
你的目标是尽可能满足越多数量的孩子，并输出这个最大数值
*/

// very easy greedy

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int findContentChildren(vector<int>& g, vector<int>& s) {
    // sort the g and s
    // kids increase and cookie increase
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    // two pointer 
    int p_k = 0, p_c = 0;
    int cnt = 0;
    while (1){
        if ((p_k >= g.size()) || (p_c >= s.size())){
            break;
        }
        if (g[p_k] <= s[p_c]){
            cnt++;
            p_k++;
            p_c++;
            continue;
        }
        p_c++;
    }
    return cnt;
}


int main(int argc, char **argv){
    vector<int> g = {1,2,3};
    vector<int> s = {1,1};
    cout << findContentChildren(g,s) << endl;
    exit(0);
}