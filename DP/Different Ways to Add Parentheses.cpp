class Solution {
    unordered_map<long long, vector<int>> memo;

    vector<int> solve(const string &s, int l, int r) {
        long long key = ((long long)l << 32) | r;
        if (memo.count(key)) return memo[key];

        vector<int> ans;
        bool isNum = true;

        for (int i = l; i <= r; i++) {
            char c = s[i];
            if (c == '+' || c == '-' || c == '*') {
                isNum = false;

                auto left = solve(s, l, i - 1);
                auto right = solve(s, i + 1, r);

                ans.reserve(ans.size() + left.size() * right.size());

                for (int a : left)
                    for (int b : right)
                        ans.push_back(c == '+' ? a + b :
                                      c == '-' ? a - b :
                                                 a * b);
            }
        }

        if (isNum) {
            int num = 0;
            for (int i = l; i <= r; i++)
                num = num * 10 + (s[i] - '0');
            ans.push_back(num);
        }

        return memo[key] = move(ans);
    }

public:
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression, 0, expression.size() - 1);
    }
};
