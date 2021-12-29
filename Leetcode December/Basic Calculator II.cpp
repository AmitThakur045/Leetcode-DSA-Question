class Solution {
public:
    int calculate(string s) {
        long long i=0, ans = 0, num = 0;
        long long interm = 0;
        char oper = '+';
        int n = s.size();
        while(i < n) {
            if(isdigit(s[i])) {
                num = 0;
                while(i < n && isdigit(s[i])) {
                    num = num * 10 + s[i] - '0';
                    i++;
                }
                if(oper == '+' || oper == '-') {
                    ans += interm;
                    interm = num * (oper == '-' ? -1 : 1);
                } else if(oper == '*') {
                    interm *= num;
                } else if(oper == '/') {
                    interm /= num;
                }
                continue;
            }
            else if(s[i] != ' ') 
                oper = s[i];
            i++;
        }
        
        ans += interm;
        return ans;
    }
};
