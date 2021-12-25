class Solution {
public:
    int maxPower(string s) {
        int cnt = 1, max_cnt = 1, n = s.size();
        for(int i=0; i<n-1; i++) {
            if(s[i] == s[i+1]) {
                cnt++;
                max_cnt = max(max_cnt, cnt);
            } else {
                cnt = 1;
            }
        }
        return max_cnt;
    }
};
