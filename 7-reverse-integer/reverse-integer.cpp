#include <queue>
#include <climits>

class Solution { 
public: 
    int reverse(long long x) { 
        long long num = x; 
        queue<long long> q; 
        int digits = 0; 
        
        if (num == 0) {
            return 0;
        }

        if (num > 0) { 
            while (num > 0) { 
                digits = num % 10; 
                q.push(digits); 
                num = num / 10; 
            } 
        } else { 
            while (num < 0) { 
                digits = num % 10; 
                q.push(digits); 
                num = num / 10; 
            } 
        } 
        
        long long result = 0; 
        while (!q.empty()) { 
            result = result * 10 + q.front(); 
            q.pop(); 
            
            if (result > INT_MAX || result < INT_MIN) {
                return 0;
            }
        } 
        
        return result; 
    } 
};
