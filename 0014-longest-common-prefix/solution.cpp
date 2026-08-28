#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        /*
            The longest common prefix is the longest sequence of characters
            that appears at the beginning of every string.
            Example:

                'flower'
                'flow'
                'flight'

            Common prefix: 
                'fl'
        */
        /*
            If the vector is empty, there are no strings to compare, so
            the common prefix is an empty string.
        */
        if (strs.empty()) {
            return "";
        }

        /*
            Start by assuming the fisrt string is the entire common prefix.
            We will shorten it whenever another string does not match.
        */
        string prefix = strs[0];

        /*
            Compsre the current prefix with every remaining string.
        */
        for (int i = 1; i < strs.size(); i++) {
            /*
                Find where the current prefix stops matching strs[i].
                'j' represents the position currently being compared.
                We stop when:
                1. We reach the end of the prefix.
                2. We reach the end of the current string.
                3. The characters at position j are different.
            */
            int j = 0;

            while (j < prefix.length() && j < strs[i].length() && prefix[j] == strs[i][j]) {
                j++;
            }

            /*
                Only keep the part of the prefix that matched.
                Exanple: 
                 prefix = 'flower'
                 stsrs[i] = 'flow'

                 Matching characters: 'flow'
                 New prefix: 'flow'
            */
            prefix = prefix.substr(0,j);

            /*
                If the prefix becomes empty, no string shares a common starting character with all previous strings.
            */
            if (prefix.empty()) {
                return "";
            }
        }

        /*
            After comparing all strings, prefix contains the longest sequence shared by every string.
        */
        return prefix;
    }
};
