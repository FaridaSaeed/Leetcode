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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head->next) return head;
        if(left==right) return head;

        ListNode *l1=new ListNode(0), *l2=head;
        l1->next=head;
        head=l1;
        int k = right-left+1;

        while(--left){
            l1=l2;
            l2=l2->next;
        }

        ListNode *prev=NULL, *curr=l2, *front=NULL;
        while(k--){
            front = curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }

        l1->next=prev;
        l2->next=curr;

        return head->next;
    }
};