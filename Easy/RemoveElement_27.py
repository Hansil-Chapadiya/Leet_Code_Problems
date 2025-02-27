from typing import List


class RemoveElement:
    def removeElement(self, nums: List[int], val: int) -> int:
        # result.remove(val)

        while val in nums:
            nums.remove(val)
        return len(nums)


obj = RemoveElement()
print(obj.removeElement([3, 2, 2, 3], 3))
