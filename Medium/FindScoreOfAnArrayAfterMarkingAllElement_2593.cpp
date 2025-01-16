#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <functional>

class FindScoreOfAnArrayAfterMarkingAllElement_2593
{
private:
    /* data */
public:
    long long findScore(std::vector<int> &nums)
    {
        std::priority_queue<std::tuple<int, int, bool>, std::vector<std::tuple<int, int, bool>>, std::greater<std::tuple<int, int, bool>>> pq;

        for (int i = 0; i < nums.size(); i++)
        {
            pq.push({nums[i], i, false});
        }

        // Array to track if an element is marked
        std::vector<bool> marked(nums.size(), false);
        long long score = 0;
        // Pop elements from the queue
        while (!pq.empty())
        {
            auto [priority, index, is_marked] = pq.top();
            pq.pop();

            // Skip if already marked
            if (marked[index])
                continue;
            score += priority;
            // Mark current element
            marked[index] = true;

            // std::cout << "Processing element at index " << index << " with priority " << priority << std::endl;

            // Mark left and right neighbors if they exist
            if (index > 0 && !marked[index - 1])
            {
                // std::cout << "Marking left neighbor at index " << index - 1 << " with value " << nums[index - 1] << std::endl;
                marked[index - 1] = true;
            }

            if (index < nums.size() - 1 && !marked[index + 1])
            {
                // std::cout << "Marking right neighbor at index " << index + 1 << " with value " << nums[index + 1] << std::endl;
                marked[index + 1] = true;
            }

            std::cout << "Priority: " << priority << ", Index: " << index << ", Marked: " << is_marked << std::endl;
        }
        return score;
    }
};
int main()
{
    FindScoreOfAnArrayAfterMarkingAllElement_2593 f1;
    std::vector<int> nums = {2, 1, 3, 4, 5, 2};
    std::cout<<f1.findScore(nums);
    return 0;
}