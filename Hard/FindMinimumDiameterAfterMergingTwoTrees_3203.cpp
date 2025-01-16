/* #include <iostream>
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
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

class Solution
{
public:
    // Function to calculate the diameter of an undirected tree using a modified Kahn's algorithm
    static int calculateTreeDiameter(std::vector<std::vector<int>> &edges)
    {
        int numNodes = edges.size() + 1; // Total nodes in the tree
        std::vector<int> degree(numNodes, 0);
        std::vector<std::vector<int>> adjacencyList(numNodes);

        // Build adjacency list and degree count
        for (auto &edge : edges)
        {
            int nodeA = edge[0], nodeB = edge[1];
            adjacencyList[nodeA].push_back(nodeB);
            adjacencyList[nodeB].push_back(nodeA);
            degree[nodeA]++;
            degree[nodeB]++;
        }

        // Initialize a queue to process leaf nodes
        std::queue<int> leafQueue;
        for (int i = 0; i < numNodes; i++)
        {
            if (degree[i] == 1)
            { // Leaf node
                leafQueue.push(i);
            }
        }

        int levels = 0;                // Tracks levels of inward traversal
        int remainingNodes = numNodes; // Nodes left in the tree

        // Process the tree inward toward the center
        while (remainingNodes > 2)
        { // At most two nodes can remain
            int leafCount = leafQueue.size();
            remainingNodes -= leafCount; // Reduce remaining nodes by the number of leaves

            for (int i = 0; i < leafCount; i++)
            {
                int currentLeaf = leafQueue.front();
                leafQueue.pop();
                for (int neighbor : adjacencyList[currentLeaf])
                {
                    // Remove edge to make the neighbor a leaf
                    if (--degree[neighbor] == 1)
                    {
                        leafQueue.push(neighbor);
                    }
                }
            }
            levels++; // Increment level after processing current batch of leaves
        }

        // Diameter calculation based on remaining nodes
        return (remainingNodes == 2) ? 2 * levels + 1 : 2 * levels;
    }

    // Function to calculate the minimum possible diameter after merging two trees
    static int calculateMinimumDiameterAfterMerge(std::vector<std::vector<int>> &tree1Edges,
                                                  std::vector<std::vector<int>> &tree2Edges)
    {
        int tree1Diameter = calculateTreeDiameter(tree1Edges);
        int tree2Diameter = calculateTreeDiameter(tree2Edges);

        // Calculate minimum diameter after merging the two trees
        return std::max({tree1Diameter,
                         tree2Diameter,
                         (tree1Diameter + 1) / 2 + (tree2Diameter + 1) / 2 + 1});
    }
};

int main()
{
    Solution solution;
    std::vector<std::vector<int>> tree1Edges = {{0, 1}, {0, 2}, {0, 3}};
    std::vector<std::vector<int>> tree2Edges = {{0, 1}};

    int result = solution.calculateMinimumDiameterAfterMerge(tree1Edges, tree2Edges);
    std::cout << "Minimum Diameter After Merge: " << result << std::endl;
    return 0;
}
