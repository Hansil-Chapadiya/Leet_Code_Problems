// #include <iostream>
// #include <vector>
// #include <queue>
// #include <unordered_map>

// class FindtheNumberofDistinctColorsAmongtheBalls_3160
// {
// private:
//     struct PQNode
//     {
//         int index;
//         int color_count;

//         bool operator<(const PQNode &other) const
//         {
//             return index > other.index;
//         }
//     };

//     // Function to compute distinct color count using unordered_map (faster than set)
//     int computeColorCount(std::unordered_map<int, int> &ballColorMap)
//     {
//         std::unordered_map<int, int> colorFrequency; // Track color occurrences
//         for (const auto &pair : ballColorMap)
//         {
//             colorFrequency[pair.second]++; // Insert color into map (ensures unique count)
//         }
//         return colorFrequency.size(); // Return the total number of distinct colors
//     }

// public:
//     std::vector<int> queryResults(int limit, std::vector<std::vector<int>> &queries)
//     {
//         std::priority_queue<PQNode> pq;
//         std::unordered_map<int, int> ballColorMap; // Track the latest color of each ball

//         for (int i = 0; i < queries.size(); i++)
//         {
//             int ball = queries[i][0];
//             int color = queries[i][1];

//             // Update the latest color of the ball
//             ballColorMap[ball] = color;

//             // Compute distinct color count using unordered_map (efficient)
//             int color_cnt = computeColorCount(ballColorMap);
//             pq.push({i, color_cnt});
//         }

//         // Print results
//         while (!pq.empty())
//         {
//             PQNode node = pq.top();
//             pq.pop();
//             std::cout << "Index: " << node.index << ", Color Count: " << node.color_count << std::endl;
//         }

//         return {}; // This function should return a vector if needed
//     }
// };

// int main()
// {
//     FindtheNumberofDistinctColorsAmongtheBalls_3160 f1;
//     std::vector<std::vector<int>> queries = {
//         {0, 1},  // Ball 0 → Color 1
//         {1, 2},  // Ball 1 → Color 2
//         {2, 2},  // Ball 2 → Color 2
//         {3, 4},  // Ball 3 → Color 4
//         {4, 5},  // Ball 4 → Color 5
//         {1, 3},  // Ball 1 repainted → Color 3
//         {2, 5}   // Ball 2 repainted → Color 5
//     };

//     f1.queryResults(10, queries);
//     return 0;
// }



#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

class FindtheNumberofDistinctColorsAmongtheBalls_3160
{
private:
    struct PQNode
    {
        int index;
        int color_count;

        bool operator<(const PQNode &other) const
        {
            return index > other.index;
        }
    };

    std::unordered_map<int, int> ballColorMap; // Ball → Latest Color
    std::unordered_map<int, int> colorFrequency; // Color → Frequency Count
    int distinctColorCount = 0; // Directly track unique color count

    void updateColorCount(int ball, int newColor)
    {
        if (ballColorMap.find(ball) != ballColorMap.end()) // Ball exists
        {
            int oldColor = ballColorMap[ball]; // Get previous color

            // Reduce frequency of the old color
            colorFrequency[oldColor]--;
            if (colorFrequency[oldColor] == 0)
            {
                distinctColorCount--; // If no more balls of this color, remove it
            }
        }

        // Assign new color to the ball
        ballColorMap[ball] = newColor;

        // Increase frequency of the new color
        if (colorFrequency[newColor] == 0)
        {
            distinctColorCount++; // If new color is first time seen, add it
        }
        colorFrequency[newColor]++;
    }

public:
    std::vector<int> queryResults(int limit, std::vector<std::vector<int>> &queries)
    {
        std::priority_queue<PQNode> pq;

        for (int i = 0; i < queries.size(); i++)
        {
            int ball = queries[i][0];
            int color = queries[i][1];

            // Update color efficiently
            updateColorCount(ball, color);

            // Push result to priority queue
            pq.push({i, distinctColorCount});
        }

        std::vector<int> v;
        while (!pq.empty())
        {
            PQNode node = pq.top();
            pq.pop();
            v.push_back(node.color_count);
            // std::cout << "Index: " << node.index << ", Color Count: " << node.color_count << std::endl;
        }

        return v; // This function should return a vector if needed
    }
};

int main()
{
    FindtheNumberofDistinctColorsAmongtheBalls_3160 f1;
    std::vector<std::vector<int>> queries = {
        {0, 1},  // Ball 0 → Color 1
        {1, 2},  // Ball 1 → Color 2
        {2, 2},  // Ball 2 → Color 2
        {3, 4},  // Ball 3 → Color 4
        {4, 5},  // Ball 4 → Color 5
        {1, 3},  // Ball 1 repainted → Color 3
        {2, 5}   // Ball 2 repainted → Color 5
    };

    f1.queryResults(10, queries);
    return 0;
}
