class Solution {
public:
    int calculate(string s) {
        int total = 0, sum = 0, sign = 1;
        stack<int> st({1});
        
        for(char ch : s) {
            if(isdigit(ch)) {
                sum = sum*10 + (ch - '0');
            }
            else {
                total += sum * sign * st.top();
                sum = 0;
                if(ch == '+')   sign = 1;
                if(ch == '-')   sign = -1;
                if(ch == ')')   st.pop();
                if(ch == '(') {
                    st.push(st.top() * sign);
                    sign = 1;
                }
            }
        }
        total += sum * sign * st.top();
        return total;
    }
};
