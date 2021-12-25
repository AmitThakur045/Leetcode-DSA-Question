class Solution {
    vector<vector<int>> dp;
    bool solve(int sum, int pos, vector<int>& nums, int n) {
        if(sum == 0)
            return true;
        else if(pos >= n || sum < 0)
            return false;
        
        if(dp[pos][sum] != -1)
            return dp[pos][sum];
        
        return dp[pos][sum] = solve(sum - nums[pos], pos+1, nums, n) || 
                                solve(sum, pos+1, nums, n);
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(auto &i : nums) {
            sum += i;
        }
        
        if(sum & 1)
            return false;
        dp.clear();
        dp.resize(n+1, vector<int>(sum/2 + 1, -1));
        return solve(sum / 2, 0, nums, n);
    }
};
