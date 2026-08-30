#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        /*
            We need to choose three numbers whose sum is as close
            as possible to target.

            Example:

                nums = {-1, 2, 1, -4}
                target = 1

                Possible sums include:
                    -1 + 2 + 1 = 2
                    -1 + 2 - 4 = -3
                    ...

                The closest sum is 2.
        */

        /*
            Sorting allows us to use the two-pointer technique.

            It also makes it possible to determine whether a sum is
            too small or too large and move the correct pointer.
        */
        sort(nums.begin(), nums.end());

        /*
            Start with the first three numbers as our initial answer.

            This guarantees that closestSum contains a valid sum
            before the search begins.
        */
        int closestSum = nums[0] + nums[1] + nums[2];

        /*
            Choose nums[i] as the first number in the triplet.

            We stop at nums.size() - 2 because two more numbers are
            needed after i.
        */
        for (int i = 0; i < nums.size() - 2; i++) {
            /*
                The two pointers search for the best pair that works
                with nums[i].
            */
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                /*
                    Calculate the current three-number sum.
                */
                int currentSum =
                    nums[i] + nums[left] + nums[right];

                /*
                    Calculate how far the current sum is from target.
                    A smaller difference means a closer answer.
                */
                int currentDifference =
                    abs(currentSum - target);

                int closestDifference =
                    abs(closestSum - target);

                /*
                    Update the answer if the current sum is closer
                    to target than the best sum found so far.
                */
                if (currentDifference < closestDifference) {
                    closestSum = currentSum;
                }

                /*
                    If we find the exact target, it is impossible to
                    get any closer, so we can return immediately.
                */
                if (currentSum == target) {
                    return currentSum;
                }

                /*
                    If the sum is too small, move left forward.

                    Because the array is sorted, increasing nums[left]
                    can increase the sum.
                */
                if (currentSum < target) {
                    left++;
                }

                /*
                    If the sum is too large, move right backward.

                    Because the array is sorted, decreasing nums[right]
                    can decrease the sum.
                */
                else {
                    right--;
                }
            }
        }

        /*
            Return the sum closest to target.
        */
        return closestSum;
    }
};
