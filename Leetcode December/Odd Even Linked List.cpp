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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* node1 = head, *node2 = head->next;
        ListNode* tmp = node2;
        
        while(node2 != NULL && node2->next != NULL) {
            node1->next = node2->next;
            node1 = node1->next;
            node2->next = node1->next;
            node2 = node2->next;
        }
        node1->next = tmp;
        return head;
    }
};
