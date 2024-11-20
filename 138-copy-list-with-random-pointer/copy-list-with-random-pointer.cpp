/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*>mp;
    Node* copyRandomList(Node* head) {
        if(head==NULL)return head;
        Node* newHead = new Node(head->val);
        mp[head] = newHead;
        newHead->next = copyRandomList(head->next);
        newHead->random = mp[head->random];
        return newHead;
    }
};