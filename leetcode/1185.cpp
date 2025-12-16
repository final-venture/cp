class Solution {
private:
    bool isLeap(int year) {
        return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    }
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<int> month2days {
            31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
        };
        int daysBetween = 0;
        // process prior years
        for (int i = 1971; i < year; ++i) {
            if (isLeap(i)) {
                daysBetween += 366;
            }
            else {
                daysBetween += 365;
            }
        }
        // process current year, prior months
        for (int i = 1; i < month; ++i) {
            if (i == 2 && isLeap(year)) {
                daysBetween += 29;
            }
            else {
                daysBetween += month2days[i - 1];   
            }
        }
        // process current year, current month
        daysBetween += (day - 1);
        daysBetween %= 7;
        vector<string> dayOfWeek {
            "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};
        return dayOfWeek[daysBetween];
    }
};
