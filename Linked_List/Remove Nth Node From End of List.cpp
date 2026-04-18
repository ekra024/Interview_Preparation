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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr || n == 0) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        for(int i = 0; i < n; i++) {
            if(fast->next == nullptr) return head;
            fast = fast->next;
        }

        while(fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode * nextNode = slow->next;
        slow->next = nextNode->next;
        delete(nextNode);

        return dummy.next;
    }
};
