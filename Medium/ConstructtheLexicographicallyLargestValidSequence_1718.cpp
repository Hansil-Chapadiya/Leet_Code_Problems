#include <iostream>
#include <vector>

class ConstructtheLexicographicallyLargestValidSequence_1718
{
private:
    int n;

    bool backtrack(int index, int &size, std::vector<int> &result, std::vector<bool> &placed)
    {
        if (index == size)
            return true;

        if (result[index] != 0)
            return backtrack(index + 1, size, result, placed);

        for (int i = n; i >= 1; i--) // Fix: Start from 'n' down to '1'
        {
            if (placed[i])
                continue;

            if (i == 1)
            {
                result[index] = 1;
                placed[1] = true;
                if (backtrack(index + 1, size, result, placed))
                    return true;
                result[index] = 0;
                placed[1] = false;
            }
            else
            {
                int second_index = index + i;
                if (second_index < size && result[second_index] == 0) // Fix: Check result[second_index]
                {
                    result[index] = i;
                    result[second_index] = i;
                    placed[i] = true;

                    if (backtrack(index + 1, size, result, placed))
                        return true;

                    result[index] = 0;
                    result[second_index] = 0;
                    placed[i] = false;
                }
            }
        }
        return false;
    }

public:
    std::vector<int> constructDistancedSequence(int n)
    {
        int size = 2 * n - 1;
        std::vector<int> result(size, 0);
        std::vector<bool> placed(n + 1, false);
        this->n = n;
        backtrack(0, size, result, placed);
        return result;
    }
};

int main()
{
    ConstructtheLexicographicallyLargestValidSequence_1718 c1;
    std::vector<int> answer = c1.constructDistancedSequence(3);

    for (int i : answer)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
