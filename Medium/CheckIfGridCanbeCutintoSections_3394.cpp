#include <iostream>
#include <vector>
#include <algorithm> // For std::max

class CheckIfGridCanbeCutintoSections_3394
{
public:
    std::vector<std::vector<int>> mergedSize(std::vector<std::vector<int>> &rectangles, bool vertical)
    {
        std::vector<std::vector<int>> intervals;
        for (int i = 0; i < rectangles.size(); i++)
        {
            if (vertical)
            {
                intervals.push_back({rectangles[i][0], rectangles[i][2]});
            }
            else
            {
                intervals.push_back({rectangles[i][1], rectangles[i][3]});
            }
        }

        // Sort intervals based on starting point
        std::sort(intervals.begin(), intervals.end());

        std::vector<std::vector<int>> merged;
        std::vector<int> current = intervals[0];

        for (int i = 1; i < intervals.size(); i++)
        {
            std::vector<int> next = intervals[i];
            if (current[1] > next[0]) // Overlapping intervals
            {
                current[1] = std::max(current[1], next[1]);
            }
            else
            {
                merged.push_back(current);
                current = next;
            }
        }

        // Don't forget to push the last interval
        merged.push_back(current);
        return merged;
    }

    bool checkValidCuts(int n, std::vector<std::vector<int>> &rectangles)
    {
        std::vector<std::vector<int>> mergedVertical = mergedSize(rectangles, true);
        std::vector<std::vector<int>> mergedHorizontal = mergedSize(rectangles, false);

        return (mergedVertical.size() >= 3 || mergedHorizontal.size() >= 3);
    }
};

int main()
{
    CheckIfGridCanbeCutintoSections_3394 c1;
    std::vector<std::vector<int>> rectangles = {{1, 0, 5, 2}, {0, 2, 2, 4}, {3, 2, 5, 3}, {0, 4, 4, 5}};

    bool result = c1.checkValidCuts(5, rectangles);
    std::cout << "Can the grid be cut into sections? " << (result ? "Yes" : "No") << std::endl;
    return 0;
}
