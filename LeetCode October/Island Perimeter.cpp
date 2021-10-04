class Solution {
public:
    bool check(vector<vector<int>>& grid, int i, int j, int r, int c) {
        // cout<<i<<" "<<j<<endl;
        if(i < 0 || j < 0 || i >= r || j >= c || grid[i][j] == 0)
            return false;
        else
            return true;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        
        int p_metre = 0;
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(grid[i][j] == 1) {
                    if(check(grid, i+1, j, r, c) == false) 
                        p_metre++;
                    if(check(grid, i, j+1, r, c) == false)
                        p_metre++;
                    if(check(grid, i-1, j, r, c) == false)
                        p_metre++;
                    if(check(grid, i, j-1, r, c) == false)
                        p_metre++;
                }
            }
        }
        return p_metre;
    }
};
