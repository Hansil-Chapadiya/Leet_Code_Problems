#include <iostream>
#include <vector>
#include <numeric>
#include <functional>
#include <algorithm>

class MaximumNumberOfKDivisibleComponents_2872
{
public:
    int maxKDivisibleComponents(int n, std::vector<std::vector<int>> &edges, std::vector<int> &values, int k)
    {
        long long total_sum = std::accumulate(values.begin(), values.end(), 0LL); // Use long long
        std::vector<long long> subtreesum(n, 0);

        // Build adjacency list from edges
        std::vector<std::vector<int>> graph(n);
        for (const auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int max_components = 0;

        // DFS to calculate valid splits
        std::function<int(int, int)> dfs = [&](int node, int parent)
        {
            subtreesum[node] = values[node]; // Start with the current node's value
            int local_components = 0;        // Number of components found in this subtree

            for (int child : graph[node])
            {
                if (child != parent)
                {
                    local_components += dfs(child, node);  // Recur for child nodes
                    subtreesum[node] += subtreesum[child]; // Update subtree sum
                }
            }

            // If the current subtree sum is divisible by k, it forms a valid component
            if (subtreesum[node] % k == 0)
            {
                local_components++;
                subtreesum[node] = 0; // Reset the subtree sum after forming a valid component
            }

            return local_components;
        };

        max_components = dfs(0, -1);
        return max_components;
    }
};

int main()
{
    std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}};
    std::vector<int> values = {3, 0, 6, 1, 5, 2, 1};
    MaximumNumberOfKDivisibleComponents_2872 m1;
    std::cout << m1.maxKDivisibleComponents(7, edges, values, 3) << std::endl;
    return 0;
}
