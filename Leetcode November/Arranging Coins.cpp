class Solution {
public:
    int arrangeCoins(int n) {
        int cnt = 0;
        
        int i=1;
        while(n > 0) {
            n = n - i;
            i++;
            if(n >= 0)
                cnt++;
        }
        
        return cnt;
    }
};
