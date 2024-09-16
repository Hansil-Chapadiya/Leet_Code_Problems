#include <iostream>
#include <vector>
#include <algorithm> // For
#include <string>
using namespace std;

class MinimumTimeDifference_539
{
public:
    int findMinDifference(vector<string> &timePoints);
};

int timeToMinutes(const string &time)
{
    // Extract hours and minutes from the time string "HH:MM"
    int hours = stoi(time.substr(0, 2));   // First two characters are hours
    int minutes = stoi(time.substr(3, 2)); // Last two characters are minutes
    // Return total minutes from midnight
    return hours * 60 + minutes;
}

int MinimumTimeDifference_539::findMinDifference(vector<string> &timePoints)
{
    vector<int> minutes;

    // Convert all time points to minutes
    for (const string &time : timePoints)
    {
        minutes.push_back(timeToMinutes(time));
    }

    // Sort the times (in minutes)
    sort(minutes.begin(), minutes.end());

    // Initialize minimum difference to be a large number
    int minDiff = 24 * 60; // Maximum possible time difference (1440 minutes)

    // Compare adjacent time points
    for (int i = 1; i < minutes.size(); i++)
    {
        // Find the difference between consecutive times
        int diff = minutes[i] - minutes[i - 1];
        minDiff = min(minDiff, diff);
    }

    // Additionally, compare the first and last time points, considering the wrap-around (midnight)
    int wrapAroundDiff = (1440 - minutes.back()) + minutes.front(); // Time difference between the last and first times
    minDiff = min(minDiff, wrapAroundDiff);

    return minDiff;
}

int main()
{
    MinimumTimeDifference_539 obj;
    vector<string> timePoints = {"23:59", "00:00", "12:34"};
    cout << "Minimum Time Difference: " << obj.findMinDifference(timePoints) << " minutes" << endl;
    return 0;
}
static const int hansil = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
/*
when working with time is that the day "wraps around" after midnight. This means that we also need to consider the difference between the last time of the day (23:59 or 1439 minutes) and the first time of the day (00:00 or 0 minutes).

Wrap-around difference between 1439 (23:59) and 0 (00:00):
(1440 − 1439) + 0 = 1  minute
(1440−1439)+0=1 minute
5. Determine the Minimum Difference:
Now we compare all the calculated differences:

754 minutes (between 12:34 and 00:00)
685 minutes (between 23:59 and 12:34)
1 minute (wrap-around between 23:59 and 00:00)
The smallest difference is 1 minute, which is the wrap-around case between 23:59 and 00:00.
*/