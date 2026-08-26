#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        /*
            Roman numerals use these values:

                1000 = M
                900  = CM
                500  = D
                400  = CD
                100  = C
                90   = XC
                50   = L
                40   = XL
                10   = X
                9    = IX
                5    = V
                4    = IV
                1    = I

            The subtractive combinations are important:

                4  is IV, not IIII
                9  is IX, not VIIII
                40 is XL
                90 is XC
                400 is CD
                900 is CM
        */

        /*
            Store the Roman numeral values from largest to smallest.

            Because the values are sorted in descending order, we can
            repeatedly use the largest possible Roman numeral.
        */
        vector<int> values = {
            1000, 900, 500, 400,
            100,  90,  50,  40,
            10,   9,  5,   4,
            1
        };

        /*
            Each value has a matching Roman numeral symbol.
        */
        vector<string> symbols = {
            "M", "CM", "D", "CD",
            "C", "XC", "L", "XL",
            "X", "IX", "V", "IV",
            "I"
        };

        string result;

        /*
            Process every Roman numeral value from largest to smallest.
        */
        for (int i = 0; i < values.size(); i++) {
            /*
                A Roman numeral can be used multiple times.

                For example:

                    3000 = MMM
                    30   = XXX
                    3    = III

                Keep using the current symbol while it fits inside
                the remaining number.
            */
            while (num >= values[i]) {
                /*
                    Add the corresponding Roman numeral symbol
                    to the result.
                */
                result += symbols[i];

                /*
                    Remove that value from the number.

                    Example:

                        num = 1984
                        current value = 1000

                        num becomes 984
                    */
                num -= values[i];
            }
        }

        /*
            Once the number reaches zero, every value has been
            converted into Roman numeral symbols.
        */
        return result;
    }
};
