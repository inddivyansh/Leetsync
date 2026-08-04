class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> res;
        int j = nums[0];

        for (int i : nums) {
            while (j < i) {
                res.push_back(j);
                j++;
            }

            if (j == i)
                j++;
        }

        // while (j <= nums.size()) {
        //     res.push_back(j);
        //     j++;
        // }

        return res;
    }
};