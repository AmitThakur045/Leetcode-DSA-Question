class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        for(auto email : emails) {
            string res = "";
            for(auto s : email) {
                if(s == '+' || s == '@')
                    break;
                if(s == '.')
                    continue;
                res += s;
            }
            res += email.substr(email.find('@'));
            st.insert(res);
        }
        return st.size();
    }
};
