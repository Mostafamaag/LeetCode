# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:

        count = set(nums)
    
        cur = ListNode(0, head)
        head = cur

        while cur.next:
            if cur.next.val in count:
                cur.next = cur.next.next
            else:
                cur = cur.next



        return head.next

        
