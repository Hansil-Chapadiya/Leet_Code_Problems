from typing import List
from functools import reduce
import operator


class SingleNumber_136:
    def singleNumber(self, nums: List[int]) -> int:
        # return reduce(operator.xor, nums)
        res = 0
        for i in nums:
            res ^= i
        return res


obj = SingleNumber_136()
print(obj.singleNumber([2,2,1]))