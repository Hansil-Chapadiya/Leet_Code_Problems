#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <unordered_map>
#include <set>

class ShortestDistanceAfterAdditionRoadQueriesI_3243
{
public:
    std::vector<int> shortestDistanceAfterQueries(int n, std::vector<std::vector<int>> &queries)
    {
        // Adjacency list to represent the graph
        std::vector<std::vector<std::pair<int, int>>> graph(n);

        // Initialize the graph with roads from i to i+1 with weight 1
        for (int i = 0; i < n - 1; i++)
        {
            graph[i].push_back({i + 1, 1});
        }

        std::vector<int> result;

        // Helper function for Dijkstra's algorithm
        auto dijkstra = [&](int source, int target)
        {
            std::vector<int> dist(n, std::numeric_limits<int>::max());
            dist[source] = 0;
            std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
            pq.push({0, source}); // {distance, node}

            while (!pq.empty())
            {
                auto [current_dist, current_node] = pq.top();
                pq.pop();

                if (current_dist > dist[current_node])
                    continue;

                for (auto &[neighbor, weight] : graph[current_node])
                {
                    int new_dist = current_dist + weight;
                    if (new_dist < dist[neighbor])
                    {
                        dist[neighbor] = new_dist;
                        pq.push({new_dist, neighbor});
                    }
                }
            }

            return dist[target];
        };

        // Process each query
        for (auto &query : queries)
        {
            int u = query[0];
            int v = query[1];

            // Add the new road to the graph
            graph[u].push_back({v, 1});

            // Compute the shortest path from 0 to n-1
            int shortest_path_length = dijkstra(0, n - 1);
            result.push_back(shortest_path_length);
        }

        return result;
    }
};

int main()
{
    // Example queries
    std::vector<std::vector<int>> queries = {{2, 4}, {0, 2}, {0, 4}};
    ShortestDistanceAfterAdditionRoadQueriesI_3243 s1;

    // Compute shortest paths after each query
    std::vector<int> result = s1.shortestDistanceAfterQueries(5, queries);

    // Output the results
    for (int length : result)
    {
        std::cout << length << " ";
    }
    std::cout << std::endl;

    return 0;
}
