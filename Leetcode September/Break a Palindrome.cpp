class Solution {
public:
    string breakPalindrome(string str) {
        int n = str.size();
        if(str.size() == 1)
            return "";
        
        bool flag = false;
        for(int i=0; i<n; i++) {
            if(str[i] != 'a') {
                flag = true;
                if(i == n/2) {
                    str[n-1] = 'b';
                } else {
                    str[i] = 'a';
                }
                break;
            }
        }
        if(flag == true)
            return str;
        
        str[n-1] = 'b';
        return str;
    }
};
