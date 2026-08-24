class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int m = h.size(), n = h[0].size();
        vector<vector<int>> p(m, vector<int>(n)), a = p;
        
        auto dfs = [&](auto&& self, int r, int c, auto& vis) -> void {
            if (vis[r][c]) return;
            vis[r][c] = 1;

            int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};
            for (int k = 0; k < 4; k++) {
                int x = r + dr[k], y = c + dc[k];
                if (x >= 0 && x < m && y >= 0 && y < n &&
                    !vis[x][y] && h[x][y] >= h[r][c])
                    self(self, x, y, vis);
            }
        };

        for (int i = 0; i < m; i++)
            dfs(dfs, i, 0, p), dfs(dfs, i, n-1, a);

        for (int j = 0; j < n; j++)
            dfs(dfs, 0, j, p), dfs(dfs, m-1, j, a);

        vector<vector<int>> ans;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (p[i][j] && a[i][j])
                    ans.push_back({i,j});

        return ans;
    }
};
