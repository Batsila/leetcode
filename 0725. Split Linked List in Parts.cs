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
    public ListNode[] SplitListToParts(ListNode head, int k)
    {
        var result = new List<ListNode>();
        var length = GetLength(head);
        var avgSize = length / k;
        var remainder = length % k;
        var current = head;
        var previous = default(ListNode);

        for (int i = 0; i < k; ++i)
        {
            result.Add(current);
            
            for (var j = 0; j < avgSize; ++j)
            {
                previous = current;
                current = current?.next;
            }

            if (remainder > 0)
            {
                previous = current;
                current = current?.next;
                --remainder;
            }

            if (previous != null)
            {
                previous.next = null;
            }
        }

        return result.ToArray();
    }

    private int GetLength(ListNode head)
    {
        var length = 0;
        var current = head;

        while (current != null)
        {
            current = current.next;
            ++length;
        }

        return length;
    }
}