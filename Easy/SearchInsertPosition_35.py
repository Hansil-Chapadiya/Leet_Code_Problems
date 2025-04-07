from typing import List

class SearchInsertPosition_35:
    def searchInsert(self, nums: List[int], target: int) -> int:
        high = len(nums) - 1
        low = 0

        while low <= high:
            mid = (low + high) // 2
            if target == nums[mid]:
                return mid
            if target < nums[mid]:
                high = mid-1
            else:
                low = mid+1
        return low

obj = SearchInsertPosition_35()
print(obj.searchInsert([1,3,5,6],2))
print(obj.searchInsert([1,3,5,6],5))
print(obj.searchInsert([1,3,5,6],0))
print(obj.searchInsert([1,3,5,6],7))
