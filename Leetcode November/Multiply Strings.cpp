class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size(), m = num2.size();
        vector<int> res(n+m, 0);
        
        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + res[i+j+1];
                res[i+j+1] = sum % 10;
                res[i+j] += sum / 10;
            }
        }
        
        bool flag = false;
        string s = "";
        for(int i=0; i<(n+m); i++) {
            // cout<<res[i]<<" ";
            if(res[i] == 0 && flag == false) {
                continue;
            } else {
                flag = true;
                s += to_string(res[i]);
            }
        }
        return s.size() == 0 ? "0" : s;
    }
};
