public class Solution
{
    public IList<IList<int>> CombinationSum2(int[] candidates, int target)
    {
        var result = new List<IList<int>>();

        Array.Sort(candidates);
        Backtrack(candidates, 0, [], target, result);

        return result;
    }

    private static void Backtrack(
        int[] candidates,
        int index,
        IList<int> combination,
        int target,
        IList<IList<int>> result)
    {
        if (target == 0)
        {
            result.Add(new List<int>(combination));
        }
        else if (target > 0)
        {
            for (int i = index; i < candidates.Length && target >= candidates[i]; ++i)
            {
                if (i == index || candidates[i] != candidates[i - 1])
                {
                    combination.Add(candidates[i]);
                    Backtrack(candidates, i + 1, combination, target - candidates[i], result);
                    combination.RemoveAt(combination.Count - 1);
                }
            }
        }
    }
}