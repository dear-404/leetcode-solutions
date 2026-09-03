#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        /*
            A string of brackets is valid when:

            1. Every opening bracket has a matching closing bracket.
            2. Brackets close in the correct order.
            3. No closing bracket appears without a matching opening bracket.

            Examples:

                "()"       -> valid
                "()[]{}"   -> valid
                "(]"        -> invalid
                "([)]"      -> invalid
                "{[]}"      -> valid
        */

        /*
            The stack stores opening brackets that are waiting
            for their matching closing brackets.

            A stack is appropriate because the most recently opened
            bracket must be closed first.

            This is the same idea as nested boxes:
            the last box opened must be the first box closed.
        */
        stack<char> openingBrackets;

        /*
            This map tells us which opening bracket belongs to each
            closing bracket.
        */
        unordered_map<char, char> matchingBracket = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        /*
            Process each bracket from left to right.
        */
        for (char bracket : s) {
            /*
                If the bracket is an opening bracket, place it on
                the stack and wait for its matching closing bracket.
            */
            if (bracket == '(' ||
                bracket == '[' ||
                bracket == '{') {

                openingBrackets.push(bracket);
            } else {
                /*
                    A closing bracket cannot be valid if there is no
                    opening bracket waiting for it.
                */
                if (openingBrackets.empty()) {
                    return false;
                }

                /*
                    Look at the most recently opened bracket.
                */
                char mostRecentOpening = openingBrackets.top();

                /*
                    Check whether it matches the current closing bracket.

                    Examples:

                        ')' must match '('
                        ']' must match '['
                        '}' must match '{'
                */
                if (mostRecentOpening != matchingBracket[bracket]) {
                    return false;
                }

                /*
                    The pair is valid, so remove the opening bracket
                    from the stack.
                */
                openingBrackets.pop();
            }
        }

        /*
            Every opening bracket must eventually be closed.

            Therefore, the stack must be empty at the end.
        */
        return openingBrackets.empty();
    }
};
