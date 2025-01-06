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
        int operation = 0, balls = 0;
        for (int i = 0; i < boxes.length(); i++)
        {
            if (balls > 0)
            {
                operation += balls;
            }
            answer[i] = operation;
            if (boxes[i] == '1')
            {
                balls++;
                /* code */
            }
        }
        operation = balls = 0;
        for (int i = boxes.length() - 1; i >= 0; i--)
        {
            operation += balls;
            if (boxes[i] == '1')
            {
                balls++;
            }
            answer[i] += operation;
        }
        return answer;
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