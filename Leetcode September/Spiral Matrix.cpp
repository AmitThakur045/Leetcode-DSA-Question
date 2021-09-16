class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // l = left
        // r = right
        // t = top
        // d = down
        int l = 0, r = matrix[0].size()-1;
        int t = 0, d = matrix.size()-1;
        int dir = 0, i;
        vector<int> res;
        
        while(t <= d && l <= r) {
            if(dir == 0) {
                for(i=l; i<=r; i++) {
                    res.push_back(matrix[t][i]);
                }
                t++;
            } 
            else if(dir == 1) {
                for(i=t; i<=d; i++) {
                    res.push_back(matrix[i][r]);
                }
                r--;
            }
            else if(dir == 2) {
                for(i=r; i>=l; i--) {
                    res.push_back(matrix[d][i]);
                }
                d--;
            }
            else if(dir == 3) {
                for(i=d; i>=t; i--) {
                    res.push_back(matrix[i][l]);
                }
                l++;
            }
            dir = (dir+1) % 4;
        }
        return res;
    }
};
