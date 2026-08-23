class Solution {
public:
    bool isPalindrome(int x) {
        /*
            A palindrome number reads the same from left to right and right to left.
            Examples:
                121         -> palindrome
                1331        -> palindrome 
                123         -> not a palindrome 
        */

        /*
            Negative numbers cannot be palindromes.
            The minus sign only appears at the beginning, so it would not match a character at the end.
            Example:
                    -121
            Reversed Form:
                    121-
            These are not the same.
        */
        if (x < 0) {
            return false;
        }

        /*
            Numbers ending in zero cannot be palindromes unless the number is exactly zero.
            Examples:
                    10 -> reversed is 01, which is not the same 
                    100 -> reversed is 001, which is not the same 
        */
        if (x != 0 && x % 10 == 0) {
            return false;
        }

        /*
            Instead of reversing the entire number, we only reverse the second half.
            This avoids possible integer overflow and lets us compare the first half with the reversed second half.
        */
        int reversedHalf = 0;

        /*
            Continue until the reversed second half becomes greater than or equal to the remaining first half.
            Exanple for 1221:
                    x = 1221, reversedHalf = 0
                    x = 122,  reversedHalf = 1 
                    x = 12,   reversedHalf = 12
            At this point, half of the number has been reversed.
        */
        while (x > reversedHalf) {
            /*
                Extract the last digit of x.
                Example: 
                        1221 % 10 = 1
            */
            int lastDigit = x % 10;

            /*
                Add the extracted digit to the reversed half.
                Example:
                        reversedHalf = 12 
                        lastDigit = 1 
                        
                        reversedHalf = 12 * 10 + 1 
                                     = 121 
            */
            reversedHalf = reversedHalf * 10 + lastDigit;

            /*
                Remove the last digit from x.
                Example:
                        1221 / 10 = 122
            */
            x /= 10;
        }

        /*
            There are two possible cases.

            1. Even number of digits 
                    1221
                    left = 12 
                    right reversed = 12 
            
            2. Odd number of digits 
                    12321
                    left = 12 
                    right reversed = 123 

            The middle digit does not need to be compared, so remove it from reversedHalf using / 10.
        */
        return x == reversedHalf ||
               x == reversedHalf / 10;
    }
};
