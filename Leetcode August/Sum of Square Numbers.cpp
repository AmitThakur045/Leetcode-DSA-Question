class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c == 0 || c == 1 || c == 2)
            return true;
        long end = sqrt(c);
        long start = 0, num = 0;
        
        while(start <= end) {
            num = start*start + end*end;
            if(num == c)
                return true;
            else if(num > c)
                end--;
            else
                start++;
        }
        return false;
    }
};
