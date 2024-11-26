#include <iostream>
#include <vector>
#include <unordered_map>

// Class definition for the FindChampion problem
class FindChampionII_2924
{
private:
    // No private members in this example
public:
    // Function to find the champion (node with in-degree of 0)
    int findChampion(int n, std::vector<std::vector<int>> &edges)
    {
        // Create a map to store the in-degree of each node
        std::unordered_map<int, int> in_degrees;

        // Populate the in-degrees map based on the given edges
        for (auto i : edges)
        {
            in_degrees[i[1]]++; // Increment in-degree for the destination node of each edge
        }

        // Vector to store nodes with in-degree 0
        std::vector<int> champions;

        // Check all nodes from 0 to n-1
        for (int i = 0; i < n; i++)
        {
            // If a node is not found in the in-degrees map, it has in-degree 0
            if (in_degrees.find(i) == in_degrees.end())
            {
                champions.push_back(i); // Add the node to the champions list
            }
        }

        // If there is exactly one champion, return it; otherwise, return -1
        return champions.size() == 1 ? champions[0] : -1;
    }
};

int main()
{
    // Create an instance of the FindChampion_2924 class
    FindChampionII_2924 f1;

    // Example input: edges represented as a vector of pairs (from, to)
    // Uncomment the desired input and comment out the other for testing

    // Example 1: edges = {{0, 1}, {1, 2}}
    // std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}};

    // Example 2: edges = {{0, 2}, {1, 3}, {1, 2}}
    std::vector<std::vector<int>> edges = {{0, 2}, {1, 3}, {1, 2}};

    // Call the findChampion function with the number of nodes and edges
    std::cout << f1.findChampion(3, edges);

    // Return 0 to indicate successful execution
    return 0;
}
