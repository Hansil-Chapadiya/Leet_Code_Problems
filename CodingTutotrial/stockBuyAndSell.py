""" from typing import List

class stockBuyAndSell:
    def buyAndSell(self, nums: List[int]) -> int:
        maxProfit = 0

        for price in range(0,len(nums)):
            minPrice = nums[0]
            for priceCmp in range(price+1, len(nums)):
                maxProfit = max(maxProfit, nums[priceCmp] - nums[price])
        return maxProfit

obj = stockBuyAndSell()
# print(obj.buyAndSell([7,1,5,3,6,4]))
print(obj.buyAndSell([7,6,4,3,1])) """

from typing import List

class stockBuyAndSell:
    def buyAndSell(self, nums: List[int]) -> int:
        maxProfit = 0
        minPrice = float('inf')

        for price in range(0,len(nums)):
            minPrice = min(minPrice, nums[price])
            maxProfit = max(maxProfit, nums[price] - minPrice)
        return int(maxProfit)

obj = stockBuyAndSell()
print(obj.buyAndSell([7,1,5,3,6,4]))
# print(obj.buyAndSell([7,6,4,3,1]))