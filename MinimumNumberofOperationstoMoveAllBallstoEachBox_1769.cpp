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

/*
def minOperations(boxes):
    n = len(boxes)
    answer = [0] * n  # Initialize result array with zeros

    for i in range(n):  # For each target box
        moves = 0
        for j in range(n):  # Check all other boxes
            if boxes[j] == '1':  # If the box has a ball
                moves += abs(j - i)  # Add the distance to moves
        answer[i] = moves  # Store the result for box i

    return answer

 */