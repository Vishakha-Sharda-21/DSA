class Solution {
public:
    int dfs(int i, vector<vector<int>>& cnt, vector<int>& wordScore,
            vector<int>& letters, int n) {

        if (i == n)
            return 0;

        // Skip the word
        int ans = dfs(i + 1, cnt, wordScore, letters, n);

        // Try taking the word
        bool possible = true;

        for (int j = 0; j < 26; j++) {
            if (cnt[i][j] > letters[j]) {
                possible = false;
                break;
            }
        }

        if (possible) {
            for (int j = 0; j < 26; j++)
                letters[j] -= cnt[i][j];

            ans = max(ans,
                      wordScore[i] +
                      dfs(i + 1, cnt, wordScore, letters, n));

            for (int j = 0; j < 26; j++)
                letters[j] += cnt[i][j];
        }

        return ans;
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters,
                      vector<int>& score) {

        int n = words.size();

        // Available letters
        vector<int> lettersCount(26, 0);

        for (char c : letters)
            lettersCount[c - 'a']++;

        // Precompute each word
        vector<vector<int>> cnt(n, vector<int>(26));
        vector<int> wordScore(n, 0);

        for (int i = 0; i < n; i++) {
            for (char c : words[i]) {
                int x = c - 'a';

                cnt[i][x]++;
                wordScore[i] += score[x];
            }
        }

        return dfs(0, cnt, wordScore, lettersCount, n);
    }
};
