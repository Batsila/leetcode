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
    private List<int> nodes = new List<int>();
        
    public TreeNode BalanceBST(TreeNode root) 
    {
        Dfs(root);
        
        return CreateBalancedBST(0, nodes.Count - 1);
    }
    
    public TreeNode CreateBalancedBST(int left, int right)
    {
        if (left <= right)
        {
            int mid = (left + right) / 2;
        
            var leftNode = CreateBalancedBST(left, mid - 1);
            var rightNode = CreateBalancedBST(mid + 1, right);
        
            return new TreeNode(nodes[mid], leftNode, rightNode);
        }
        else
        {
            return null;
        }
    }
    
    public void Dfs(TreeNode node)
    {
        if (node != null)
        {
            Dfs(node.left);
            nodes.Add(node.val);
            Dfs(node.right);
        }
    }
}