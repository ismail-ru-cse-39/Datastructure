/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//Floyd's cycle detection Algorithm from Shafayeter blog
//Find the cycle's starting point
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode* fast = head;
        
        while(fast != NULL) {
            if(fast->next != NULL && fast->next->next != NULL) {
                fast = fast->next->next;
            } else {
                return NULL;
            }
            slow = slow->next;
            
            if(fast == slow) {
                break;
            }
        }
        
        ListNode* fast2 = head;
        while(fast2 != fast) {
            fast = fast->next;
            fast2 = fast2->next;
        }
        
        return fast;
    }
};