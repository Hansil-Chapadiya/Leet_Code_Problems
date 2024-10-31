#include <vector>
#include <algorithm>
#include <deque>
#include <climits>
#include <cmath>
#include <iostream>

class MinimumTotalDistanceTraveled_2463
{
private:
    /* data */
public:
    long long minimumTotalDistance(std::vector<int> &robot, std::vector<std::vector<int>> &factory)
    {
        // Sort robots and factories by position for optimal assignment
        std::sort(robot.begin(), robot.end());
        std::sort(factory.begin(), factory.end());

        int numRobots = robot.size();
        int numFactories = factory.size();

        // DP table to store minimum distances for subproblems
        // dp[i][j] represents the minimum total distance for robots[i:] with factories[j:]
        std::vector<std::vector<long long>> dp(numRobots + 1, std::vector<long long>(numFactories + 1, LLONG_MAX));

        // Base case: if no factories are available, we cannot assign remaining robots, set to "infinity"
        for (int i = 0; i <= numRobots; ++i)
        {
            dp[i][numFactories] = LLONG_MAX;
        }
        dp[numRobots][numFactories] = 0; // If no robots and no factories left, distance is zero

        // Process each factory from the last to the first
        for (int j = numFactories - 1; j >= 0; --j)
        {
            // Track cumulative distance of assigning consecutive robots to the current factory
            long long cumulativeDistance = 0;

            // Deque to maintain minimum distance states for sliding window approach
            std::deque<std::pair<int, long long>> minDeque;
            minDeque.push_back({numRobots, 0}); // Initialize with base case

            // Process each robot from the last to the first
            for (int i = numRobots - 1; i >= 0; --i)
            {
                // Add the distance from current robot to the current factory position
                cumulativeDistance += std::abs(robot[i] - factory[j][0]);

                // Maintain only relevant entries in the deque for the current factory's capacity
                while (!minDeque.empty() && minDeque.front().first > i + factory[j][1])
                {
                    minDeque.pop_front(); // Remove robots beyond the factory's capacity
                }

                // Ensure deque remains monotonic by removing dominated states
                while (!minDeque.empty() && minDeque.back().second >= dp[i][j + 1] - cumulativeDistance)
                {
                    minDeque.pop_back();
                }

                // Add the current state to deque
                minDeque.push_back({i, dp[i][j + 1] - cumulativeDistance});

                // Calculate minimum distance for dp[i][j] using the deque's front element
                dp[i][j] = minDeque.front().second + cumulativeDistance;
            }
        }

        // Return the minimum total distance starting from first robot and first factory
        return dp[0][0];
    }
};
int main()
{
    MinimumTotalDistanceTraveled_2463 m1;
    std::vector<int> robot = {0, 4, 6};
    std::vector<std::vector<int>> factory = {{2, 2}, {6, 2}};
    std::cout<<m1.minimumTotalDistance(robot,factory);

}