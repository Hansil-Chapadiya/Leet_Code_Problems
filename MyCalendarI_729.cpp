#include <map>
#include <iostream>

class MyCalendar
{
private:
    // Map to store the bookings, with `start` time as the key and `end` time as the value
    std::map<int, int> calendar;

public:
    MyCalendar() {}

    bool book(int start, int end)
    {
        // Find the first event that ends after the `start` time (lower_bound)
        auto nextEvent = calendar.lower_bound(start);

        // Check if there is an overlapping event before the `start` time
        if (nextEvent != calendar.begin())
        {
            auto prevEvent = prev(nextEvent);
            if (prevEvent->second > start)
            { // Previous event ends after the new start
                return false;
            }
        }

        // Check if the `nextEvent` starts before the `end` time
        if (nextEvent != calendar.end() && nextEvent->first < end)
        {
            return false;
        }

        // No overlaps, insert the new event into the calendar
        calendar[start] = end;
        return true;
    }
};

// Driver code to test the MyCalendar class
int main()
{
    MyCalendar myCalendar;

    // Test cases
    std::cout << (myCalendar.book(10, 20) ? "True" : "False") << std::endl; // Should return True
    std::cout << (myCalendar.book(15, 25) ? "True" : "False") << std::endl; // Should return False (overlaps with [10, 20))
    std::cout << (myCalendar.book(20, 30) ? "True" : "False") << std::endl; // Should return True (no overlap)

    return 0;
}
static const int hansil = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();