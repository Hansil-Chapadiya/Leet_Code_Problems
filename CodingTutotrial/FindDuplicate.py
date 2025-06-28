from typing import List

class FindDuplicate:
    def getDuplicateElement(self, nums: List[int]) -> int:

        hashMap = {}

        for num in nums:
            hashMap[num] = hashMap.get(num,0) + 1
            if hashMap[num] > 1:
                return num

        return None

obj = FindDuplicate()
# print(obj.getDuplicateElement([1,3,4,2,2]))
print(obj.getDuplicateElement([3,1,3,4,2]))