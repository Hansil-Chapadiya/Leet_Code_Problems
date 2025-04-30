from typing import List

class FindNumberswithEvenNumberofDigits_1295:
    def findNumbers(self, nums: List[int]) -> int:
        cnt  = 0
        for i in nums:
            nLen = len(str(i))
            if nLen % 2 == 0:
                cnt += 1

        return cnt

obj = FindNumberswithEvenNumberofDigits_1295()
print(obj.findNumbers([12,345,2,6,7896]))