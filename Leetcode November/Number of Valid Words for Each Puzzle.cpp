class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<char, vector<int>> mp;
        for(int i=0; i<26; i++) {
            vector<int> res;
            mp[(char)(i+'a')] = res;
        }
        
        for(auto word : words) {
            int mask = 0;
            for(auto ch : word) {
                int bit = ch - 'a';
                mask = mask | (1 << bit);
            }
            
            unordered_set<char> st;
            for(auto ch : word) {
                if(st.find(ch) != st.end())
                    continue;
                st.insert(ch);
                mp[ch].push_back(mask);
            }
        }
        
        vector<int> ans;
        for(auto puzzle : puzzles) {
            int pmask = 0;
            for(auto ch : puzzle) {
                int bit = ch - 'a';
                pmask = pmask | (1 << bit);
            }
            
            int fch = puzzle[0], cnt = 0;
            vector<int> tmp = mp[fch];
            for(int i=0; i<tmp.size(); i++) {
                if((tmp[i] & pmask) == tmp[i]) {
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
