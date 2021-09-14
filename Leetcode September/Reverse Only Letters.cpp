class Solution {
public:
    string reverseOnlyLetters(string s) {
        string str= "";
        int n = s.size();
        for(int i=n-1; i>=0; i--) {
            if(isalpha(s[i])) {
                str += s[i];
            }
        }
        
        for(int i=0,j=0; i<n; i++) {
            if(isalpha(s[i])) {
                s[i] = str[j];
                j++;
            }
        }
        return s;
    }
};
