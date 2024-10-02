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
        ListNode* newHead = new ListNode();
        ListNode* slow = newHead;
        ListNode* fast = slow;
        slow->next = head;
        int x = n;
        while(x-- && fast->next!=NULL)
        {
            fast= fast->next;
        }

        while(fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        if(slow->next==NULL || slow->next->next==NULL)slow->next = NULL;
        else
            slow->next = slow->next->next;
        return newHead->next;
    }
};