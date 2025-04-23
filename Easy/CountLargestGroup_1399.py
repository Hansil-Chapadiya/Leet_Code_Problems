class CountLargestGroup_1399:
    def sumOfDigit(self, n : int) -> int:
        rem = 0
        sum_ = 0

        while n > 0:

            rem = n % 10
            sum_ += rem
            n //= 10

        return sum_

    def countLargestGroup(self, n: int) -> int:

        groups = {}
        for i in range(1,n+1):
            sod = self.sumOfDigit(i)
            groups[sod] = groups.get(sod, 0) + 1

        cnt = 0
        max_ = 0

        for i,j in groups.items():
            print(i,j)
            if j > max_:
                max_ = j
                cnt = 1
            elif j == max_:
                cnt += 1


        return cnt

obj = CountLargestGroup_1399()
print(obj.countLargestGroup(13))


"""def sumOfDigit(self, n: int) -> int:
        total = 0
        while n > 0:
            total += n % 10
            n //= 10
        return total

    def countLargestGroup(self, n: int) -> int:
        groups = {}
        for i in range(1, n + 1):
            sod = self.sumOfDigit(i)
            groups[sod] = groups.get(sod, 0) + 1

        max_size = max(groups.values())
        # count how many sums have this max frequency
        return sum(1 for freq in groups.values() if freq == max_size)
"""