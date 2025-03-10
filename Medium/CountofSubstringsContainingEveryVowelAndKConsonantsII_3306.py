class Solution:
    def _isVowel(self, c: str) -> bool:
        return c in ["a", "e", "i", "o", "u"]

    def _atLeastK(self, word: str, k: int) -> int:
        num_valid_substrings = 0
        start = 0
        end = 0
        vowel_count = {}  # Track unique vowels
        consonant_count = 0  # Count consonants in window

        while end < len(word):
            new_letter = word[end]
            if self._isVowel(new_letter):
                vowel_count[new_letter] = vowel_count.get(new_letter, 0) + 1
            else:
                consonant_count += 1

            # If window is valid (all vowels & consonants >= k)
            while len(vowel_count) == 5 and consonant_count >= k:
                num_valid_substrings += len(word) - end  # Count substrings
                start_letter = word[start]
                if self._isVowel(start_letter):
                    vowel_count[start_letter] -= 1
                    if vowel_count[start_letter] == 0:
                        vowel_count.pop(start_letter)
                else:
                    consonant_count -= 1
                start += 1

            end += 1

        return num_valid_substrings

    def countOfSubstrings(self, word: str, k: int) -> int:
        return self._atLeastK(word, k) - self._atLeastK(word, k + 1)


# Test
obj = Solution()
print(obj.countOfSubstrings("iqeaouqi", 2))  # Expected Output: Correct count


"""
class CountofSubstringsContainingEveryVowelAndKConsonantsII_3306:
    def __init__(self):
        self.vowelSet_ = {"a", "e", "i", "o", "u"}
        self.constant_ = {
            "b", "c", "d", "f", "g", "h", "j", "k", "l", "m",
            "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z"
        }

    def countOfSubstrings(self, word: str, k: int) -> int:
        n = len(word)
        subStrlen = len(self.vowelSet_) + k
        f = True
        cntSubStr = 0
        for i in range(n - subStrlen+1):
            c = 0
            subStr = word[i : i + subStrlen]
            print(subStr)
            tempStr = []
            for j in subStr:
                if c < k and j in self.constant_:
                    tempStr.append(j)
                    c += 1
                elif j in self.vowelSet_:
                    tempStr.append(j)
            if len(subStr) == len(tempStr):
                cntSubStr += 1
        return cntSubStr


obj = CountofSubstringsContainingEveryVowelAndKConsonantsII_3306()
print(obj.countOfSubstrings("aoaiuefi", 1))





"""
