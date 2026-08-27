class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());

        if (!st.count(endWord)) return 0;

        queue<string> q;
        q.push(beginWord);

        int steps = 1;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                string word = q.front();
                q.pop();

                if (word == endWord) return steps;

                for (int i = 0; i < word.size(); i++) {
                    char original = word[i];

                    for (char c = 'a'; c <= 'z'; c++) {
                        word[i] = c;

                        if (st.count(word)) {
                            st.erase(word);
                            q.push(word);
                        }
                    }

                    word[i] = original;
                }
            }

            steps++;
        }

        return 0;
    }
};
