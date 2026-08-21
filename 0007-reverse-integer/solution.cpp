#include <cstring>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        /*
            We build the reversed number one digit at a time.
            Example:
            x = 123
            Last digit: 3
            Then:       2
            Then:       1
            Result: 321
        */

        int reversedNumber = 0;

        // Continue until every digit has been removed from x.
        while(x != 0) {
            /*
                The modulo operator gives us the last digit.
                Examples:
                    123 % 10 = 3
                    -123 % 10 = -3
            */
            int digit = x % 10;

            /*
                Remove the last digit from x.
                Integer division truncates toward zero:
                    123 / 10 = 12
                    -123 / 10 = -12
            */
            x /= 10;

            /*
                Before calculating:
                    reversedNumber * 10 + digit

                we must check whether multiplying by 10 would cause a 
                signed 32-bit integer overflow.

                INT_MAX is:
                    2,147,483,647

                INT_MIN is:
                    -2,147,483,648
            */

            /*
                Check for positive overflow.

                If reversedNumber is always greater than INT_MAX / 10,
                multiplying it by 10 would overflow.

                If it equals INT-MAX / 10, the new digit must not be 
                greater than the final allowed digit, which is 7.
            */
            if (reversedNumber > INT_MAX / 10 || (reversedNumber == INT_MAX /10 && digit > 7 )) {
                return 0;
            }

            /*
                Check for negative overflow.
                If reversedNumber is already less than INT_MIN / 10, multiplying it by 10 would overflow.

                If it equals INT_MIN / 10, the new digit must not be smaller than -8.
            */
            if (reversedNumber < INT_MIN / 10 || (reversedNumber == INT_MIN / 10 && digit < -8)) {
                return 0;
            }

            /*
                Shift the current reversed number left by on edecimal place and append the new digit.
                Example:
                    reversedNumber = 12 
                    digit = 3

                    12 * 10 + 3 = 123
            */
            reversedNumber = reversedNumber * 10 + digit;
        }
        
        // Return the reversed number if no overflow occurred.
        return reversedNumber;
    }
};
