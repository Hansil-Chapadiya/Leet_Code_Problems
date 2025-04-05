from typing import List
class SumofAllSubsetXORTotals_1863:
    def __init__(self):
        self.total = 0
    def subsetXORSum(self, nums: List[int]) -> int:

        def recursion(index, currentXOR):
            if index == len(nums):
                self.total += currentXOR
                return
            recursion(index+1,currentXOR)
            recursion(index+1,currentXOR ^ nums[index])

        recursion(0,0)
        return self.total

obj = SumofAllSubsetXORTotals_1863()
print(obj.subsetXORSum([1,3]))