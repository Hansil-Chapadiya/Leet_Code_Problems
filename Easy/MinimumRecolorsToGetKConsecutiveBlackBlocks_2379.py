class MinimumRecolorsToGetKConsecutiveBlackBlocks_2379:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        min_ = 2**100
        n = len(blocks)
        if n == k:
            return blocks[:k].count("W")
        for i in range(n - k + 1):
            subStr_ = blocks[i : i + k]
            subCnt = subStr_.count("W")
            min_ = min(min_, subCnt)

        return min_


obj = MinimumRecolorsToGetKConsecutiveBlackBlocks_2379()
# print(obj.minimumRecolors("WBBWWBBWBW",7))
print(obj.minimumRecolors("WBWBBBW", 2))
