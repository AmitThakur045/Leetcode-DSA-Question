class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n >= 1) {
            bool flag = n & (n-1);
            return !flag;
        } 
        return false;
    }
};
