/**
* Definition for a singly-linked list
* struct ListNode {
*   int val;
*   ListNode *next;
*   ListNode() : val(0), next(nullptr) {}
*   ListNode(int x) : val(x), next(nullptr) {}
*};
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        /*
            The linked lists store digits backwards.
            Exanple : 342 appears as:
                2 -> 4 -> 3
            Think of each node as a clue left behind at a crime scene.
            We investigate from the smallest digit to the largest.
            Just like solving a mystery one suspicious detail at a time
        */
        /*
            The dummy node is our horror-movie disposable character.
            It makes building the answer easier, but it will not survive into the final result.
        */
            ListNode dummy(0);

        /*
            'tail' points to the end of our result list.
            Think of it as the final victim in the chain:
            every new result digit gets attached behind it.
        */
            ListNode* tail = &dummy;

        /*
            'carry' = the monster hiding between calculations 
            If a digit addition produces 10 or more, the extra 1 stalks the next paitr of digits.
        */
            int carry = 0;
        /*
            Keep investigating while:
            - l1 still has digits.
            - l2 still has digits, or 
            - the carry monster is still alive.

            We must continue after both lists and if a final carry remains.
        */
            while (l1 != nullptr || l2 != nullptr || carry != 0) {
                /*
                    If a list has run out of digits, treat its missing digit as zero.
                    The shorter list has basically left the scene, but the investigation continues with the remaining clues.
                */
                int digit1 = (l1 != nullptr) ? l1->val : 0;
                int digit2 = (l2 != nullptr) ? l2->val : 0;

                /*
                    Add both digits and the carry from the previous scene 
                    Example:
                    9 + 8 + 1 = 18
                    The 8 becomes the current result digit, while the 1 becomes the next carry
                */
                int sum = digit1 + digit2 + carry;

                /*
                    The remainder gives us the digit that belongs in the current position.
                    Using 18 as the example:
                    18 % 10 = 8 

                    This is the evidence we record before moving on.
                */
                int resultDigit = sum % 10;

                /*
                    The quotient tells us whether another digit must be passed to the next calculation.
                    For 18:
                    18 / 10 = 1 

                    The carry survives to haunt the next iteration.
                */
                carry = sum / 10;

                /* 
                    Create a new node for the current digit and attach it to the end of the result.
                    Another clue has been added to the evidence board.
                */
                tail->next = new ListNode(resultDigit);
                tail = tail->next;

                /* 
                    Move to the next node in each list.
                    The detectives advance through both crime scenes at the same pace, when possible.
                */
                if(l1 != nullptr) {
                    l1 = l1->next;
                }

                if(l2 != nullptr) {
                    l2 = l2->next;
                }
            }
            
            /*
                The dummy node was only here to make the construction cleaner. 
                Like the opening victim in a thriller, it served its purpose and must not appear in the final story. 

                Return the first real node in the answer.
            */
            return dummy.next;
    }
};
