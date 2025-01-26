#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        int longestCycle = 0;
        vector<bool> visited(n, false);
        vector<vector<int>> reverseList(n);

        // Prepare reverse adjacency list
        for (int i = 0; i < n; ++i) {
            reverseList[favorite[i]].push_back(i);
        }

        // Detect cycles and collect 2-length cycles
        vector<pair<int, int>> twoLenCycles;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            unordered_set<int> seen;
            int start = i, current = i, length = 0;

            while (!visited[current]) {
                visited[current] = true;
                seen.insert(current);
                current = favorite[current];
            }

            length = seen.size();
            while (start != current) {
                --length;
                start = favorite[start];
            }

            longestCycle = max(longestCycle, length);
            if (length == 2) {
                twoLenCycles.emplace_back(current, favorite[current]);
            }
        }

        // Calculate the maximum path length for 2-length cycles
        int maxTwoLenCyclePath = 0;
        for (const auto& cycle : twoLenCycles) {
            maxTwoLenCyclePath += bfs(cycle.first, cycle.second, reverseList)
                                + bfs(cycle.second, cycle.first, reverseList) + 2;
        }

        // Return the maximum of the longest cycle or the sum of paths with 2-length cycles
        return max(longestCycle, maxTwoLenCyclePath);
    }

private:
    int bfs(int node, int skip, const vector<vector<int>>& reverseList) {
        int length = 0;
        queue<pair<int, int>> q; // {node, distance}
        q.push({node, 0});

        while (!q.empty()) {
            auto [current, dist] = q.front();
            q.pop();
            length = max(length, dist);

            for (int neighbor : reverseList[current]) {
                if (neighbor == skip) continue;
                q.push({neighbor, dist + 1});
            }
        }

        return length;
    }
};
