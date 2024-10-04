public class Solution
{
    public long DividePlayers(int[] skill)
    {
        long totalChemistry = 0;
        var sum = skill.Sum();
        var teamCount = skill.Length / 2;

        if (sum % teamCount == 0)
        {
            var teamSum = sum / teamCount;
            Array.Sort(skill);

            for (int i = 0; i < teamCount; ++i)
            {
                if (skill[i] + skill[^(i + 1)] == teamSum)
                {
                    totalChemistry += skill[i] * skill[^(i + 1)];
                }
                else
                {
                    totalChemistry = -1;
                    break;
                }
            }
        }
        else
        {
            totalChemistry = -1;
        }

        return totalChemistry;
    }
}