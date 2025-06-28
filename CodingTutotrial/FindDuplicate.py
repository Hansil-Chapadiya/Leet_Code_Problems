""" from typing import List

class FindDuplicate:
    def getDuplicateElement(self, nums: List[int]) -> int:

        hashMap = {}

        for num in nums:
            hashMap[num] = hashMap.get(num,0) + 1
            if hashMap[num] > 1:
                return num

        return -1

obj = FindDuplicate()
# print(obj.getDuplicateElement([1,3,4,2,2]))
print(obj.getDuplicateElement([3,1,3,4,2])) """


f""" rom typing import List
from collections import Counter

class FindDuplicate:
    def getDuplicateElement(self, nums: List[int]) -> int:

        freqcounter = Counter(nums)
        for item, count in freqcounter.items():
            if count > 1:
                return item

        return -1

obj = FindDuplicate()
# print(obj.getDuplicateElement([1,3,4,2,2]))
print(obj.getDuplicateElement([3,1,3,4,2])) """

from typing import List
from collections import Counter

class FindDuplicate:
    def getDuplicateElement(self, nums: List[int]) -> int:
        low = 1
        high = len(nums) - 1  # max value should be n-1

        while low < high:
            mid = (low + high) // 2
            count = sum(num <= mid for num in nums)

            if count > mid:
                high = mid
            else:
                low = mid + 1

        return low


obj = FindDuplicate()
print(obj.getDuplicateElement([1,3,4,2,2]))
# print(obj.getDuplicateElement([3,1,3,4,2])) #1,2,3,3,4