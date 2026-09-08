class WordDictionary {
    struct Node {
        Node* child[26];
        bool end;

        Node() : end(false) {
            for (int i = 0; i < 26; ++i)
                child[i] = nullptr;
        }
    };

    Node* root;

    bool dfs(Node* node, const string& word, int pos) {
        if (pos == word.size())
            return node->end;

        char c = word[pos];

        // Normal character
        if (c != '.') {
            Node* next = node->child[c - 'a'];

            if (!next)
                return false;

            return dfs(next, word, pos + 1);
        }

        // Wildcard '.'
        for (int i = 0; i < 26; ++i) {
            Node* next = node->child[i];

            if (next && dfs(next, word, pos + 1))
                return true;
        }

        return false;
    }

public:
    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node* cur = root;

        for (char c : word) {
            int idx = c - 'a';

            if (!cur->child[idx])
                cur->child[idx] = new Node();

            cur = cur->child[idx];
        }

        cur->end = true;
    }

    bool search(string word) {
        return dfs(root, word, 0);
    }
};
