class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b) {
            return a.start < b.start;
        });

        priority_queue<int, vector<int>, greater<int>> rooms;

        for (auto& meeting : intervals) {
            if (!rooms.empty() && rooms.top() <= meeting.start)
                rooms.pop();

            rooms.push(meeting.end);
        }

        return rooms.size();
    }
};
