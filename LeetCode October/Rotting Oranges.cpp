class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.size() == 0)
            return 0;
        int m = grid.size(), n = grid[0].size(), day = 0, tot = 0, cnt = 0;
        queue<pair<int, int>> q;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] != 0) tot++;
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        while(!q.empty()) {
            int size = q.size();
            cnt += size;
            while(size--) {
                auto it = q.front();
                q.pop();
                int x = it.first, y = it.second;
                for(int i=0; i<4; i++) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if(nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] != 1) {
                        continue;
                    }
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
            if(!q.empty())
                day++;
        }
        
        // cout<<tot<<" "<<cnt<<endl;
        return tot == cnt ? day : -1;
    }
};
