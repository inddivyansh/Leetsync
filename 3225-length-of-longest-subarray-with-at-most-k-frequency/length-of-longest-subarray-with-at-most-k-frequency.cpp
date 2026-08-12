class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int lt = 0;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;

            while (mp[nums[i]] > k) {
                mp[nums[lt]]--;
                lt++;
            }

            ans = max(ans, i - lt + 1);
        }

        return ans;
    }
};
