class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> indegree(m, vector<int>(n, 0));

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // Build indegree:
        // edge -> smaller cell to larger cell
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr >= 0 && nr < m &&
                        nc >= 0 && nc < n &&
                        matrix[nr][nc] > matrix[r][c]) {
                        indegree[nr][nc]++;
                    }
                }
            }
        }

        queue<pair<int, int>> q;

        // Cells with no smaller neighbor are starting points
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (indegree[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        int length = 0;

        while (!q.empty()) {
            int size = q.size();
            length++;

            while (size--) {
                auto [r, c] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr >= 0 && nr < m &&
                        nc >= 0 && nc < n &&
                        matrix[nr][nc] > matrix[r][c]) {

                        indegree[nr][nc]--;

                        if (indegree[nr][nc] == 0) {
                            q.push({nr, nc});
                        }
                    }
                }
            }
        }

        return length;
    }
};
