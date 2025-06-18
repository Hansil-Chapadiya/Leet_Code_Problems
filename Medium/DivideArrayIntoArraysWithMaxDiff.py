from typing import List

class DivideArrayIntoArraysWithMaxDiff:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        nums.sort()
        answer = []
        lenOfArray = len(nums)
        i = 0

        while i < lenOfArray:
            temp = []

            for _ in range(3):
                if i < lenOfArray:
                    temp.append(nums[i])
                    i += 1
                else:
                    break

            if len(temp) == 3 and (max(temp) - min(temp)) <= k:
                answer.append(temp)
            else:
                return []  # If we can't form a valid group

        return answer

obj = DivideArrayIntoArraysWithMaxDiff()
print(obj.divideArray([1,3,4,8,7,9,3,5,1],2))