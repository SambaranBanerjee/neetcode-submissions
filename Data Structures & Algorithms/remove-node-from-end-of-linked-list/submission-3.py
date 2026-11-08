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
        count = 0

        while tail:
            if tail is not None and length - n == 0:
                tail = tail.next
                head = tail
                break
            if count == length - n - 1:
                curr = tail.next
                prev = tail

                prev.next = curr.next
                curr = None
                break
            tail = tail.next
            count += 1
        
        return head
                
