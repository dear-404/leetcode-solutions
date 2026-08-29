#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*
            We need to find every unique combination of three numbers whose sum equals zero.
            Example:
                num = {-1, 0, 1, 2, -1, -4}

            Valid triplets:
                {-1, -1, 2}
                {-1, 0, -1}
        */

        vector<vector<int>> result;

        /*
            Sorting is important because it allows us to:
            1. Use the two-pointer technique.
            2. Move pointers intelligently based on the sum.
            3. Skip duplicate values easily.
        */
        sort(nums.begin(), nums.end());

        /*
            Choose nums[i] as the first number in the triplet.
            We stop at nums.size() - 2 because we need two more numbers after i.
        */
        for(int i = 0; i < nums.size() - 2; i++) {
            /*
                If the current number is positive, every number after it will also be positive because the array is sorted.
                Three positive numbers cannt add up to zero.
            */
            if (nums[i] > 0) {
                break;
            }

            /*
                Skip duplicate first values.
                Without this check, the same triplet could be added multiple times.
                Example:
                    {-1, -1, 0, 1}
                Both -1 values could produce the same triplet.  
            */
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            /*
                Use two pointers to find the remaining two numbers.
                left starts immediately after i.
                right starts at the end of the array.
            */
            int left = i + 1;
            int right = nums.size() - 1;

            while(left < right) {
                //Calculate the sum of the three selected numbers.
                int sum = nums[i] + nums[left] + nums[right];

                //Case 1: We found a valid triplet.
                if (sum == 0) {
                    result.push_back({
                        nums[i],
                        nums[left],
                        nums[right]
                    });

                    /*
                        Move both pointers to search for another pair.
                        Since the current values have already been used, we move past them before checking duplicates.
                    */
                    left++;
                    right--;

                    /*
                        Skip duplicate values at the left pointer.
                        This prevents adding the same triplet again.
                    */
                    while(left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }

                    //Skip duplicate values at the right pointer.
                    while(left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }

                /*
                    Case 2: The sum is too small
                    Because the array is sorted, increasing nums[left] is the only way to make the sum larger.
                */
                else if (sum < 0) {
                    left++;
                }

                /*
                    Case 3: The sum is too large.
                    Increasing nums[right] is the only way to make the sum smaller.
                */
                else {
                    right--;
                }
            }
        }

        //Return all unique triplets whose sum is zero.
        return result;
    }
};
