class Solution {
public:

    static constexpr int MOD=1e9+7;

    int zigZagArrays(int n, int l, int r) {
        int m = r-l+1;

        if(n==1) { return m;}

        vector<long long> up(m,0),down(m,0);

        for(int i=0; i<m; i++){
            up[i]=i;
            down[i]=m-i-1;
        }

        if(n==2){
            long long ans=0;
            for(int i=0; i<m; i++){
                ans=(ans+up[i]+down[i])%MOD;
            }
            return int(ans);
        }

        vector<long long> newup(m),newdown(m);

        for(int len=3; len<=n; len++){

            long long curr=0;

            for(int i=0; i<m; i++){
                newup[i]=curr;
                curr=(curr+down[i])%MOD;
            }

            curr=0; 

            for(int i=m-1; i>=0; i--){
                newdown[i]=curr;
                curr=(curr+up[i])%MOD;
            }

            swap(up,newup);
            swap(down,newdown);
        }

        long long ans=0; 
        for(int i=0; i<m; i++){
            ans=(ans+up[i]+down[i])%MOD;
        }

        return int(ans);
    }
};