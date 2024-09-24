public class Solution
{
    public int LongestCommonPrefix(int[] arr1, int[] arr2)
    {
        var prefixies = new HashSet<int>();

        foreach (var num in arr1)
        {
            foreach (var prefix in GetPrefixies(num))
            {
                prefixies.Add(prefix);
            }
        }

        var result = 0;

        foreach (var num in arr2)
        {
            foreach (var prefix in GetPrefixies(num))
            {
                if (GetPrefixLength(prefix) > result)
                {
                    if (prefixies.Contains(prefix))
                    {
                        result = Math.Max(result, GetPrefixLength(prefix));
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
        }

        return result;
    }

    private static int GetPrefixLength(int prefix)
    {
        var result = 0;

        while (prefix > 0)
        {
            prefix /= 10;
            ++result;
        }

        return result;
    }

    private static IEnumerable<int> GetPrefixies(int num)
    {
        while (num > 0)
        {
            yield return num;
            num /= 10;
        }
    }
}