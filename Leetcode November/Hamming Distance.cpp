class Solution {
public:
    int hammingDistance(int x, int y) {
        int num = x ^ y;
        int cnt = 0;
        while(num) {
            if(num & 1) {
                cnt++;
            }
            num = num >> 1;
        }
        return cnt;
    }
};
