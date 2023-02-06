public class Solution 
{
    public int[] Shuffle(int[] nums, int n) 
    {
        var ans = new int[2 * n];
        
        for (int i = 0; i < n; ++i)
        {
            ans[2 * i] = nums[i];
            ans[2 * i + 1] = nums[n + i];
        }
        
        return ans;
    }
}