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
    public TreeNode CreateBinaryTree(int[][] descriptions)
    {
        var nodesByValue = new Dictionary<int, TreeNode>();
        var childs = new HashSet<int>();

        foreach (var description in descriptions)
        {
            TreeNode parentNode;

            if (!nodesByValue.TryGetValue(description[0], out parentNode))
            {
                parentNode = new TreeNode(description[0]);
                nodesByValue.Add(description[0], parentNode);
            }

            TreeNode childNode;

            if (!nodesByValue.TryGetValue(description[1], out childNode))
            {
                childNode = new TreeNode(description[1]);
                nodesByValue.Add(description[1], childNode);
            }

            childs.Add(childNode.val);

            if (description[2] == 1)
            {
                parentNode.left = childNode;
            }
            else
            {
                parentNode.right = childNode;
            }
        }

        var parent = descriptions.Select(x => x[0]).First(x => !childs.Contains(x));

        return nodesByValue[parent];
    }
}