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
    int pairSum(ListNode* head) {
        vector<int>twin;
        ListNode* slow = head->next,*fast = head->next->next;
        int n = 1,ans = 0;
        twin.push_back(head->val);
        while(slow!=NULL)
        {
            if(fast!=NULL)
            {
                twin.push_back(slow->val);
                n++;
                fast = fast->next->next;
                slow = slow->next;
            }
            if(fast==NULL)
            {
                n--;
                if(slow!=NULL)
                {
                    twin[n] += slow->val;  
                    ans = max(ans,twin[n]);
                }
                slow = slow->next;
            }
            
        }
        return ans;
    }
};