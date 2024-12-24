#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

class FindMinimumDiameterAfterMergingTwoTrees_3203
{
private:
    // Helper function: Perform BFS to calculate the farthest distance from a node
    std::pair<int, int> bfsFarthestNode(int start, const std::vector<std::vector<int>> &adj)
    {
        int n = adj.size();
        std::vector<int> dist(n, -1);
        std::queue<int> q;
        q.push(start);
        dist[start] = 0;

        int farthestNode = start;
        int maxDist = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node])
            {
                if (dist[neighbor] == -1)
                {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);

                    if (dist[neighbor] > maxDist)
                    {
                        maxDist = dist[neighbor];
                        farthestNode = neighbor;
                    }
                }
            }
        }
        return {farthestNode, maxDist};
    }

    // Helper function: Calculate the diameter of a tree
    int calculateDiameter(const std::vector<std::vector<int>> &adj)
    {
        if (adj.empty())
            return 0;
        auto [farthestNode, _] = bfsFarthestNode(0, adj);
        auto [_, diameter] = bfsFarthestNode(farthestNode, adj);
        return diameter;
    }

    // Helper function: Get the farthest distance from each node
    std::vector<int> findFarthestDistances(const std::vector<std::vector<int>> &adj)
    {
        int n = adj.size();
        std::vector<int> distances(n, 0);
        for (int i = 0; i < n; i++)
        {
            auto [_, maxDist] = bfsFarthestNode(i, adj);
            distances[i] = maxDist;
        }
        return distances;
    }

public:
    int minimumDiameterAfterMerge(std::vector<std::vector<int>> &edges1, std::vector<std::vector<int>> &edges2)
    {
        // Convert edge lists to adjacency lists
        int n1 = edges1.size() + 1;
        int n2 = edges2.size() + 1;

        std::vector<std::vector<int>> adj1(n1), adj2(n2);
        for (auto &edge : edges1)
        {
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }
        for (auto &edge : edges2)
        {
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }

        // Step 1: Calculate diameters of both trees
        int diameter1 = calculateDiameter(adj1);
        int diameter2 = calculateDiameter(adj2);

        // Step 2: Find farthest distances from each node
        std::vector<int> farthestDistances1 = findFarthestDistances(adj1);
        std::vector<int> farthestDistances2 = findFarthestDistances(adj2);

        // Step 3: Combine trees and minimize diameter
        int minDiameter = INT_MAX;
        for (int d1 : farthestDistances1)
        {
            for (int d2 : farthestDistances2)
            {
                int newDiameter = std::max({diameter1, diameter2, d1 + 1 + d2});
                minDiameter = std::min(minDiameter, newDiameter);
            }
        }

        return minDiameter;
    }
};

int main()
{
    FindMinimumDiameterAfterMergingTwoTrees_3203 f1;
    std::vector<std::vector<int>> edges1 = {{0, 1}, {1, 2}, {1, 3}};
    std::vector<std::vector<int>> edges2 = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
    int result = f1.minimumDiameterAfterMerge(edges1, edges2);
    std::cout << "Minimum Diameter After Merge: " << result << std::endl;
    return 0;
}
