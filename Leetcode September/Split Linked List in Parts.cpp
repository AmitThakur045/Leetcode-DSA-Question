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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        for (ListNode *x = head; x; ++len, x = x->next);

        int n = len / k, r = len % k;
        vector<ListNode*> res(k);
        for (int i = 0; i < k && head; ++i) {
            res[i] = head;
            for (int j = 1; j < n + (i < r); ++j)
                head = head->next;
            ListNode *next = head->next;
            head->next = nullptr;
            head = next;
        }
        return res;
    }
};
