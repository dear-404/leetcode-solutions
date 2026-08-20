#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        /*
            If there is only one row, or if the number of rows is greater than or equal to >= the string length,
            no zigzag movement is needed 
        */

        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        /*
            Each string in this vector represents one row of the zigzag pattern.
            For example, with 3 rows, the string '"PAYPALISHIRING"
            is arranged like this:

                P   A   H   N
                A P L S I G
                Y   I   R

            rows[0] stores the first row.
            rows[1] stores the second row.
            rows[2] stores the third row.
        */
        vector<string> rows(numRows);

        /*
            currentRow tells us where to place the next character.
            goingDown tells us whether we are currently moving:

                downward    : 0 -> 1 -> 2
                upward      : 2 -> 1 -> 0
        */
        int currentRow = 0;
        bool goingDown = true;

        // Process every character in the input string
        for (char character : s) {
            // Add the current character to the appropriate row
            rows[currentRow] += character;

            /*
                When we reach the top row, we must start moving down.
                When we reach the bottom row, we must start moving up.
                These turning points create the zigzag shape.
            */
            if(currentRow == 0) {
                goingDown = true;
            } else if (currentRow == numRows - 1) {
                goingDown = false;
            }

            /*
                Move to the next row.
                If goingDown = true: move one row downward
                Otherwise : move one row upward
            */
            if (goingDown) {
                currentRow++;
            } else {
                currentRow--;
            }
        }

        /*
            The problem asks us to read the zigzag pattern row by row.
            Combine all rows into one final string.
        */
        string result;

        for (const string& row : rows) {
            result += row;
        }

        return result;
    }
};
