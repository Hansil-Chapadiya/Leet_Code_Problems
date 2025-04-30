""" class Solution:
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
 """

class LengthOfLastWord_58:
    def lengthOfLastWord(self, s: str) -> int:
        n = len(s) - 1

        # Skip trailing spaces
        while n >= 0 and s[n] == " ":
            n -= 1

        # If string is only spaces
        if n < 0:
            return 0

        cnt = 0
        # Count length of last word
        while n >= 0 and s[n] != ' ':
            cnt += 1
            n -= 1

        return cnt

# Test
obj = LengthOfLastWord_58()
print(obj.lengthOfLastWord("Hello World"))  # Output: 5
