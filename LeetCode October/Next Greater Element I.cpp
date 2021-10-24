class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;
        for(auto x : nums2) {
            while(st.size() && st.top() < x) {
                mp[st.top()] = x;
                st.pop();
            }
            st.push(x);
        }
        
        vector<int> res;
        for(auto i : nums1) {
            res.push_back(mp.count(i) ? mp[i] : -1);
        }
        return res;
    }
};
