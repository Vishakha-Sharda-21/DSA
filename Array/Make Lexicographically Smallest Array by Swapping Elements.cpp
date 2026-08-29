class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int,int>> a(n);

        for (int i = 0; i < n; i++)
            a[i] = {nums[i], i};

        sort(a.begin(), a.end());

        for (int l = 0; l < n; ) {
            int r = l;
            while (r + 1 < n && a[r + 1].first - a[r].first <= limit)
                r++;

            vector<int> idx;
            for (int i = l; i <= r; i++)
                idx.push_back(a[i].second);

            sort(idx.begin(), idx.end());

            for (int i = l; i <= r; i++)
                nums[idx[i - l]] = a[i].first;

            l = r + 1;
        }

        return nums;
    }
};
