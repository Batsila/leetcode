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
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) 
    {
        ListNode p = l1;
        ListNode q = l2;
        ListNode ans = null;
        ListNode c = null;
        
        int m = 0;
        
        while (p != null || q != null)
        {
            int x = p != null ? p.val : 0;
            int y = q != null ? q.val : 0;
            
            int sum = (x + y + m) % 10;
            m = (x + y + m) / 10;
            
            if (c == null)
            {
                c = new ListNode(sum);
                ans = c;
            }
            else
            {
                c.next = new ListNode(sum);
                c = c.next;
            }
            
            p = p?.next;
            q = q?.next;
        }
        
        if (m > 0)
        {
            c.next = new ListNode(m);
        }
        
        return ans;
    }
}