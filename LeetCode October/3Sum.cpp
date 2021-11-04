class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++) {
            int target = -nums[i];
            int start = i+1, end = n-1;
            while(start < end) {
                int sum = nums[start] + nums[end];
                if(sum < target) {
                    start++;
                } else if(sum > target) {
                    end--;
                } else {
                    vector<int> triplet = {nums[i], nums[start], nums[end]};
                    res.push_back(triplet);
                    
                    // start++;
                    // end--;
                    while(start < end && nums[start] == triplet[1]) {
                        start++;
                    }
                    while(start < end && nums[end] == triplet[2]) {
                        end--;
                    }
                }
            }
            while(i+1 < n && nums[i] == nums[i+1]) {
                i++;
            }
        }
        return res;
    }
};
