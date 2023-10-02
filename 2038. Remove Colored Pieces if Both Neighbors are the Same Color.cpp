class Solution
{
public:
    bool winnerOfGame(string colors)
    {
        int a = 0;
        int b = 1;

        for (int i = 1; i < colors.size(); ++i)
        {
            if (colors[i] == colors[i - 1] and colors[i] == colors[i + 1])
            {
                if (colors[i] == 'A')
                {
                    ++a;
                }
                else
                {
                    ++b;
                }
            }
        }

        return a >= b;
    }
};