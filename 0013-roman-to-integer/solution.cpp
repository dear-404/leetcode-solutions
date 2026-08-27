#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        /*
            Map each Roman numeral symbol to its integer value.

                I = 1
                V = 5
                X = 10
                L = 50
                C = 100
                D = 500
                M = 1000

            The unordered_map lets us quickly look up the value
            of each Roman numeral character.
        */
        unordered_map<char, int> value = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int result = 0;

        /*
            Process each character from left to right.
        */
        for (int i = 0; i < s.length(); i++) {
            /*
                Get the value of the current Roman numeral.
            */
            int currentValue = value[s[i]];

            /*
                If the next symbol is larger than the current symbol,
                subtract the current value.

                Example:

                    IV

                    I = 1
                    V = 5

                    Since 5 is greater than 1:
                    result = result - 1 + 5 = 4
            */
            if (i + 1 < s.length() &&
                currentValue < value[s[i + 1]]) {
                result -= currentValue;
            } else {
                /*
                    Otherwise, add the current value normally.

                    Example:

                        VI

                        V = 5
                        I = 1

                        result = 5 + 1 = 6
                */
                result += currentValue;
            }
        }

        /*
            Return the final integer value.
        */
        return result;
    }
};
