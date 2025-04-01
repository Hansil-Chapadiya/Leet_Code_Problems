from typing import List

class SolvingQuestionsWithBrainpower_2140:
    def mostPoints(self, questions: List[List[int]]) -> int:
        m = len(questions)
        dp = [0] * m  # DP array to store max points from each question

        # Base case: The last question's max points is its own value
        dp[m - 1] = questions[m - 1][0]

        # Process questions from second last to first
        for i in range(m - 2, -1, -1):
            points, brainpower = questions[i]  # Get points and brainpower

            # Solve the question and jump ahead
            next_question = i + brainpower + 1
            if next_question >= m:  # If we jump out of bounds, add 0
                dp[i] = max(points, dp[i + 1])
            else:  # Otherwise, add dp[next_question]
                dp[i] = max(points + dp[next_question], dp[i + 1])

        return dp[0]  # Max points from the first question

# Example usage
s1 = SolvingQuestionsWithBrainpower_2140()
print(s1.mostPoints([[3,2],[4,3],[4,4],[2,5]]))  # Output: 5
