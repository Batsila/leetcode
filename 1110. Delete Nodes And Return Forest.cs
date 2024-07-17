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
    public IList<TreeNode> DelNodes(TreeNode root, int[] to_delete)
    {
        var toDeleteSet = new HashSet<int>(to_delete);
        var forest = new List<TreeNode>();

        var node = Dfs(root, toDeleteSet, forest);

        if (node != null)
        {
            forest.Add(node);
        }

        return forest;
    }

    private TreeNode Dfs(TreeNode node, ISet<int> toDeleteSet, IList<TreeNode> forest)
    {
        if (node != null)
        {
            node.left = Dfs(node.left, toDeleteSet, forest);
            node.right = Dfs(node.right, toDeleteSet, forest);

            if (!toDeleteSet.Contains(node.val))
            {
                return node;
            }
            else
            {
                if (node.left != null)
                {
                    forest.Add(node.left);
                }

                if (node.right != null)
                {
                    forest.Add(node.right);
                }
            }
        }

        return null;
    }
}