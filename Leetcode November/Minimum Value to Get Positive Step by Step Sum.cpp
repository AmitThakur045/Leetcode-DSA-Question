class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0, mini = 0;
        for(auto i : nums) {
            sum += i;
            mini = min(mini, sum);
        }
        return 1 - mini;
    }
};
