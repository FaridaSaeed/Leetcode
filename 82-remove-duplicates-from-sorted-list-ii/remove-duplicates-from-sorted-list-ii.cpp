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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* tmp = head;
        ListNode* lst = new ListNode();
        lst->next = head;
        ListNode* ans = lst;
        if(head==NULL)return head;
        while(tmp!=NULL && tmp->next!=NULL)
        {
            bool f =false;
            while(tmp->next!=NULL && tmp->val==tmp->next->val)
            {
                f = true;
                tmp->next = tmp->next->next;
            }
            if(f) lst->next = tmp->next;
            else lst = tmp;
            tmp = tmp->next;
        }
        return ans->next;

    }
};