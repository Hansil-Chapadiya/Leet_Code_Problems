#include <iostream>
#include <vector>
#include <algorithm>

class DivideIntervalIntoMinimumNumberOfGroup_2406 {
public:
    int minGroups(std::vector<std::vector<int>> &intervals) {
        std::vector<std::pair<int, int>> pair_start_end;

        // Step 1: Convert intervals into start and end pair_start_end
        for (const auto &interval : intervals) {
            pair_start_end.push_back({interval[0], 1});  // start of an interval
            pair_start_end.push_back({interval[1] + 1, -1});  // end of an interval
        }

        // Step 2: Sort pair_start_end. If times are the same, end pair_start_end come before start pair_start_end
        std::sort(pair_start_end.begin(), pair_start_end.end());

        int currentGroups = 0;
        int maxGroups = 0;

        // Step 3: Process pair_start_end
        for (const auto &event : pair_start_end) {
            currentGroups += event.second;
            maxGroups = std::max(maxGroups, currentGroups);
        }

        return maxGroups;
    }
};

int main() {
    DivideIntervalIntoMinimumNumberOfGroup_2406 d1;
    std::vector<std::vector<int>> intervals = {{5, 10}, {6, 8}, {1, 5}, {2, 3}, {1, 10}};
    std::cout << d1.minGroups(intervals) << std::endl;
    return 0;
}
static const int hansil = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

/*
copy from solution
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> start_times, end_times;

        // Extract start and end times
        for (const auto& interval : intervals) {
            start_times.push_back(interval[0]);
            end_times.push_back(interval[1]);
        }

        // Sort start and end times
        sort(start_times.begin(), start_times.end());
        sort(end_times.begin(), end_times.end());

        int end_ptr = 0, group_count = 0;

        // Traverse through the start times
        for (int start : start_times) {
            if (start > end_times[end_ptr]) {
                end_ptr++;
            } else {
                group_count++;
            }
        }

        return group_count;
    }
};
static const int hansil = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

*/