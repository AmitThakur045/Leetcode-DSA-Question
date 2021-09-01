class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size(), res = 0;
        vector<bool> visited(n);
        for(auto it : nums) {
            int ans = 0;
            while(!visited[it]) {
                visited[it] = true;
                ans++;
                it = nums[it]; 
            }
            res = max(res, ans);
        }
        return res;
    }
};
