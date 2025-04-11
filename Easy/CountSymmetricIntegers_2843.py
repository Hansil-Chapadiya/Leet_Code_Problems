class CountSymmetricIntegers_2843:
    def countSymmetricIntegers(self, low: int, high: int) -> int:
        cnt = 0
        for i in range(low, high + 1):
            iStr = str(i)
            length = len(iStr)

            if length % 2 != 0:
                continue  # Skip odd-length numbers

            half = length // 2
            firstHalf = sum(int(iStr[j]) for j in range(half))
            secondHalf = sum(int(iStr[j]) for j in range(half, length))

            if firstHalf == secondHalf:
                cnt += 1

        return cnt

# Test it out!
obj = CountSymmetricIntegers_2843()
print(obj.countSymmetricIntegers(1, 100))       # Output should be correct now
# print(obj.countSymmetricIntegers(1200, 1230)) # You can test more cases
