#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

class NumberOfSmallestUnoccupiedChair_1942
{
public:
    int smallestChair(std::vector<std::vector<int>> &times, int targetFriend)
    {
        int n = times.size();

        // Step 1: Create a list of events
        std::vector<std::pair<int, int>> events;
        for (int i = 0; i < n; ++i)
        {
            events.push_back({times[i][0], i});  // Arrival event
            events.push_back({times[i][1], -i}); // Departure event (negative index to indicate departure)
        }

        // Step 2: Sort events by time (if times are equal, arrival comes before departure)
        std::sort(events.begin(), events.end());

        // Step 3: Min-heap for available chairs (smallest chair will be at the top)
        std::priority_queue<int, std::vector<int>, std::greater<int>> availableChairs;
        for (int i = 0; i < n; ++i)
        {
            availableChairs.push(i); // Initially, all chairs are available
        }

        // Step 4: Min-heap to track when chairs become available (sorted by departure time)
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> busyChairs;

        // Step 5: Process events in sorted order
        for (const auto &event : events)
        {
            int time = event.first;
            int friendIdx = event.second;

            // Handle departures first (if any chair becomes available at the current time)
            while (!busyChairs.empty() && busyChairs.top().first <= time)
            {
                availableChairs.push(busyChairs.top().second); // Free the chair
                busyChairs.pop();                              // Remove from busy list
            }

            if (friendIdx >= 0)
            { // Arrival event
                // Assign the smallest available chair to the friend
                int assignedChair = availableChairs.top();
                availableChairs.pop();

                // If this is the target friend, return the chair number
                if (friendIdx == targetFriend)
                {
                    return assignedChair;
                }

                // Mark the chair as busy until the friend's departure time
                busyChairs.push({times[friendIdx][1], assignedChair});
            }
        }

        return -1; // This should never be reached if the input is well-formed
    }
};

int main()
{
    NumberOfSmallestUnoccupiedChair_1942 n1;
    // std::vector<std::vector<int>> times = {{1, 4}, {2, 3}, {4, 6}};
    std::vector<std::vector<int>> times = {{4, 5}, {12, 13}, {5, 6}, {1, 2}, {8, 9}, {9, 10}, {6, 7}, {3, 4}, {7, 8}, {13, 14}, {15, 16}, {14, 15}, {10, 11}, {11, 12}, {2, 3}, {16, 17}};
    int targetFriend = 15;
    std::cout << "Smallest Chair for Target Friend: " << n1.smallestChair(times, targetFriend) << std::endl;
    return 0;
}
