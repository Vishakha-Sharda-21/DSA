class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        // Put all stones into max heap
        for (int stone : stones) {
            pq.push(stone);
        }

        // Smash the two heaviest stones
        while (pq.size() > 1) {
            int x = pq.top();
            pq.pop();

            int y = pq.top();
            pq.pop();

            // If weights are different, push the remaining weight
            if (x != y) {
                pq.push(x - y);
            }
        }

        // Return remaining stone, or 0
        return pq.empty() ? 0 : pq.top();
    }
};
