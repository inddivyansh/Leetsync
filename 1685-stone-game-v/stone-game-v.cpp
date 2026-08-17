#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int sg(vector<vector<int>>& dp, vector<int>& a, int i, int j, int total) {
        if (i >= j) return 0;
        if (dp[i][j] != -1) return dp[i][j]; 
        
        int ans = 0;
        int stk = 0;
        
        for (int k = i; k < j; k++) {
            stk += a[k];
            int sak = total - stk;
            
            if (stk > sak) {
                ans = max(ans, sak + sg(dp, a, k + 1, j, sak));
            } else if (stk < sak) {
                ans = max(ans, stk + sg(dp, a, i, k, stk));
            } else {
                ans = max(ans, stk + max(sg(dp, a, k + 1, j, sak), sg(dp, a, i, k, stk)));
            }
        }
        return dp[i][j] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ts = accumulate(stoneValue.begin(), stoneValue.end(), 0);
        return sg(dp, stoneValue, 0, n - 1, ts);
    }
};
