class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int, int>> cars(n);

        for (int i = 0; i < n; ++i)
            cars[i] = {position[i], speed[i]};

        sort(cars.begin(), cars.end(), greater<pair<int, int>>());

        int fleets = 0;
        double slowestTime = 0.0;

        for (auto &[pos, spd] : cars) {
            double time = (double)(target - pos) / spd;

            if (time > slowestTime) {
                ++fleets;
                slowestTime = time;
            }
        }

        return fleets;
    }
};
