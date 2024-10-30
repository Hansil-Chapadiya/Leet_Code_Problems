from typing import List

def minimum_removals_for_bitonic(nums: List[int]) -> int:
    n = len(nums)

#Step 1 : Find LIS ending at each index
    lis = [1] * n  # longest increasing subsequence length up to each index
    for i in range(1, n):
        for j in range(i):
            if nums[i] > nums[j]:
                lis[i] = max(lis[i], lis[j] + 1)

#Step 2 : Find LDS starting at each index
    lds = [1] * n  # longest decreasing subsequence length from each index to the end
    for i in range(n-2, -1, -1):
        for j in range(i+1, n):
            if nums[i] > nums[j]:
                lds[i] = max(lds[i], lds[j] + 1)

#Step 3 : Calculate maximum bitonic subsequence length
    max_bitonic_length = 0
    for i in range(n):
#To form a bitonic sequence at index i, we need at least 1 element in both LIS and LDS
        if lis[i] > 1 and lds[i] > 1:
            max_bitonic_length = max(max_bitonic_length, lis[i] + lds[i] - 1)

#Step 4 : Minimum removals required to form the longest bitonic sequence
    min_removals = n - max_bitonic_length
    return min_removals

#Given input
nums = [2, 1, 1, 5, 6, 2, 3, 1]
print(minimum_removals_for_bitonic(nums))
