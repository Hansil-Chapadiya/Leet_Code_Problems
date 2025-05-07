from typing import List
import itertools

class Permutations_46:
    def permute(self, nums: List[int]) -> List[List[int]]:

        n = len(nums)

        perms = list(itertools.permutations(nums,n))

        return perms


obj = Permutations_46()
print(obj.permute([1,2,3]))
