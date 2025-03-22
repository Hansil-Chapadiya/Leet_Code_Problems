#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &component)
{
    visited[node] = true;
    component.push_back(node);
    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, adj, visited, component);
        }
    }
}

int countCompleteComponents(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(n);
    vector<bool> visited(n, false);

    // Build adjacency list
    for (auto &edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]); // Undirected graph
    }

    int completeComponents = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            dfs(i, adj, visited, component);

            // Check if this component is complete
            int size = component.size();
            int edgeCount = 0;
            for (int node : component)
            {
                edgeCount += adj[node].size();
            }
            edgeCount /= 2; // Each edge is counted twice

            // A complete graph with `size` nodes must have `size * (size - 1) / 2` edges
            if (edgeCount == (size * (size - 1)) / 2)
            {
                completeComponents++;
            }
        }
    }

    return completeComponents;
}

int main()
{
    int n = 6;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {3, 4}, {4, 5}, {5, 3}, {3, 5}};

    cout << "Number of complete connected components: " << countCompleteComponents(n, edges) << endl;
    return 0;
}
