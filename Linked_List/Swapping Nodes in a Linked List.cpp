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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* slow = head;
        ListNode* fast = head;

        for (int i = 1; i < k; i++)
            fast = fast->next;

        ListNode* firstNode = fast;

        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* secondNode = slow;

        int tmp1 = firstNode->val;
        firstNode->val = secondNode->val;
        secondNode->val = tmp1;

        return head;
    }
};
