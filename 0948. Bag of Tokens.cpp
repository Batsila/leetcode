class Solution
{
public:
    int bagOfTokensScore(vector<int>& tokens, int power)
    {
        int currentPower = power;
        int currentScore = 0;
        int maxScore = 0;
        
        sort(tokens.begin(), tokens.end());
        int l = 0;
        int r = tokens.size() - 1;
        
        while (l <= r 
               and (currentPower >= tokens[l]
                    or currentScore > 0))
        {
            if (currentPower >= tokens[l])
            {
                currentPower -= tokens[l];
                ++currentScore;
                ++l;
                maxScore = max(maxScore, currentScore);
            }
            else if (currentScore > 0)
            {
                currentPower += tokens[r];
                --r;
                --currentScore;
            }
        }
        
        return maxScore;
    }
};