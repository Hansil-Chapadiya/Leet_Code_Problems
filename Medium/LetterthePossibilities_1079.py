class LetterthePossibilities:
    def numTilePossibilities(self, tiles: str) -> int:
        freqMap = self.createFrequencymap(tiles)  # Create frequency map
        return self.backtrack(freqMap)  # Start backtracking

    @classmethod
    def backtrack(cls, freqMap: dict) -> int:
        count = 0
        for letter in freqMap:
            if freqMap[letter] > 0:  # If letter is available to use
                count += 1  # Count the current sequence

                freqMap[letter] -= 1  # Use the letter
                count += cls.backtrack(freqMap)  # Recurse to build more sequences
                freqMap[letter] += 1  # Backtrack: Restore the letter

        return count

    @classmethod
    def createFrequencymap(cls, tiles: str) -> dict:
        freqMap = {}
        for tile in tiles:
            freqMap[tile] = freqMap.get(tile, 0) + 1  # Initialize and count occurrences
        return freqMap


# Call the function directly without creating an instance
obj = LetterthePossibilities()
print(obj.numTilePossibilities("AAB"))
