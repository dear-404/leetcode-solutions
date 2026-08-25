#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        /*
            Each pair of lines forms a container.

            The amount of water a container can hold is:

                width × shorter height

            Why the shorter height?

            Water would spill over the shorter line, so the taller
            line cannot increase the container's height by itself.

            Formula:

                area = (right - left) *
                       min(height[left], height[right])
        */

        // Start with the widest possible container.
        int left = 0;
        int right = height.size() - 1;

        // Stores the largest area found so far.
        int largestArea = 0;

        /*
            Continue while the two pointers have not crossed.
        */
        while (left < right) {
            /*
                Calculate the width between the two lines.
            */
            int width = right - left;

            /*
                The shorter line determines the water level.
            */
            int containerHeight = min(height[left], height[right]);

            /*
                Calculate how much water this pair of lines can hold.
            */
            int currentArea = width * containerHeight;

            /*
                Keep the largest container found so far.
            */
            largestArea = max(largestArea, currentArea);

            /*
                The shorter line is limiting the container.

                Moving the taller line would reduce the width but would
                not improve the height, because the shorter line is still
                the limiting boundary.

                Therefore, move the pointer pointing to the shorter line,
                hoping to find a taller line.
            */
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        /*
            Return the maximum area discovered.
        */
        return largestArea;
    }
};
