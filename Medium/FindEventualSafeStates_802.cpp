/* #include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
class FindEventualSafeStates_802
{
private:
public:
    std::vector<int> eventualSafeNodes(std::vector<std::vector<int>> &graph)
    {
        std::stack<std::pair<int, std::vector<int>>> stk;
        for (int i = 0; i < graph.size(); i++)
        {
            stk.push({i, graph[i]});
        }

        std::vector<int> answer;
        while (!stk.empty())
        {
            auto [node, edges] = stk.top();
            std::cout << node << " = ";
            for (auto i : edges)
            {
                std::cout << i << " ";
            }
            std::cout << std::endl;
            stk.pop();
            // if (edges.size() == 0)
            // {
            //     answer.push_back(node);
            // }
        }

        // while (!stk.empty())
        // {
        //     auto [node, edges] = stk.top();
        //     for (auto node : answer)
        //     {
        //         if (std::find(edges.begin(), edges.end(), node) != edges.end())
        //         {
        //             answer.push_back(node);
        //         }
        //     }
        // }
        // return answer;
    }
};
int main()
{
    FindEventualSafeStates_802 f1;
    std::vector<std::vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    f1.eventualSafeNodes(graph);
    return 0;
} */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>
#include <algorithm>

class FindEventualSafeStates_802 {
public:
    std::vector<int> eventualSafeNodes(std::vector<std::vector<int>> &graph) {
        int n = graph.size();
        std::vector<int> outDegree(n, 0); // Tracks the out-degree of each node
        std::vector<std::vector<int>> reverseGraph(n); // Reverse graph for easier traversal

        // Build the reverse graph and calculate out-degree
        for (int node = 0; node < n; ++node) {
            for (int neighbor : graph[node]) {
                reverseGraph[neighbor].push_back(node);
            }
            outDegree[node] = graph[node].size();
        }

        std::stack<int> stk;
        // Nodes with 0 out-degree are safe
        for (int i = 0; i < n; ++i) {
            if (outDegree[i] == 0) {
                stk.push(i);
            }
        }

        std::vector<int> safeNodes;
        while (!stk.empty()) {
            int node = stk.top();
            stk.pop();
            safeNodes.push_back(node);

            // Reduce the out-degree of all nodes in the reverse graph
            for (int prevNode : reverseGraph[node]) {
                outDegree[prevNode]--;
                if (outDegree[prevNode] == 0) {
                    stk.push(prevNode);
                }
            }
        }

        std::sort(safeNodes.begin(), safeNodes.end()); // Sort the result
        return safeNodes;
    }
};

int main() {
    FindEventualSafeStates_802 f1;
    std::vector<std::vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    std::vector<int> answer = f1.eventualSafeNodes(graph);
    for (auto i : answer) {
        std::cout << i << " ";
    }
    return 0;
}
