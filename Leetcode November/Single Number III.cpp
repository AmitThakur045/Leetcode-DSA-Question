class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long sum = nums[0];
        for(int i=1; i<nums.size(); i++)
            sum = sum ^ nums[i];
        
        // right most set bit
        long bit = (sum & ~(sum - 1));
        long num1 = 0, num2 = 0;
        for(auto it : nums) {
            if((bit & it) > 0) {
                num1 ^= it;
            } else {
                num2 ^= it;
            }
        }
        vector<int> res;
        res.push_back(num1);
        res.push_back(num2);
        return res;
    }
};
