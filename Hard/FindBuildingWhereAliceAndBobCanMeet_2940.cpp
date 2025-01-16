// #include <iostream>
// #include <vector>
// #include <algorithm>

// class FindBuildingWhereAliceAndBobCanMeet_2940
// {
// public:
//     std::vector<int> leftmostBuildingQueries(std::vector<int> &heights, std::vector<std::vector<int>> &queries)
//     {
//         std::vector<int> answer;

//         for (const auto &q : queries)
//         {
//             int q1 = q[0]; // Alice's starting position
//             int q2 = q[1]; // Bob's starting position
//             if (q1 > q2)
//             {
//                 std::swap(q1, q2); // Ensure q1 <= q2
//             }

//             // If Alice and Bob start in the same building, that's the meeting point
//             if (q1 == q2)
//             {
//                 answer.push_back(q1);
//                 continue;
//             }

//             int meetingBuilding = -1; // Initialize meeting building as -1 (not found)
//             for (int k = q2 + 1; k < heights.size(); ++k)
//             {
//                 // Check if both Alice and Bob can reach building `k`
//                 if (heights[q1] < heights[k] && heights[q2] < heights[k])
//                 {
//                     meetingBuilding = k;
//                     break; // Found the leftmost meeting building
//                 }
//             }

//             answer.push_back(meetingBuilding);
//         }

//         return answer;
//     }
// };

// int main()
// {
//     FindBuildingWhereAliceAndBobCanMeet_2940 f1;

//     std::vector<int> heights = {5, 3, 8, 2, 6, 1, 4, 6};
//     std::vector<std::vector<int>> queries = {{0, 7}, {3, 5}, {5, 2}, {3, 0}, {1, 6}};

//     std::vector<int> answer = f1.leftmostBuildingQueries(heights, queries);

//     for (auto i : answer)
//     {
//         std::cout << i << " ";
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

class MeetingBuildingFinder
{
public:
    std::vector<int> findMeetingBuildings(std::vector<int> &heights, std::vector<std::vector<int>> &queries)
    {
        int numBuildings = heights.size();
        int numQueries = queries.size();
        std::vector<int> results(numQueries, -1);
        std::vector<std::vector<std::pair<int, int>>> deferredQueries(numBuildings);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> minHeap;

        // Process queries and categorize them into direct results or deferred queries
        for (int queryIndex = 0; queryIndex < numQueries; ++queryIndex)
        {
            int aliceStart = queries[queryIndex][0];
            int bobStart = queries[queryIndex][1];

            // Ensure aliceStart <= bobStart for consistency
            if (aliceStart > bobStart)
                std::swap(aliceStart, bobStart);

            // If Alice can directly reach Bob or both start at the same building
            if (aliceStart == bobStart || heights[aliceStart] < heights[bobStart])
            {
                results[queryIndex] = bobStart; // Direct result
            }
            else
            {
                // Defer the query to be resolved later
                deferredQueries[bobStart].emplace_back(heights[aliceStart], queryIndex);
            }
        }

        // Process each building and resolve deferred queries
        for (int currentBuilding = 0; currentBuilding < numBuildings; ++currentBuilding)
        {
            // Add all deferred queries for the current building to the heap
            for (const auto &deferred : deferredQueries[currentBuilding])
            {
                minHeap.push(deferred);
            }

            // Resolve deferred queries where the current building is valid
            while (!minHeap.empty() && minHeap.top().first < heights[currentBuilding])
            {
                results[minHeap.top().second] = currentBuilding;
                minHeap.pop();
            }
        }

        return results;
    }
};

int main()
{
    MeetingBuildingFinder solution;

    std::vector<int> heights = {5, 3, 8, 2, 6, 1, 4, 6};
    std::vector<std::vector<int>> queries = {{0, 7}, {3, 5}, {5, 2}, {3, 0}, {1, 6}};

    std::vector<int> results = solution.findMeetingBuildings(heights, queries);

    for (int result : results)
    {
        std::cout << result << " ";
    }
    std::cout << std::endl;

    return 0;
}
