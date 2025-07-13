from typing import List

class KnapSack:
    def maxValue(self, weights: List[int], values : List[int], capacity) -> int:
        n = len(weights)
        dp = [[0 for _ in range(capacity+1)] for _ in range(n+1)]

        for i in range(1, n+1):
            for w in range(1,capacity+1):
                if(weights[i - 1] <= w):
                    dp[i][w] = max(dp[i-1][w], values[i-1]+dp[i-1][w - weights[i-1]])
                else:
                    dp[i][w] = dp[i-1][w]
        return dp[n][capacity]


obj = KnapSack()
print(obj.maxValue([1, 3, 4, 5],[10, 40, 50, 70],8))