class CheckIfNumberISSumOfPowersOfThree:
    def checkPowersOfThree(self, n: int) -> bool:
        while n > 0:
            rem = n % 3
            if rem == 2:
                return False
            n //= 3

        return True


obj = CheckIfNumberISSumOfPowersOfThree()
print(obj.checkPowersOfThree(10))
