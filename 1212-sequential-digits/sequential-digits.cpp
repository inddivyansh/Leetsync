class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ret;

        for(int i = 1; i <= 9; i++) {
            int num = i;

            for(int j = i + 1; j <= 9; j++) {
                num = num * 10 + j;

                if(num >= low && num <= high)
                    ret.push_back(num);

                if(num > high)
                    break;
            }
        }

        sort(ret.begin(), ret.end());

        return ret;
    }
};