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
    int pairSum(ListNode *head) {
    ListNode *slow = head, *fast = head, *pre = NULL, *curr = head;
    int ans = 0;
    while (fast != NULL) {
        fast = fast->next->next;
        curr = slow;
        slow = slow->next;
        curr->next = pre;
        pre = curr;
    }
    while (slow != NULL) {
        ans = max(ans, pre->val + slow->val);
        slow = slow->next;
        pre = pre->next;
    }
    return ans;
}
};