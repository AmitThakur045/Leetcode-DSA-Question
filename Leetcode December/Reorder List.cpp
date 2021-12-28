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
    void reorderList(ListNode* head) {
        // Break the linked list in 2 part
        ListNode* slow = head, *fast = head->next;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2 = slow->next;
        slow->next = NULL;
        
        if(head2 == NULL)
            return;
        
        // reversing the linked list
        ListNode* curr = head2, *next, *prev = NULL;
        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head2 = prev;
        
        ListNode* head1 = head;
        ListNode* next1 = head1->next, *next2 = head2->next;
        
        while(head1 != NULL && head2 != NULL) {
            head1->next = head2;
            head2->next = next1;
            head1 = next1;
            head2 = next2;
            next1 = next1 == NULL ? NULL : next1->next;
            next2 = next2 == NULL ? NULL : next2->next;
        }
    }
};
