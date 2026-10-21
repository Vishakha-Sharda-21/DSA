class Solution {
public:
    vector<int> parent, size;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);

        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (size[a] < size[b])
            swap(a, b);

        parent[b] = a;
        size[a] += size[b];
    }

    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return true;

        // If 1 exists, it cannot connect with anything.
        for (int x : nums) {
            if (x == 1)
                return false;
        }

        int mx = *max_element(nums.begin(), nums.end());

        // Smallest Prime Factor
        vector<int> spf(mx + 1);

        for (int i = 0; i <= mx; i++)
            spf[i] = i;

        for (int i = 2; i * i <= mx; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= mx; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }

        parent.resize(n);
        size.assign(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        // prime -> first index having this prime
        vector<int> first(mx + 1, -1);

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            while (x > 1) {
                int p = spf[x];

                if (first[p] == -1)
                    first[p] = i;
                else
                    unite(i, first[p]);

                // Remove all occurrences of p
                while (x % p == 0)
                    x /= p;
            }
        }

        int root = find(0);

        for (int i = 1; i < n; i++) {
            if (find(i) != root)
                return false;
        }

        return true;
    }
};
