class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        else if(n == 1)
            return nums[0];
        else if(n == 2) 
            return max(nums[0], nums[1]);
        else {
            vector<int> dp(n, 0);
            dp[0] = nums[0];
            dp[1] = nums[1];
            dp[2] = nums[0] + nums[2];
            
            int maxi = max(dp[2], dp[1]);
            for(int i=3; i<n; i++) {
                dp[i] = max(dp[i-2], dp[i-3]) + nums[i];
                maxi = max(maxi, dp[i]);
            }
            return maxi;
        }
    }
};
