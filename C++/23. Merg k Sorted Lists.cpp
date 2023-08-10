class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto compare = [](const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> pq(compare);
        
        for (ListNode* list : lists) {
            if (list) {
                pq.push(list);
            }
        }
        
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (!pq.empty()) {
            ListNode* smallest = pq.top();
            pq.pop();
            
            tail->next = smallest;
            tail = tail->next;
            
            if (smallest->next) {
                pq.push(smallest->next);
            }
        }
        
        return dummy.next;
    }
};