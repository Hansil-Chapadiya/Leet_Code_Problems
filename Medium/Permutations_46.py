from typing import List
import itertools

class Permutations_46:
    def permute(self, nums: List[int]) -> List[List[int]]:

        n = len(nums)

        perms = [list(perm) for perm in itertools.permutations(nums, n)]

        return perms


obj = Permutations_46()
print(obj.permute([1,2,3]))


"""
from typing import List

class Permutations_46:
    def permute(self, nums: List[int]) -> List[List[int]]:
        pool = tuple(nums)
        n = len(pool)
        r = n  # full length permutations

        indices = list(range(n))         # [0, 1, 2]
        cycles = list(range(n, 0, -1))   # [3, 2, 1]

        result = [list(pool[i] for i in indices[:r])]  # First permutation

        while n:
            for i in reversed(range(r)):
                cycles[i] -= 1
                if cycles[i] == 0:
                    # Rotate indices[i:] to the left
                    indices[i:] = indices[i+1:] + indices[i:i+1]
                    cycles[i] = n - i
                else:
                    j = cycles[i]
                    indices[i], indices[-j] = indices[-j], indices[i]
                    result.append([pool[i] for i in indices[:r]])
                    break
            else:
                return result

        return result




obj = Permutations_46()
print(obj.permute([1,2,3]))

"""
