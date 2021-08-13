class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        string res = "";
        bool flag = 0;
        
        int i = n1-1, j = n2-1, carry = 0;
        while(i >= 0 && j >= 0) {
            int tmp1 = num1[i] - '0';
            int tmp2 = num2[j] - '0';
            
            int tmp = tmp1 + tmp2 + carry;
            if(tmp >= 10) {
                flag = 1;
            }
            else {
                flag = 0;
            }
            carry = tmp / 10;
            tmp = tmp % 10;
            
            res += to_string(tmp);
            i--;
            j--;
        }
        while(i >= 0) {
            int tmp1 = num1[i] - '0';
            int tmp = tmp1 + carry;
            if(tmp >= 10) {
                flag = 1;
            }
            else {
                flag = 0;
            }
            carry = tmp / 10;
            tmp = tmp % 10;
            
            res += to_string(tmp);
            i--;
        }
        while(j >= 0) {
            int tmp2 = num2[j] - '0';
            int tmp = tmp2 + carry;
            if(tmp >= 10) {
                flag = 1;
            }
            else {
                flag = 0;
            }
            carry = tmp / 10;
            tmp = tmp % 10;
            
            res += to_string(tmp);
            j--;
        }
        
        if(flag == 1)
            res += to_string(carry);
        
        reverse(res.begin(), res.end());
        return res;
    }
};
