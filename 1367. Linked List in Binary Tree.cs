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
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution
{
    public bool IsSubPath(ListNode head, TreeNode root)
    {
        if (root != null)
        {
            if (CheckPath(head, root))
            {
                return true;
            }
            else
            {
                return IsSubPath(head, root.left) || IsSubPath(head, root.right);
            }
        }
        else
        {
            return false;
        }
    }

    private bool CheckPath(ListNode head, TreeNode root)
    {
        if (head != null)
        {
            if (root != null)
            {
                if (root.val == head.val)
                {
                    return CheckPath(head.next, root.left) || CheckPath(head.next, root.right);
                }
            }

            return false;
        }

        return true;
    }
}