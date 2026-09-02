/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*
            We use two pointers:

                fast
                slow

            The distance between them will be exactly n nodes.

            Once fast reaches the end of the list, slow will be
            positioned immediately before the node that must be removed.
        */

        /*
            A dummy node is placed before the head.

            This handles edge cases cleanly, especially when the node
            being removed is the first node.

            Example:

                Original: 1 -> 2 -> 3
                Dummy:    0 -> 1 -> 2 -> 3
        */
        ListNode dummy(0);
        dummy.next = head;

        ListNode* slow = &dummy;
        ListNode* fast = &dummy;

        /*
            Move fast n steps forward.

            This creates a gap of n nodes between fast and slow.
        */
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        /*
            Move both pointers together until fast reaches the last
            node in the list.

            At that moment, slow will be immediately before the node
            that needs to be removed.
        */
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        /*
            The node after slow is the node to remove.

            Example:

                slow
                 ↓
                1 -> 2 -> 3

            If 2 must be removed:

                slow->next = 2

            We bypass it by connecting 1 directly to 3.
        */
        slow->next = slow->next->next;

        /*
            Return the updated head.

            The dummy node itself is not part of the actual list.
        */
        return dummy.next;
    }
};
