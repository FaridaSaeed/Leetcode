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
    ListNode* partition(ListNode* head, int x) {
        vector<int>v;
        ListNode* newNode = head;
        while(newNode!=NULL)
        {
            if(newNode->val<x)v.push_back(newNode->val);
            newNode = newNode->next;
        }
        newNode = new ListNode(0);
        ListNode* ans = newNode;
        for(auto i:v)
        {
            newNode->next = new ListNode(i);
            newNode = newNode->next;
        }
        while(head!=NULL)
        {
            if(head->val>=x){
                newNode->next= new ListNode(head->val);
                newNode = newNode->next;
            }
            head = head->next;
        }
        return ans->next;
    }
};