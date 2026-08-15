#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Stores each number and its index
        unordered_map<int, int> numToIndex;

        for (int i = 0; i < nums.size(); i++) {
            // Number needed to reach the target
            int complement = target - nums[i];

            // Check whether the complement was seen earlier
            if (numToIndex.find(complement) != numToIndex.end()) {
                return {
                    numToIndex[complement],
                    i
                };
            }

            // Store the current number and its index
            numToIndex[nums[i]] = i;
        }

        // Return an empty vector if no solution is found
        return {};
    }
};
