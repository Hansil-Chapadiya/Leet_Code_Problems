from typing import List


class RepeatingAndMissingNumber:
    def repeatAndMiss(self, nums: List[int]) -> int:
        n = len(nums)

        total_sum = (n * (n + 1)) // 2
        sum_of_array = sum(nums)
        sum_of_unique_elements_of_array = sum(set(nums))
        diff = total_sum - sum_of_array

        missing_num = total_sum - sum_of_unique_elements_of_array
        repeatNum = missing_num - (total_sum - sum_of_array)

        return [repeatNum, missing_num]


obj = RepeatingAndMissingNumber()
print(obj.repeatAndMiss([3, 1, 2, 5, 3]))
