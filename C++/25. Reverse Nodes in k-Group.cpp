class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int length = 0;
        ListNode* curr = head;
        
        // Calculate the length of the linked list
        while (curr) {
            length++;
            curr = curr->next;
        }
        
        if (length < k) {
            return head;
        }
        
        ListNode* prev = nullptr;
        curr = head;
        for (int i = 0; i < k; ++i) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        if (curr) {
            head->next = reverseKGroup(curr, k);
        }
        
        return prev;
    }
};