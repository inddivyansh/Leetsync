class Solution {
public:
    int maxArea(vector<int>& height) {
        int n =height.size();
        int left=0;
        int right=n-1;
        int max_area=0;


        while(left<right){
            int curr_height=min(height[left],height[right]);
            int curr_area=(right-left)*curr_height;

            max_area=max(curr_area,max_area);

            if(height[left]<=height[right]){
                left++;
            }
            else{
                right--;
            }
        }

        return max_area;
    }
};