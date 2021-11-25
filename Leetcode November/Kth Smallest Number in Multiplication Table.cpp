class Solution {
public:
    int solve(int mid, int m, int n) {
        int count = 0;
        for(int i=1; i<=m; i++) {
            int temp = min(mid / i, n);
            count += temp;
        }
        return count;
    }
    
    int findKthNumber(int m, int n, int k) {
        int low = 1, high = m*n;
        
        while(low < high) {
            int mid = low + (high - low) / 2;
            int capacity = solve(mid, m, n);
            
            if(capacity >= k)   high = mid;
            else    low = mid + 1;
        }
        return high;
    }
    
};
