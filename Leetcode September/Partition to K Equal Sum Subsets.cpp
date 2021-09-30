class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(auto i : nums)
            sum += i;
        
        if(sum % k != 0 || k > nums.size())
            return false;
        
        int subsetSum = sum / k;
        vector<bool> visited(nums.size(), false);
        return check(nums, visited, subsetSum, 0, k, 0);
    }
    
    bool check(vector<int>& nums, vector<bool>& visited, int& subsetSum, int start, int k, int currSum) {
        if(k == 0)  return true;
        if(currSum > subsetSum) return false;
        if(currSum == subsetSum) {
            return check(nums, visited, subsetSum, 0, k-1, 0);
        }
        
        for(int i=start; i<nums.size(); i++) {
            if(visited[i])  continue;
            visited[i] = true;
            if(check(nums, visited, subsetSum, i+1, k, currSum + nums[i])) return true;
            visited[i] = false;
        }
        return false;
    }
};
