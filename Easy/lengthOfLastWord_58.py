class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        n = len(s) - 1

        while s[n] == " " and n >= 0:
            n -= 1

        if n < 0:
            return 0

        cnt = 0
        for i in range(n, -1, -1):

            if s[i] == " ":
                break
            else:
                cnt += 1

        return cnt
