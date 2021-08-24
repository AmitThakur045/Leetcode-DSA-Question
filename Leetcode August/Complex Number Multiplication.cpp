class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int i=0, n = num1.size();
        for(; i<n; i++) {
            if(num1[i] == '+')
                break;
        }
        int real_1 = stoi(num1.substr(0, i));
        int complex_1 = stoi(num1.substr(i+1, n-1));
        
        int j=0, m = num2.size();
        for(; j<m; j++) {
            if(num2[j] == '+')
                break;
        }
        int real_2 = stoi(num2.substr(0, j));
        int complex_2 = stoi(num2.substr(j+1, m-1));
        
        int start = (real_1 * real_2);
        int middle = ((real_1 * complex_2) + (real_2 * complex_1));
        start -= (complex_1 * complex_2);
        
        // cout<<real_1<<" "<<complex_1<<endl;
        // cout<<real_2<<" "<<complex_2<<endl;
        
        string s1 = to_string(start);
        string s2 = to_string(middle);
        
        string res = "";
        res += s1 + "+" + s2 +"i";
        return res;        
       
    }
};
