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
    private int[] dx = { 0, 1, 0, -1 };
    private int[] dy = { 1, 0, -1, 0 };

    public int[][] SpiralMatrix(int m, int n, ListNode head)
    {
        var matrix = Enumerable.Range(0, m).Select(x => Enumerable.Range(0, n).Select(y => -1).ToArray()).ToArray();
        var currentNode = head;
        var direction = 0;
        var x = 0;
        var y = 0;

        while (currentNode != null)
        {
            matrix[x][y] = currentNode.val;
            var newX = x + dx[direction];
            var newY = y + dy[direction];

            if (newX < 0 || newX >= m
                || newY < 0 || newY >= n
                || matrix[newX][newY] != -1)
            {
                ++direction;
                direction %= 4;
            }

            x += dx[direction];
            y += dy[direction];

            currentNode = currentNode.next;
        }

        return matrix;
    }
}