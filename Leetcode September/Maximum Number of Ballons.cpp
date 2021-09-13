class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> mp(26, 0);
        for(auto i : text) {
            mp[i - 'a']++;
        }
        int tmp = min({mp[0], mp[1], mp[13], min(mp[11] / 2, mp[14] / 2)});
        return tmp;
    }
};
