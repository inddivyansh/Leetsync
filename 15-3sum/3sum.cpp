class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n =nums.size();
        vector<vector<int>> v1;

        sort(nums.begin(),nums.end());



        for(int i=0; i<n; i++){

            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }

            int left=i+1;
            int right=n-1;

            while(right>left){
                int sum=nums[i]+nums[left]+nums[right];

                if(sum==0){
                    v1.push_back({nums[i],nums[left],nums[right]});
                    while(right>left && nums[left]==nums[left+1]) left++;
                    while(right>left && nums[right]==nums[right-1]) right--;

                    left++;
                    right--;
                }
                else if(sum<0){
                    left++;
                }
                else{
                    right--;
                }
            }
        }

        return v1;
    }
};