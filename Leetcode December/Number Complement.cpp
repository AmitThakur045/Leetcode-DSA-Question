class Solution {
public:
    int findComplement(int num) {
        int n = num, i = 0;
        while(num) {
            n = n ^ (1 << i);
            i++;
            num = num / 2;
        }
        return n;
    }
};
