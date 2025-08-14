class Solution:
    def largestGoodInteger(self, num: str) -> str:
        maxNum = ""

        for i in range(len(num) - 2):
            if num[i] == num[i+1] == num[i+2]:
                triple = num[i:i+3]
                if triple > maxNum:
                    maxNum = triple

        return maxNum

obj = Solution()
print(obj.largestGoodInteger("000000000000000000000000000"))