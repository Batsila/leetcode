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
    public int[] NodesBetweenCriticalPoints(ListNode head)
    {
        var minDistance = int.MaxValue;

        ListNode previousNode = head;
        ListNode currentNode = head.next;

        var firstCriticalIndex = -1;
        var previousCriticalIndex = -1;
        var currentIndex = 1;

        while (currentNode.next != null)
        {
            if (IsCritical(currentNode, previousNode))
            {
                if (previousCriticalIndex == -1)
                {
                    firstCriticalIndex = currentIndex;
                    previousCriticalIndex = currentIndex;
                }
                else
                {
                    minDistance = Math.Min(minDistance, currentIndex - previousCriticalIndex);
                    previousCriticalIndex = currentIndex;
                }
            }

            ++currentIndex;
            previousNode = currentNode;
            currentNode = currentNode.next;
        }

        if (minDistance != int.MaxValue)
        {
            return [minDistance, previousCriticalIndex - firstCriticalIndex];
        }
        else
        {
            return [-1, -1];
        }
    }

    private bool IsCritical(
        ListNode currentNode,
        ListNode previousNode)
    {
        return (currentNode.val < previousNode.val && currentNode.val < currentNode.next.val)
            || (currentNode.val > previousNode.val && currentNode.val > currentNode.next.val);
    }
}