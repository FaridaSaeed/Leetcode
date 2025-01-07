class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return head;
        Node* tmp,*original,*newList;
        original = head;
        while(head)
        {
            tmp = new Node(head->val);
            tmp->next = head->next;
            head->next = tmp;
            head = tmp->next;
        }
        head = original;
        while(head)
        {
            tmp = head->next;
            if(head->random)
                tmp->random = head->random->next;
            head = tmp->next;
        }
        head = original;
        tmp = head->next;
        newList = tmp;
        while(head)
        {
            head->next = tmp->next;
            head = head->next;
            if(head)
                tmp->next = head->next;
            tmp = tmp->next;
        }
        return newList;
    }
};