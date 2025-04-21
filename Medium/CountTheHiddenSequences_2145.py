class Solution:
    def numberOfArrays(self, differences: List[int], lower: int, upper: int) -> int:
        val1 = 0
        val2 = 0
        current = 0

        for d in differences:

            current += d

            val1 = min(val1, current)
            val2 = max(val2, current)

            if val2 - val1 > upper - lower:
                return 0

        return (upper - lower) - (val2 - val1) + 1