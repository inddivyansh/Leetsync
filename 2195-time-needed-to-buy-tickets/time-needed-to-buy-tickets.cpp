class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int, int>> q; 

        for (int i = 0; i < tickets.size(); i++) {
            q.push({tickets[i], i});
        }

        int time = 0;

        while (!q.empty()) {
            auto [count, i] = q.front();
            q.pop();

            count--;
            time++;

            if (count == 0) {
                if (i == k) return time;
            } else {
                q.push({count, i});
            }
        }

        return time;
    }
};