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
        var s1 = new Stack<int>();
        var s2 = new Stack<int>();
        
        var p1 = l1;
        
        while (p1 != null)
        {
            s1.Push(p1.val);
            
            p1 = p1?.next;
        }
        
        var p2 = l2;
        
        while (p2 != null)
        {
            s2.Push(p2.val);
            
            p2 = p2?.next;
        }
        
        var s = new Stack<int>();
        var c = 0;
        
        while (s1.Count() > 0 || s2.Count() > 0)
        {
            var x = s1.Count() > 0 ? s1.Pop() : 0;
            var y = s2.Count() > 0 ? s2.Pop() : 0;
            
            s.Push((x + y + c) % 10);
            c = (x + y + c) / 10;
        }
        
        if (c > 0)
        {
            s.Push(c);
        }
        
        ListNode ans = null;
        ListNode p = null;
        
        while (s.Count() > 0)
        {
            if (ans == null)
            {
                ans = p;
            }
            
            if (p == null)
            {
                p = new ListNode(s.Pop());
            }
            else
            {
                p.next = new ListNode(s.Pop());
                p = p.next;
            }
        }
        
        if (ans == null)
        {
            ans = p;
        }
        
        return ans;
    }
}