class MinStack {
public:
    stack<pair<int, int>> st;

    MinStack() {
    }

    void push(int val) {
        int currentMin = val;

        if (!st.empty()) {
            currentMin = min(val, st.top().second);
        }

        st.push({val, currentMin});
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};
