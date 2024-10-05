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
        if(left==right)return head;
        ListNode* tmp = head;
        int ind = 1;
        while(tmp!=NULL && tmp->next!=NULL && ind+1<left)
        {
            tmp = tmp->next;
            ind++;
        }
        ListNode* tmp2 = tmp;
        deque<int>s;
        if(left==1)s.push_back(tmp->val);
        while(tmp2->next!=NULL && ind<right)
        {
            tmp2 = tmp2->next;
            s.push_front(tmp2->val);
            ind++;
        }
        ListNode* res =new ListNode(s[0]);
        ListNode* tmpres = res;
        for(int i=1;i<s.size();i++)
        {
            tmpres->next = new ListNode(s[i]);
            tmpres = tmpres->next;
        }
        if(tmp2!=NULL && tmp2->next!=NULL)
            tmpres->next = tmp2->next;
        
        if(left==1)head = res;
        else
            tmp->next = res;
        return head;
    }
};