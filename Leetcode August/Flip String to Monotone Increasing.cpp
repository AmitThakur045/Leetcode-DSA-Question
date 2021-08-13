class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ones = 0;
        int res = 0;
        
        for(auto ch : s) {
            if(ch == '1')
                ones++;
            else 
                res++;
            res = min(res, ones);
        }
        return res;
    }
};
