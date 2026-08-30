#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        /*
            Each digit maps to a group of letters, like on an
            old-fashioned phone keypad:

                2 -> abc
                3 -> def
                4 -> ghi
                5 -> jkl
                6 -> mno
                7 -> pqrs
                8 -> tuv
                9 -> wxyz

            Example:

                digits = "23"

                Possible combinations include:

                    ad, ae, af
                    bd, be, bf
                    cd, ce, cf
        */

        /*
            If digits is empty, there are no combinations to create.
        */
        if (digits.empty()) {
            return {};
        }

        /*
            Store the letters associated with each digit.

            The index in this vector matches the digit:

                keypad[2] = "abc"
                keypad[3] = "def"
        */
        vector<string> keypad = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        vector<string> result;

        /*
            This string stores the combination currently being built.

            For digits = "23":

                Start: ""
                Choose from 2: "a"
                Choose from 3: "ad"
                Save: "ad"
        */
        string currentCombination;

        /*
            Begin backtracking from the first digit.
        */
        buildCombinations(
            digits,
            keypad,
            0,
            currentCombination,
            result
        );

        return result;
    }

private:
    void buildCombinations(
        const string& digits,
        const vector<string>& keypad,
        int index,
        string& currentCombination,
        vector<string>& result
    ) {
        /*
            Base case:

            If index reaches the end of digits, we have selected
            one letter for every digit.

            The current combination is complete, so save it.
        */
        if (index == digits.length()) {
            result.push_back(currentCombination);
            return;
        }

        /*
            Convert the current digit character into an integer.

            Example:

                digits[index] = '7'

                '7' - '0' = 7
        */
        int digit = digits[index] - '0';

        /*
            Try every letter associated with the current digit.
        */
        for (char letter : keypad[digit]) {
            /*
                Choose:

                Add the letter to the combination currently being built.
            */
            currentCombination.push_back(letter);

            /*
                Explore:

                Move to the next digit and continue building.
            */
            buildCombinations(
                digits,
                keypad,
                index + 1,
                currentCombination,
                result
            );

            /*
                Undo the choice:

                Remove the last letter so that we can try the next
                possible letter for this digit.

                This is the backtracking step.
            */
            currentCombination.pop_back();
        }
    }
};
