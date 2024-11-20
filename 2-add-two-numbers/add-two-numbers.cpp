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
        ListNode* ans = new ListNode(0);
        ListNode* res = ans;
        int rem = 0;
        while(l1!=NULL &&l2!=NULL)
        {
            int sum = l1->val + l2->val;
            sum+=rem;
            if(sum>=10){
                sum-=10;
                rem = 1;
            }
            else rem = 0;
            ans->next = new ListNode(sum);
            ans = ans->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=NULL)
        {
            int sum = l1->val;
            sum+=rem;
            cout<<sum<<' ';
            if(sum>=10){
                sum-=10;
                rem = 1;
            }
            else rem = 0;
            ans->next = new ListNode(sum);
            l1 = l1->next;
            ans = ans->next;
        }
        while(l2!=NULL)
        {
            int sum = l2->val;
            sum+=rem;
            if(sum>=10){
                sum-=10;
                rem = 1;
            }
            else rem = 0;
            ans->next = new ListNode(sum);
            l2 = l2->next;
            ans = ans->next;
        }
        if(rem)ans->next = new ListNode(rem);
        return res->next;
    }
};