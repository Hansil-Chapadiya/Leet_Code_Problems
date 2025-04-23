""" from typing import List


class MissingNumber_268:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(n + 1):

            if i not in nums:
                return i

        return 0


obj = MissingNumber_268()
print(obj.missingNumber([3, 0, 1]))
 """

# from  typing import List

# class MissingNumber_268:
#     def missingNumber(self, nums: List[int]) -> int:
#         n = len(nums)
#         nums.sort()
#         if nums[n-1] == 0 and n == 1:
#             return 1
#         if n == 1:
#             return 0
#         if nums[0] != 0:
#             return 0
#         for i in range(1, n):

#             if (nums[i] - nums[i - 1]) > 1:
#                 return nums[i - 1] + 1
#         return nums[n - 1] + 1

# obj = MissingNumber_268()
# print(obj.missingNumber([3,0,1]))
# print(obj.missingNumber([0,1]))


from typing import List

class MissingNumber_268:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        # expected sum of 0..n
        expected = n * (n + 1) // 2
        # actual sum of elements
        actual = sum(nums)
        return expected - actual

obj = MissingNumber_268()
print(obj.missingNumber([3,0,1]))  # 2
print(obj.missingNumber([0,1]))    # 2
print(obj.missingNumber([]))       # 0
print(obj.missingNumber([1]))      # 0
