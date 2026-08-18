class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = -1;
        unordered_map<int, int> mpv;

        for (int i = 0; i <= n - k; i++) {
            unordered_set<int> st;

            for (int j = i; j < i + k; j++) {
                st.insert(nums[j]);
            }

            for (int x : st) {
                mpv[x]++;
            }
        }

        for (auto& pair : mpv) {
            // cout << pair.first<< " " << pair. second << endl;
            if (pair.second == 1) {
                // cout << pair.first << " " ;
                ans = max(ans, pair.first);
            }
        }

        return ans;
    }
};