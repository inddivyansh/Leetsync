class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int ans = 0;
        int mx = 0;

        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][1] > mx) {
                ans++;
                mx = intervals[i][1];
            }
        }

        return ans;
    }
};