#include <iostream>
#include <vector>
class DefuseTheBomb_1652
{
private:
    /* data */
public:
    std::vector<int> decrypt(std::vector<int> &code, int k)
    {
        int n = code.size();
        std::vector<int> result(n, 0);

        if (k == 0)
        {
            // Reset the entire array to 0
            std::fill(code.begin(), code.end(), 0);
            return code;
        }

        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            if (k > 0)
            {
                // Sum of the next k elements (circular)
                for (int j = 1; j <= k; j++)
                {
                    sum += code[(i + j) % n];
                }
            }
            else if (k < 0)
            {
                // Sum of the previous |k| elements (circular)
                for (int j = 1; j <= -k; j++)
                {
                    sum += code[(i - j + n) % n];
                }
            }
            result[i] = sum;
        }

        // Update original array
        return result;
    }
};
int main()
{
    DefuseTheBomb_1652 d1;
    std::vector<int> code = {5, 7, 1, 4};
    d1.decrypt(code, 3);
    return 0;
}
