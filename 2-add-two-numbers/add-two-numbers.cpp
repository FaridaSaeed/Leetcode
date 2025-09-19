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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* ans = new ListNode();
       ListNode *res = ans; 
       int rem = 0,sum = 0;
       while(l1!=NULL && l2!=NULL)
       {
            sum = l1->val + l2->val;
            sum +=rem;
            rem = 0;
            if(sum>=10)
            {
                sum -=10;
                rem = 1;
            }
            ans->next = new ListNode();
            ans->next->val = sum;
            ans = ans->next;
            l1 = l1->next;
            l2 = l2->next;
       }
       while(l1!=NULL)
       {
            sum = l1->val;
            sum +=rem;
            rem = 0;
            if(sum>=10)
            {
                sum -=10;
                rem = 1;
            }
            ans->next = new ListNode();
            ans->next->val = sum;
            ans = ans->next;
            l1 = l1->next;
       }
       while(l2!=NULL)
       {
            sum = l2->val;
            sum +=rem;
            rem = 0;
            if(sum>=10)
            {
                sum -=10;
                rem = 1;
            }
            ans->next = new ListNode();
            ans->next->val = sum;
            ans = ans->next;
            l2 = l2->next;
       }
       if(rem)ans->next = new ListNode(rem);
       return res->next;

    }
};