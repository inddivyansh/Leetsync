class Solution {
public:
    void update(vector<int>& bit, int i) {
        while (i < bit.size()) {
            bit[i]++;
            i += i & -i;
        }
    }

    int query(vector<int>& bit, int i) {
        int sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= i & -i;
        }
        return sum;
    }

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        bool found = false;
        for (int x : nums) {
            if (x == target) {
                found = true;
                break;
            }
        }

        if (!found) return 0;

        vector<int> bit(2 * n + 5, 0); //for fenwick tree - learn and revise

        long long ans = 0;
        int pref = n + 1;   

        update(bit, pref);

        for (int x : nums) {
            if (x == target)
                pref++;
            else
                pref--;

            ans += query(bit, pref - 1);
            update(bit, pref);
        }

        return ans;
    }
};