class CountLargestGroup_1399:
    def sumOfDigit(sef, n : int) -> int:
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