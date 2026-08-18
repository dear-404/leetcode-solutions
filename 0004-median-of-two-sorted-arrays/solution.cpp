#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        /*
            We always perform binary search on the smaller array.
            This keeps the time complexity at:
                0(log(min(m, n)))
            where m and n are the lengths of nums1 and nums2.
        */
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1);
    }

    int m = nums1.size();
    int n = nums2.size();

    /*
        We divide the combined arrays into two halves: 
            Left half | Right half 

        'partition1' tells us how many elements from nums1 belong on the left side.
        'partition2' is calculated so that the left side contains half of all elements.
    */
    int left = 0;
    int right = m;

    while (left <= right) {
        int partition1 = left + (right - left) / 2;
        int partition2 = (m + n + 1) / 2 - partition1;

        /*
            Find the four values immediately around the partitions.

            nums1Left = largest value on the left side of nums1
            nums1Right = smallest value on the right side of nums1
            nums2Left = largest value on the left side of nums2
            nums2Right = smallest value on the right side of nums2

            If a partition is at an array boundary, use:
            - INT_MIN for a missing left value
            - INT_MAX for a missing right value

            These sentinel values mean that boundary elements will not incorrectly affect comparisons.
        */
        int nums1Left = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
        int nums1Right = (partition1 == m) ? INT_MAX : nums1[partition1];
        int nums2Left = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
        int nums2Right = (partition2 == n) ? INT_MAX : nums2[partition2];

        /*
            The partition is correct when :
            nums1Left <= nums2Right
            nums2Left <= nums1Right

            These conditions guarantee that every element on the left side is less than or equal to every element on the right side.
        */

        if (nums1Left <= nums2Right &&
                nums2Left <= nums1Right) {

                /*
                    If the total number of elements is odd, the median
                    is the largest value on the left side.

                    The +1 in the partition calculation ensures that
                    the left side contains the extra element.
                */
                if ((m + n) % 2 == 1) {
                    return max(nums1Left, nums2Left);
                }

                /*
                    If the total number of elements is even, the median
                    is the average of:

                    - the largest value on the left side
                    - the smallest value on the right side
                */

                 int leftMax = max(nums1Left, nums2Left);
                int rightMin = min(nums1Right, nums2Right);

                return (leftMax + rightMin) / 2.0;
            }

            /*
                nums1Left is too large, which means we included too many
                elements from nums1 on the left side.

                Move the partition in nums1 to the left.
            */
            else if (nums1Left > nums2Right) {
                right = partition1 - 1;
            }

             /*
                Otherwise, nums2Left is too large.

                We need to include more elements from nums1 on the left
                side, so move the partition in nums1 to the right.
            */
            else {
                left = partition1 + 1;
            }
        }

        /*
            The input arrays are guaranteed to be sorted, so a valid
            partition must exist. This return is included as a fallback.
        */
        return 0.0;

    
    }
};
