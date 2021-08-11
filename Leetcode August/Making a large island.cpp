class Solution {
public:
    vector<int> offset = {0, 1, 0, -1, 0};      // used to move the pointer in four direction in matrix
  
    void calc_Area(vector<vector<int>>& grid, int i, int j, int &currArea, int &island_id, int &n) {
        currArea++;
        grid[i][j] = island_id;
        
        for(int k=0; k<4; k++) {
            int x = i + offset[k];
            int y = j + offset[k+1];
            if(x < 0 || x >= n || y < 0 || y >= n || grid[x][y] != 1)
                continue;
            calc_Area(grid, x, y, currArea, island_id, n);
        }
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int currArea = 0, maxArea = 0, island_id = 2;
        unordered_map<int, int> area;
        
        // map the grid with different island id and calculate the max Area available
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    calc_Area(grid, i, j, currArea, island_id, n);
                    maxArea = max(maxArea, currArea);
                    area[island_id] = currArea;     // mark island id with its area
                    island_id++;
                    currArea = 0;
                }
            }
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 0) {
                    unordered_set<int> st;
                    for(int k=0; k<4; k++) {
                        int x = i + offset[k];
                        int y = j + offset[k+1];
                        if(x < 0 || x >= n || y < 0 || y >= n || grid[x][y] == 0)
                            continue;
                        st.insert({grid[x][y]});
                    }
                    
                    int res = 1;
                    for(auto it : st) 
                        res += area[it];
                    
                    maxArea = max(maxArea, res);
                }
            }
        }
        return maxArea;
        
    }
};
