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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL ||head->next==NULL)return head;
        ListNode* odd = head , *even = head->next;
        ListNode* tmpodd = odd , *tmpev = even;
        while(tmpodd->next != NULL && tmpev->next != NULL)
        {
            tmpodd->next = tmpev->next;
            tmpodd = tmpodd->next;
            tmpev->next = tmpodd->next;
            tmpev = tmpev->next;
        }
        tmpodd->next = even;
        return odd;
    }
};