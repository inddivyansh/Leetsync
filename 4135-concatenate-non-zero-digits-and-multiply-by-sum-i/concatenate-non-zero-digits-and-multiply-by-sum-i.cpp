class Solution {
public:
    long long sumAndMultiply(int n) {
        string num = to_string(n);
        long long x = 0;
        int sum = 0;

        for (char c : num) {
            if (c != '0') {
                int digit = c - '0';
                x = x * 10 + digit;
                sum += digit;
            }
        }

        return x * sum;
    }
};