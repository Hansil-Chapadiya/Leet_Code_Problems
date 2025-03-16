from typing import List
from math import sqrt, floor

class MinimumTimetoRepairCars_2594:
    def __init__(self):
        self.__ranks__ = []
        self.__cars__ = 0

    def isPossible(self, midMinutes: int) -> bool:
        maxCars = 0
        for r in self.__ranks__:
            maxCars += floor(sqrt(midMinutes / r))
            if maxCars >= self.__cars__:  # If we can repair enough cars in this time
                return True
        return maxCars >= self.__cars__

    def repairCars(self, ranks: List[int], cars: int) -> int:
        self.__ranks__ = ranks
        self.__cars__ = cars
        low, high = 1, max(ranks) * cars * cars

        while low <= high:
            mid = (low + high) // 2
            if self.isPossible(mid):
                high = mid - 1  # Try to minimize time further
            else:
                low = mid + 1

        return low

# Example usage
obj = MinimumTimetoRepairCars_2594()
print(obj.repairCars([4, 2, 3, 1], 10))  # Output: 16
