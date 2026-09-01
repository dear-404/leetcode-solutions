#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        /*
            We need to find every unique group of four numbers
            whose sum equals target.

            Example:

                nums = {1, 0, -1, 0, -2, 2}
                target = 0

            Valid groups include:

                {-2, -1, 1, 2}
                {-2,  0, 0, 2}
                {-1,  0, 0, 1}
        */

        vector<vector<int>> result;

        /*
            Sorting helps us:

            1. Use the two-pointer technique.
            2. Skip duplicate values.
            3. Move pointers based on whether the sum is too small
               or too large.
        */
        sort(nums.begin(), nums.end());

        int n = nums.size();

        /*
            Choose the first number.
        */
        for (int i = 0; i < n - 3; i++) {
            /*
                Skip duplicate values for the first position.
                This prevents duplicate quadruplets.
            */
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            /*
                Choose the second number.
            */
            for (int j = i + 1; j < n - 2; j++) {
                /*
                    Skip duplicate values for the second position.
                */
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                /*
                    The remaining two numbers will be found using
                    the two-pointer technique.
                */
                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    /*
                        Use long long for the sum.

                        Four integers can add up to a value outside
                        the normal int range, so long long prevents
                        arithmetic overflow.
                    */
                    long long sum =
                        static_cast<long long>(nums[i]) +
                        nums[j] +
                        nums[left] +
                        nums[right];

                    /*
                        We found a valid quadruplet.
                    */
                    if (sum == target) {
                        result.push_back({
                            nums[i],
                            nums[j],
                            nums[left],
                            nums[right]
                        });

                        /*
                            Move both pointers to search for another
                            possible pair.
                        */
                        left++;
                        right--;

                        /*
                            Skip duplicate values on the left.
                        */
                        while (left < right &&
                               nums[left] == nums[left - 1]) {
                            left++;
                        }

                        /*
                            Skip duplicate values on the right.
                        */
                        while (left < right &&
                               nums[right] == nums[right + 1]) {
                            right--;
                        }
                    }

                    /*
                        The sum is too small.

                        Since the array is sorted, increase nums[left]
                        to make the sum larger.
                    */
                    else if (sum < target) {
                        left++;
                    }

                    /*
                        The sum is too large.

                        Decrease nums[right] to make the sum smaller.
                    */
                    else {
                        right--;
                    }
                }
            }
        }

        return result;
    }
};
