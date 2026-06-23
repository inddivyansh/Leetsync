class Solution {
public:
    string smallestSubsequence(string s) {
        int count[26] = {0};
        bool seen[26] = {false};

        for (char c : s) {
            count[c - 'a']++;
        }

        stack<char> st;

        for (char c : s) {
            int i = c - 'a';
            count[i]--;

            if (seen[i]) continue;

            while (!st.empty() && st.top() > c && count[st.top() - 'a'] > 0) {
                seen[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(c);
            seen[i] = true;
        }

        string ans;

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};