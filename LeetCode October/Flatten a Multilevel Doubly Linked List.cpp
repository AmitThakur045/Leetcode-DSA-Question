/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten_child(Node* head) {
        Node* curr = head, *_tail = head;
        while(curr) {
            Node* child = curr->child, *_next = curr->next;
            if(child) {
                Node* _tail = flatten_child(child);
                _tail->next = _next;
                if(_next)
                    _next->prev = _tail;
                curr->next = child;
                child->prev = curr;
                curr->child = nullptr;
                curr = _tail;
            } else {
                curr = _next;
            }
            if(curr) _tail = curr;
        }
        return _tail;
    }
    
    Node* flatten(Node* head) {
        if(head) flatten_child(head);
        return head;
    }
};
