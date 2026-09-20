class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> st;

        for (auto &s : tokens) {
            if (s.size() > 1 || isdigit(s[0])) {
                st.push_back(stoi(s));
                continue;
            }

            int b = st.back(); st.pop_back();
            int a = st.back(); st.pop_back();

            switch (s[0]) {
                case '+': st.push_back(a + b); break;
                case '-': st.push_back(a - b); break;
                case '*': st.push_back(a * b); break;
                case '/': st.push_back(a / b); break;
            }
        }

        return st.back();
    }
};
