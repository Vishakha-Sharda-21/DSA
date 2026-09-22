class Solution {
    struct Node {
        int p;
        int c[5];
    };

    int n, k, S;
    vector<Node> st;

    inline void pull(int x) {
        Node &L = st[x << 1];
        Node &R = st[x << 1 | 1];
        Node &A = st[x];

        A.p = L.p * R.p % k;

        for (int i = 0; i < k; ++i)
            A.c[i] = L.c[i];

        for (int i = 0; i < k; ++i)
            A.c[L.p * i % k] += R.c[i];
    }

    inline void update(int pos, int val) {
        int x = S + pos;
        val %= k;

        st[x].p = val;

        for (int i = 0; i < k; ++i)
            st[x].c[i] = 0;

        st[x].c[val] = 1;

        for (x >>= 1; x; x >>= 1)
            pull(x);
    }

public:
    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {
        this->k = k;
        n = nums.size();

        S = 1;
        while (S < n) S <<= 1;

        st.resize(S << 1);

        for (int i = 0; i < n; ++i) {
            int r = nums[i] % k;

            st[S + i].p = r;
            st[S + i].c[r] = 1;
        }

        for (int i = S - 1; i; --i)
            pull(i);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            update(q[0], q[1]);

            int l = S + q[2];
            int r = S + n;

            int lp = 1;
            int lc[5] = {};

            int rp = 1;
            int rc[5] = {};

            Node right[20];
            int rn = 0;

            while (l < r) {
                if (l & 1) {
                    Node &A = st[l++];

                    int old = lp;

                    for (int i = 0; i < k; ++i)
                        lc[(old * i) % k] += A.c[i];

                    lp = old * A.p % k;
                }

                if (r & 1) {
                    --r;
                    right[rn++] = st[r];
                }

                l >>= 1;
                r >>= 1;
            }

            // Right nodes must be merged in reverse order.
            for (int z = rn - 1; z >= 0; --z) {
                Node &A = right[z];

                int old = rp;

                for (int i = 0; i < k; ++i)
                    rc[(old * i) % k] += A.c[i];

                rp = old * A.p % k;
            }

            // left + right
            int x = q[3];

            for (int i = 0; i < k; ++i)
                if ((lp * i) % k == x)
                    lc[x] += rc[i];

            ans.push_back(lc[x]);
        }

        return ans;
    }
};
