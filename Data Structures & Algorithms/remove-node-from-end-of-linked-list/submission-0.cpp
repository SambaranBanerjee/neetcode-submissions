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
        if (head == nullptr) {
            return head;
        }
        if (head->next == nullptr) {
            head = nullptr;
            return head;
        }
        ListNode* curr = head;
        int listLength = 0; 
        while (curr != nullptr) {
            listLength++;
            curr = curr->next;
        }
        int removingPos = listLength - n;
        if (removingPos == 0) {
            return head->next;
        }
        int currLen = 0;
        ListNode* move = head;
        while (move != nullptr && currLen != removingPos - 1) {
            currLen++;
            move = move->next;
        }
        move->next = move->next->next;
        return head;
    }
};
