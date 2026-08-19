#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        /*
            A palindrome reads the same from left to right and right to left.
            Examples:
                "racecar"
                "abba"
                "a"

            Every palindrome has a center.

            Odd-length palindrome:
                "racecar"
            
            Even-length palindrome:
                "abba"

            We will try every possible center and expand outward while the characters continue matching.
        */

        //These variables store the best palindrome found so far.
        int bestStart = 0;
        int bestLength = 0;

        /*
            This helper function expands around a chosen center. 

            left = index on the left side of the center
            right = index on the right side of the center
        */
        auto expandFromCenter = [&](int left, int right) {
            /*
                Continue expanding while:
                1. left is inside the string
                2. right is inside the string 
                3. The characters on both sides match 
            */
                while (left >= 0 &&
                   right < s.length() &&
                   s[left] == s[right]) {
                /*
                    The substring from left to right is currently a palindrome because its outer characters 
                    match and the previous expansion was also valid.
                */

                int currentLength = right - left + 1;

                /*
                    If this palindrome is longer than the best one found so far, save its starting position
                    and length
                */
                if ( currentLength > bestLength) {
                    bestStart = left;
                    bestLength = currentLength;
                }

                /*
                    Move outward to check whether the palindrome can be extended by one character on both sides.
                */
                left--;
                right++;
            }
        };

        /*
            Every character can be the center of an odd-length palindrome.

            Example:
                "aba"
                  ^ center is 'b'

            We also check every gap between two characters as the center of an even-length palindrome 

            Example:
                "abba"
                  ^^ center is the gap between the 'b' characters
        */
        for(int i = 0; i < s.length(); i++)  {
            // Check palindrome with an odd length
            expandFromCenter(i, i);

            // Check palindrome with an even length 
            expandFromCenter(i, i + 1);
        }

        /*
            Return the longest palindrome using:

                starting index = bestStart;
                number of characters = bestLength
        */
        return s.substr(bestStart, bestLength);
    }
};
