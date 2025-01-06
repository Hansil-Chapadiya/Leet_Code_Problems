#include <iostream>
#include <vector>
#include <string>
class MinimumNumberofOperationstoMoveAllBallstoEachBox_1769
{
private:
    /* data */
public:
    std::vector<int> minOperations(std::string boxes)
    {
        std::vector<int> answer(boxes.length(), 0);
    }
};
int main()
{
    MinimumNumberofOperationstoMoveAllBallstoEachBox_1769 m1;
    std::vector<int> answer = m1.minOperations("110");
    for (auto i : answer)
    {
        std::cout << i << " ";
    }

    return 0;
}