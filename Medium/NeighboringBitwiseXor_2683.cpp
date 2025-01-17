#include <iostream>
#include <vector>
class NeighboringBitwiseXor_2683
{
private:
    /* data */
public:
    bool doesValidArrayExist(std::vector<int> &derived)
    {
        std::vector<int> result;
        result.push_back(derived[derived.size()] ^ derived[0]);
        for (int i = 1; i < derived.size(); i++)
        {
            result.push_back(derived[i] ^ derived[i - 1]);
        }

        for (auto i : result)
        {
            if (i != 0 || i != 1)
            {
                return false;
            }
        }
        return 0;
    }
};
int main()
{
    std::vector<int> derived = {1, 1, 0};
    NeighboringBitwiseXor_2683 n1;
    std::cout << n1.doesValidArrayExist(derived);
    return 0;
}
