class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        vector<vector<int>> mark = matrix;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (matrix[r][c] == 0) {
                    for (int col = 0; col < COLS; col++) {
                        mark[r][col] = 0;
                    }
                    for (int row = 0; row < ROWS; row++) {
                        mark[row][c] = 0;
                    }
                }
            }
        }

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                matrix[r][c] = mark[r][c];
            }
        }
    }
};
