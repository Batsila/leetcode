public class Solution
{
    public IList<int> LexicalOrder(int n)
    {
        var result = new List<int>();

        foreach (var digit in Enumerable.Range(1, 9))
        {
            Dfs(digit, n, result);
        }

        return result;
    }

    private void Dfs(
        int current,
        int n,
        List<int> result)
    {
        if (current <= n)
        {
            result.Add(current);

            foreach (var digit in Enumerable.Range(0, 10))
            {
                Dfs(current * 10 + digit, n, result);
            }
        }
    } 
}