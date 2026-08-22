#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        /*
            The function must convert a string into a 32-bit signed integer.
            Rules:

            1. Ignore leading whitespace.
            2. Check for an optional '+' or '-' sign.
            3. Read consecutive digits.
            4. Stop at the first non-digit character.
            5. Clamp values outside the integer range.

            Valid range:
                INT_MIN = -2,147,483,648
                INT_MAX = 2,147,483,647
        */

        int index = 0;
        int n = s.length();

        /*
            Step 1: Skip leading whitespace.
            We only skip spaces before the number. Once a non-space character is found, the conversion process
            begins.
        */
        while (index < n && s[index] == ' ') {
            index++;
        }

        /*
            Step 2: Determine the sign.
            By default, we assume the number is positive.
        */
        int sign = 1;

        if (index < n && (s[index] == '+' || s[index] == '-')) {
            if(s[index] == '-') {
                sign = -1;
            }

            index++;
        }

        /*
            Step 3: Build the number digit by digit.
            We use a long long temporarily so that we can safely compare the number against INT_MAX and INT_MIN 
            while constructing it.
        */
        long long number = 0;

        while (index < n && s[index] >= '0' && s[index] <= '9') {
            /*
                Convert the character digit into its numeric value.
                Example:
                    '7' - '0' = 7
            */
            int digit = s[index] - '0';

            /*
                Add the new digit to the number.
                Example:
                    number = 42
                    digit = 7

                    number = 42 * 10 + 7
                           = 427
            */
            number = number * 10 + digit;

            /*
                Apply the sign temporarily and check whether the value has exceeded the 32-bit integer range.
                If it has, return the appropriate boundary value;
            */
            if (sign == 1 && number > INT_MAX) {
                return INT_MAX;
            }

            if (sign == -1 && -number < INT_MIN) {
                return INT_MIN;
            }

            // Move to the next character.
            index++;
        }

        /*
            Step 4: Apply the sign and return the result.
            If no digit were found, number is still 0, which is the required result.
        */
        return static_cast<int>(sign * number);
    }
};
