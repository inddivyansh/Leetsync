class Solution {
public:
    string intToRoman(int num) {
        map<int, string, greater<int>> mp = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, 
            {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        int n = num;
        string ans = "";

        for (auto& value : mp) {
            while (n >= value.first) {
                ans += value.second;
                n -= value.first;
            }
        }

        return ans;
    }
};
