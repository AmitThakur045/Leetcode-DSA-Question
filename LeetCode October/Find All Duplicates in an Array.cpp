class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return {};
        
        vector<int> res;
        for(int i=0; i<nums.size(); i++) {
            if(nums[abs(nums[i]) - 1] < 0) {
                res.push_back(abs(nums[i]));
            }
            nums[abs(nums[i]) - 1] = - nums[abs(nums[i]) - 1];
        }
        return res;
    }
};
