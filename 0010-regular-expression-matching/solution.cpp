#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        /*
            The pattern contains:
            '.' -> matches any single character
            '*' -> matches zero or more of the previous element 

            Example: 
            'a' matches 'a'
            '.' matches 'a'
            'a*' matches ' ','a', 'aa', 'aaa' ...

            We use dynamic programming. 
            dp[i][j] means:
                Does the first i characters of a match the first j characters of p?
        */

        int m = s.length();
        int n = p.length();

        /*
            Create a DP table with:
                m + 1 rows
                n + 1 colums 
            The entire row and column represent empty strings.

            dp[0][0] means:
                Empty string matches empty pattern.
        */
        vector<vector<bool>> dp(
            m + 1,
            vector<bool>(n + 1, false)
        );

        /*
            Base case:

                An empty string matches an empty pattern.
        */
        dp[0][0] = true;

        /*
            Handle patterns that can match an empty string.

            A '*' can remove itself and the character before it.

            For example:

                Pattern: "a*"

                It can match:
                    ""
                    "a"
                    "aa"
                    ...

            Therefore, "a*" can match an empty string.

            For a pattern like "a*b*c*", we process:

                a* -> empty
                a*b* -> empty
                a*b*c* -> empty
        */
        for (int j = 2; j <= n; j++) {
            if (p[j - 1] == '*') {
                /*
                    Ignore the character before '*'
                    and ignore the '*'.

                    dp[0][j - 2] represents the pattern before
                    this "x*" group.
                */
                dp[0][j] = dp[0][j - 2];
            }
        }

        /*
            Fill the table row by row.

            i represents how many characters of s we are using.
            j represents how many characters of p we are using.
        */
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                /*
                    Case 1: The current pattern character is a normal
                    character or a dot.

                    It matches the current string character when:

                        p[j - 1] == s[i - 1]

                    or:

                        p[j - 1] == '.'
                */
                if (p[j - 1] == '.' ||
                    p[j - 1] == s[i - 1]) {

                    /*
                        If the current characters match, the answer
                        depends on whether everything before them matched.
                    */
                    dp[i][j] = dp[i - 1][j - 1];
                }

                /*
                    Case 2: The current pattern character is '*'.

                    The '*' applies to the character immediately before it.

                    Example:

                        pattern: "a*"
                                  ^
                                  '*'
                    */
                else if (p[j - 1] == '*') {
                    /*
                        Option A: Use '*' as matching zero occurrences.

                        We remove both:

                            the character before '*'
                            '*'

                        Example:

                            "a*" becomes ""

                        Therefore, look two pattern positions back.
                    */
                    dp[i][j] = dp[i][j - 2];

                    /*
                        Option B: Use '*' to match one or more occurrences.

                        This is possible only if the character before '*'
                        matches the current string character.

                        The character before '*' can match when:

                            p[j - 2] == s[i - 1]

                        or:

                            p[j - 2] == '.'
                    */
                    if (p[j - 2] == '.' ||
                        p[j - 2] == s[i - 1]) {

                        /*
                            Keep the '*' in the pattern and consume one
                            character from the string.

                            dp[i - 1][j] asks:

                                Does the previous part of the string
                                match the same pattern including '*'?
                        */
                        dp[i][j] =
                            dp[i][j] || dp[i - 1][j];
                    }
                }

                /*
                    If the pattern character is a normal character that
                    does not match, dp[i][j] remains false.
                */
            }
        }

        /*
            The answer is whether the entire string matches the
            entire pattern.
        */
        return dp[m][n];
    }
};
