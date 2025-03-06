from typing import List
from functools import reduce
import operator
class SingleNumber_136:
    def singleNumber(self, nums: List[int]) -> int:
        return reduce(operator.xor, nums)

obj = SingleNumber_136()
print(obj.singleNumber([]))