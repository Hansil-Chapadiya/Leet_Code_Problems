""" class ShortestCommonSubSequence_1092:
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        lcsStr = self.lcs(str1, str2)
        print(lcsStr)
        i = 0
        j = 0
        lcsIndex = 0
        answer = []
        while i < len(str1) and j < len(str2):
            if (
                (lcsIndex < len(lcsStr))
                and str1[i] == lcsStr[lcsIndex]
                and str2[j] == lcsStr[lcsIndex]
            ):
                answer.append(str1[i])
                i += 1
                j += 1
                lcsIndex += 1
            if (lcsIndex < len(lcsStr)) and str1[i] != lcsStr[lcsIndex]:
                answer.append(str1[i])
                i += 1
            if (lcsIndex < len(lcsStr)) and str2[j] != lcsStr[lcsIndex]:
                answer.append(str2[j])
                j += 1

        while i < len(str1):
            answer.append(str1[i])
            i += 1

        while j < len(str2):
            answer.append(str2[j])
            j += 1

        return "".join(answer)

    def lcs(self, a: str, b: str) -> str:
        row, col = len(a) + 1, len(b) + 1
        dp = [[0 for _ in range(col)] for _ in range(row)]
        for i in range(1, row):
            for j in range(1, col):
                if a[i - 1] == b[j - 1]:
                    dp[i][j] = 1 + dp[i - 1][j - 1]
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

        i, j = len(a), len(b)
        lcsStr = []
        while i > 0 and j > 0:
            if a[i - 1] == b[j - 1]:
                lcsStr.append(a[i - 1])
                i -= 1
                j -= 1
            elif dp[i - 1][j] > dp[i][j - 1]:
                i -= 1
            else:
                j -= 1
        return "".join(reversed(lcsStr))


obj = ShortestCommonSubSequence_1092()
# print(obj.shortestCommonSupersequence("abac", "cab"))
print(obj.shortestCommonSupersequence("aaaaaaaa", "aaaaaaaa"))
 """


class ShortestCommonSubSequence_1092:
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        lcsStr = self.lcs(str1, str2)  # Get LCS
        print(lcsStr)  # Debugging

        i, j, lcsIndex = 0, 0, 0
        answer = []

        while lcsIndex < len(lcsStr):  # Process until all LCS characters are used
            # Add characters from str1 before reaching the LCS character
            while i < len(str1) and str1[i] != lcsStr[lcsIndex]:
                answer.append(str1[i])
                i += 1

            # Add characters from str2 before reaching the LCS character
            while j < len(str2) and str2[j] != lcsStr[lcsIndex]:
                answer.append(str2[j])
                j += 1

            # Append the LCS character once
            answer.append(lcsStr[lcsIndex])
            i += 1
            j += 1
            lcsIndex += 1

        # Append remaining characters of str1
        while i < len(str1):
            answer.append(str1[i])
            i += 1

        # Append remaining characters of str2
        while j < len(str2):
            answer.append(str2[j])
            j += 1

        return "".join(answer)

    def lcs(self, a: str, b: str) -> str:
        row, col = len(a) + 1, len(b) + 1
        dp = [[0 for _ in range(col)] for _ in range(row)]
        for i in range(1, row):
            for j in range(1, col):
                if a[i - 1] == b[j - 1]:
                    dp[i][j] = 1 + dp[i - 1][j - 1]
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

        # Backtrack to find the LCS string
        i, j = len(a), len(b)
        lcsStr = []
        while i > 0 and j > 0:
            if a[i - 1] == b[j - 1]:
                lcsStr.append(a[i - 1])
                i -= 1
                j -= 1
            elif dp[i - 1][j] > dp[i][j - 1]:
                i -= 1
            else:
                j -= 1
        return "".join(reversed(lcsStr))


# Test the optimized version
obj = ShortestCommonSubSequence_1092()
print(obj.shortestCommonSupersequence("abac", "cab"))
print(obj.shortestCommonSupersequence("aaaaaaaa", "aaaaaaaa"))  # Edge case test
