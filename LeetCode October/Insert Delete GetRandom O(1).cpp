class RandomizedSet {
public:
    vector<int> st;
    unordered_map<int, int> mp;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end())
            return false;
        st.push_back(val);
        mp[val] = st.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end())
            return false;
        auto it = mp.find(val);
        st[it->second] = st.back();
        st.pop_back();
        mp[st[it->second]] = it->second;
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return st[rand() % st.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
