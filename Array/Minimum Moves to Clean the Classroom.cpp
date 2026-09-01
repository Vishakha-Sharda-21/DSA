class Solution {
public:
    int minMoves(vector<string>& g, int E) {
        int m = g.size(), n = g[0].size();
        int sr, sc, k = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++) {
                if (g[r][c] == 'S') sr = r, sc = c;
                else if (g[r][c] == 'L') id[r][c] = k++;
            }

        int full = (1 << k) - 1;

        // best[r][c][mask] = maximum energy seen
        vector<vector<vector<signed char>>> best(
            m, vector<vector<signed char>>(n, vector<signed char>(1 << k, -1))
        );

        queue<array<int, 4>> q;
        q.push({sr, sc, 0, E});
        best[sr][sc][0] = E;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        int moves = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c, mask, e] = q.front();
                q.pop();

                if (mask == full)
                    return moves;

                if (e == 0)
                    continue;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n ||
                        g[nr][nc] == 'X')
                        continue;

                    int ne = e - 1;
                    int nm = mask;

                    if (g[nr][nc] == 'L')
                        nm |= 1 << id[nr][nc];

                    if (g[nr][nc] == 'R')
                        ne = E;

                    // Same position + same litter mask:
                    // only keep states with more energy.
                    if (ne <= best[nr][nc][nm])
                        continue;

                    best[nr][nc][nm] = ne;
                    q.push({nr, nc, nm, ne});
                }
            }

            moves++;
        }

        return -1;
    }
};
