class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int n = s.size();
        for(int i=0; i<n; i++) {
            if(s[i] == ' ') continue;
            string tmp = "";
            int j = i;
            while(j < n && s[j] != ' ') {
                tmp += s[j];
                j++;
            }
            st.push(tmp);
            i = j;
        }
        string res = "";
        while(!st.empty()) {
            res += st.top() + " ";
            // cout<<res<<endl;
            st.pop();
        }
        return res.substr(0, res.size()-1);
    }
};
