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
    ListNode* deleteMiddle(ListNode* head) {
        int n = 1;
        ListNode* tmp = head;
        while(tmp->next!=NULL)
        {
            tmp = tmp->next;
            n++;
        }
        if(n==1)return NULL;
        int c = 1;
        tmp = head;
        while(tmp->next!=NULL)
        {
            if(c==n/2){
                tmp->next = tmp->next->next;
                break;
            }
            tmp = tmp->next;
            c++;
            
        }
        return head;
    }
};