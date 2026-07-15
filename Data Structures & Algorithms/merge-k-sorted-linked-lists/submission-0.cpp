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
    struct CompareNodes {
        bool operator() (ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        priority_queue<ListNode*, vector<ListNode*>, CompareNodes> min_heap;
        for (ListNode* head : lists) {
            if (head != nullptr) {
                min_heap.push(head);
            }
        }
        while (!min_heap.empty()) {
            ListNode* smallest = min_heap.top();
            min_heap.pop();

            tail->next = smallest;
            tail = tail->next;

            if (smallest->next != nullptr) {
                min_heap.push(smallest->next);
            }
        }
        return dummy.next;
    }
};
