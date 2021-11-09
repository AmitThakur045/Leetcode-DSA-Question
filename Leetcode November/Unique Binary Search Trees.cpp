class Solution {
public:
    int catalan(int n) {
        int cat[n + 1];
        cat[0] = cat[1] = 1;
        
        for(int i=2; i<=n; i++) {
            cat[i] = 0;
            for(int j=0; j<i; j++) {
                cat[i] += cat[j] * cat[i - j - 1];              
            }
        }
        return cat[n];
    }
    
    int numTrees(int n) {
        return catalan(n);   
    }
};
