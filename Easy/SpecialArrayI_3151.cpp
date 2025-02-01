#include <iostream>
#include <vector>
class SpecialArrayI_3151
{
private:
    bool isOdd(int n1)
    {
        if (n1 % 2 == 1)
        {
            return true;
        }
        return false;
    }

public:
    bool isArraySpecial(std::vector<int> &nums)
    {

    }
};
int main()
{
    SpecialArrayI_3151 s1;
    std::vector<int> nums = {};
    s1.isArraySpecial(nums);
}