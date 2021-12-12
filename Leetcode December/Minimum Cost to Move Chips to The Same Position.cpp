class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd = 0, even = 0;
        for(auto &i : position) {
            odd += (i & 1);
            even += !(i & 1);
        }
        return min(even, odd);
    }
};
