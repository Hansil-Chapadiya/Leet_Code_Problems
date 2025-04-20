#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

class RabbitsInForest_781
{
public:
    int numRabbits(std::vector<int> &answers)
    {
        std::unordered_map<int, int> uMap;

        for (int i = 0; i < answers.size(); i++)
        {
            uMap[answers[i]]++;
        }

        int cnt = 0;

        for (auto &entry : uMap)
        {
            int groupSize = entry.first + 1;
            int groupNeeded = std::ceil((double)entry.second / groupSize);
            cnt += groupSize * groupNeeded;
        }

        return cnt;
    }
};

int main()
{
    RabbitsInForest_781 r1;

    // std::vector<int> answers = {1, 1, 2};
    std::vector<int> answers = {10, 10, 10};

    std::cout << r1.numRabbits(answers) << std::endl;

    return 0;
}
