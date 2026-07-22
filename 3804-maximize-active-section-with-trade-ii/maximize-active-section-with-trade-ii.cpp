class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();

        int total_ones = 0;
        for(char c : s){
            if(c == '1') total_ones++;
        }

        vector<int> t, l, r;

        for(int i = 0; i < n; ){
            int j = i;
            while(j < n && s[j] == s[i]) j++;

            t.push_back(s[i] - '0');
            l.push_back(i);
            r.push_back(j - 1);

            i = j;
        }

        int m = t.size();

        vector<int> seg(n);

        for(int i = 0; i < m; i++){
            for(int j = l[i]; j <= r[i]; j++){
                seg[j] = i;
            }
        }

        vector<int> val(m);

        for(int i = 1; i < m - 1; i++){
            if(t[i]){
                val[i] = (r[i - 1] - l[i - 1] + 1) + (r[i + 1] - l[i + 1] + 1);
            }
        }

        vector<int> lg(m + 1);

        for(int i = 2; i <= m; i++){
            lg[i] = lg[i / 2] + 1;
        }

        int k = lg[m] + 1;

        vector<vector<int>> dp(k, vector<int>(m));

        for(int i = 0; i < m; i++){
            dp[0][i] = val[i];
        }

        for(int i = 1; i < k; i++){
            for(int j = 0; j + (1 << i) <= m; j++){
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + (1 << (i - 1))]);
            }
        }

        auto get = [&](int x, int y){
            if(x > y) return 0;

            int p = lg[y - x + 1];

            return max(dp[p][x], dp[p][y - (1 << p) + 1]);
        };

        auto check = [&](int id, int L, int R, int a, int b){

            if(id <= a || id >= b) return 0;
            if(!t[id]) return 0;

            int x = 0;
            if(id - 1 == a) x = max(0, r[id - 1] - L + 1);
            else x = r[id - 1] - l[id - 1] + 1;

            int y = 0;
            if(id + 1 == b) y = max(0, R - l[id + 1] + 1);
            else y = r[id + 1] - l[id + 1] + 1;

            return x + y;
        };

        vector<int> ans;

        for(auto &q : queries){

            int L = q[0];
            int R = q[1];

            int a = seg[L];
            int b = seg[R];

            if(b - a < 2){
                ans.push_back(total_ones);
                continue;
            }

            int mx = 0;

            mx = max(mx, check(a + 1, L, R, a, b));
            mx = max(mx, check(b - 1, L, R, a, b));

            if(a + 2 <= b - 2){
                mx = max(mx, get(a + 2, b - 2));
            }

            ans.push_back(total_ones + mx);
        }

        return ans;
    }
};