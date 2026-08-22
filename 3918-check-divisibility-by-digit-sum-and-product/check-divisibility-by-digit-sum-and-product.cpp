class Solution {
public:
    bool checkDivisibility(int n) {
        int num=n;
        int sum=0;
        int product=1;
        while (num > 0) {
        int digit = num % 10;
        sum+=digit;
        product*=digit;
        num /= 10;
        }
        int check=sum+product;
        if(n%check==0){
            return true;
        }
        else{
            return false;
        }
    }
};