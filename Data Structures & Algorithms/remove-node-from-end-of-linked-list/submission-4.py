# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        tail = head
        length = 0
        while tail:
            length += 1
            tail = tail.next
        tail = head
        target = length - n
        count = 0
        while tail:
            if tail and target == 0:
                head = tail.next
                tail = None
                break
            if count == target - 1:
                next_node = tail.next
                tail.next = next_node.next
                next_node = None
                break
            tail = tail.next
            count += 1
        return head
