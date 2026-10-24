class Solution {
public:
    int days(string date) {
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));

        int monthDays[] = {31, 28, 31, 30, 31, 30,
                           31, 31, 30, 31, 30, 31};

        for (int i = 0; i < month - 1; i++) {
            day += monthDays[i];
        }

        return day;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        int start = max(days(arriveAlice), days(arriveBob));
        int end = min(days(leaveAlice), days(leaveBob));

        return max(0, end - start + 1);
    }
};
