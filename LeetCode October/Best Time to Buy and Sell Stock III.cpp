class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int left[n], right[n];
        
        left[0] = 0;
        int mini = prices[0];
        for(int i=1; i<n; i++) {
            left[i] = max(prices[i] - mini, left[i-1]);
            mini = min(mini, prices[i]);
        }
        
        right[n-1] = 0;
        int maxi = prices[n-1];
        for(int i=n-2; i>=0; i--) {
            right[i] = max(right[i+1], maxi - prices[i]);
            maxi = max(maxi, prices[i]);
        }
        
        int res = 0;
        for(int i=0; i<n; i++) {
            res = max(res, left[i]+right[i]);
        }
        
        return res;
    }
};
