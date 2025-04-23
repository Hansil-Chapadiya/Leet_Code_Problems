from typing import List


class MissingNumber_268:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(n + 1):

            if i not in nums:
                return i

        return 0


obj = MissingNumber_268()
print(obj.missingNumber([3, 0, 1]))
