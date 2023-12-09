class Solution:
    def removeAlmostEqualCharacters(self, word: str) -> int:
        """
        This function takes a string `word` and returns the minimum number of deletions
        needed to make the string contain only characters that are at most one character away
        from their neighbors in the alphabet.

        Args:
            word: The string to be processed.

        Returns:
            The minimum number of deletions needed.
        """

        # Initialize variables
        n = len(word)
        dp = [[float('inf')] * 26 for _ in range(n + 1)]  # Dynamic programming table
        dp[0] = [0] * 26  # Base case

        # Iterate through the string
        for i in range(1, n + 1):
            c = ord(word[i - 1]) - ord('a')  # Get current character code
            for a in range(26):  # Iterate through possible previous characters
                for b in range(26):  # Iterate through possible characters to compare
                    if abs(a - b) > 1:  # Only consider characters at most one away
                        dp[i][a] = min(dp[i][a], dp[i - 1][b] + (a != c))

        # Return the minimum number of deletions
        return min(dp[n])
