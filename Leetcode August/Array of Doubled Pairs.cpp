class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto it : arr) {
            mp[it]++;    
        }
        
        vector<int> res;
        for(auto it : mp) {
            res.push_back(it.first);
        }
        
        sort(res.begin(), res.end(), [](int i, int j) {return abs(i) < abs(j);});
        
        for(int i : res) {
            if(mp[i] > mp[2 * i])
                return false;
            mp[2 * i] -= mp[i];
        }
        return true;
    }
};
