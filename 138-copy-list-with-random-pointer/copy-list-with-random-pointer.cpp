class Solution {
public:
    unordered_map<Node*,Node*>mp;
    Node* copyRandomList(Node* head) {
        if(!head)return head;
        Node* newList = new Node(head->val);
        mp[head] = newList;
        newList->next = copyRandomList(head->next);
        newList->random = mp[head->random];
        return newList;
    }
};