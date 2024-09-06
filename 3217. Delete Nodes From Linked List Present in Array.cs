/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution
{
    public ListNode ModifiedList(int[] nums, ListNode head)
    {
        var numsSet = nums.ToHashSet();
        var tempHead = new ListNode(-1, head);
        var previous = tempHead;
        var current = tempHead.next;

        while (current != null)
        {
            if (numsSet.Contains(current.val))
            {
                previous.next = current.next;
            }
            else
            {
                previous = current; 
            }

            current = current.next;
        }

        return tempHead.next;
    }
}