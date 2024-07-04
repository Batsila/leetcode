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
    public ListNode MergeNodes(ListNode head)
    {
        var currentNode = head;
        ListNode aggregateNode = null;

        while (currentNode != null && currentNode.next != null)
        {
            if (currentNode.val != 0)
            {
                aggregateNode.val += currentNode.val;
            }
            else
            {
                if (aggregateNode != null)
                {
                    aggregateNode.next = currentNode;
                }

                aggregateNode = currentNode;
            }

            currentNode = currentNode.next;
        }

        aggregateNode.next = null;

        return head;
    }
}