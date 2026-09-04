class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // Initialize memoization table with -1
        vector<vector<int>> memo(text1.size(), vector<int>(text2.size(), -1));
        return dfs(text1, text2, 0, 0, memo);
    }

private:
    int dfs(const string& text1, const string& text2, int i, int j, vector<vector<int>>& memo) {
        // Base case: if either string is exhausted
        if (i == text1.size() || j == text2.size()) {
            return 0;
        }

        // Return the cached result if it has already been calculated
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        // If characters match, move both pointers forward
        if (text1[i] == text2[j]) {
            return memo[i][j] = 1 + dfs(text1, text2, i + 1, j + 1, memo);
        }

        // If characters don't match, take the maximum of both choices
        return memo[i][j] = max(dfs(text1, text2, i + 1, j, memo), dfs(text1, text2, i, j + 1, memo));
    }
};
