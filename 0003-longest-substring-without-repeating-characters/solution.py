class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # Stores the most recent index where each character appeared.
        last_seen = {}

        # Left boundary of the current substring/window.
        left = 0

        # Length of the longest valid substring found so far.
        longest = 0

        # Expand the window by moving the right boundary through the string.
        for right, character in enumerate(s):
            # If the character is already inside the current window,
            # move the left boundary past its previous occurrence.
            #
            # The condition left <= last_seen[character] is important.
            # It ensures that we only react to duplicates inside the
            # current window, not duplicates that are already behind it.
            if character in last_seen and last_seen[character] >= left:
                left = last_seen[character] + 1

            # Record the character's newest position.
            last_seen[character] = right

            # The current window is from left to right, inclusive.
            current_length = right - left + 1

            # Keep the maximum window length found so far.
            longest = max(longest, current_length)

        return longest
