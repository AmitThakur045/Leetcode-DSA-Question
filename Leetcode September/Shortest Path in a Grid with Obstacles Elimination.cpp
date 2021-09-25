class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n, -1));
        queue<vector<int>> q;
        q.push({0,0,0,k});      // queue(x, y, path size, no of obstacles left)
        
        while(!q.empty()) {
            auto tmp = q.front();
            int x = tmp[0], y = tmp[1];
            q.pop();
            // cout<<x<<" "<<y<<endl;
            
            if(x < 0 || x >= m || y < 0 || y >= n)
                continue;
            if(x == m-1 && y == n-1)
                return tmp[2];
            if(grid[x][y] == 1) {
                if(tmp[3] > 0)
                    tmp[3]--;
                else
                    continue;                
            }
            if(vis[x][y] != -1 && vis[x][y] >= tmp[3]) {
                continue;
            }                
            vis[x][y] = tmp[3];
            
            q.push({x+1, y, tmp[2]+1, tmp[3]});
            q.push({x, y+1, tmp[2]+1, tmp[3]});
            q.push({x-1, y, tmp[2]+1, tmp[3]});
            q.push({x, y-1, tmp[2]+1, tmp[3]});
        }
        return -1;
    }
};
