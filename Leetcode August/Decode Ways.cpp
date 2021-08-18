class Solution {
public:
    int solve(int i, string& s, int& n, vector<int>& dp) {
        if(dp[i] > -1)
            return dp[i];
        if(s[i] == '0')
            return dp[i] = 0;
        
        int res = solve(i+1, s, n, dp);
        if(i < n-1 && ((s[i] == '1') || (s[i] == '2' && s[i+1] < '7'))) 
            res += solve(i+2, s, n, dp);
        return dp[i] = res;
    }
    
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, -1);
        dp[n] = 1;
        return n == 0 ? 0 : solve(0, s, n, dp);
    }
};
