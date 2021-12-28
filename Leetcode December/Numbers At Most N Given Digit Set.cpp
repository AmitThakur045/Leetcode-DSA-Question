class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        int size = s.size(), dsize  = digits.size(), ans = 0;
        
        for(int i=1; i<size; i++) {
            ans += pow(dsize, i);
        }
        
        for(int i=0; i<size; i++) {
            bool hasSame = false;
            for(auto d : digits) {
                if(d[0] < s[i]) {
                    ans += pow(dsize, size - i - 1);
                } else if(d[0] == s[i]) {
                    hasSame = true;
                }
            }
            if(!hasSame)
                return ans;
        }
        return ans + 1;
    }
};
