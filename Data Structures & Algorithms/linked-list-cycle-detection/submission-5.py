# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if head is None:
            return False
            
        slow = head
        fast = slow.next

        while fast is not None and fast.next is not None:
            if fast == slow:
                return True
            
            fast = fast.next.next
            slow = slow.next
        
        return False