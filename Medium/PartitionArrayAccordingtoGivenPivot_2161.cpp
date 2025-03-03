#include <iostream>
#include <vector>
class PartitionArrayAccordingtoGivenPivot
{
public:
    std::vector<int> pivotArray(std::vector<int> &nums, int pivot)
    {
        /* std::vector<int> leftArray;
        std::vector<int> rightArray;
        std::vector<int> pivotArray;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < pivot)
                leftArray.push_back(nums[i]);
            else if (nums[i] == pivot)
                pivotArray.push_back(nums[i]);
            else
                rightArray.push_back(nums[i]);
        }

        std::vector<int> result;
        for (int i = 0; i < leftArray.size(); i++)
        {
            result.push_back(leftArray[i]);
        }
        for (int i = 0; i < pivotArray.size(); i++)
        {
            result.push_back(pivotArray[i]);
        }
        for (int i = 0; i < rightArray.size(); i++)
        {
            result.push_back(rightArray[i]);
        }
        return result; */
        int leftCount = 0;
        int pivotCount = 0;
        std::vector<int> result(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < pivot)
                leftCount++;
            else if (nums[i] == pivot)
                pivotCount++;
        }

        int leftIndex = 0;
        int pivotIndex = leftCount;
        int rightIndex = leftCount + pivotCount;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < pivot)
                result[leftIndex++] = nums[i];
            else if (nums[i] == pivot)
                result[pivotIndex++] = nums[i];
            else
                result[rightIndex++] = nums[i];
        }
        return result;
    }
};
int main()
{
    PartitionArrayAccordingtoGivenPivot p1;
    // std::vector<int> nums = {9,12,5,10,14,3,10};
    std::vector<int> nums = {-3, 4, 3, 2};
    std::vector<int> result = p1.pivotArray(nums, 2);
    for (auto i : result)
    {
        std::cout << i << " ";
    }
    return 0;
}