class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches)
    {
        set<int> zeroLoss;
        set<int> oneLoss;
        unordered_set<int> moreLoss;
        
        for (auto match : matches)
        {
            if (oneLoss.find(match[0]) == oneLoss.end()
                and moreLoss.find(match[0]) == moreLoss.end())
            {
                zeroLoss.insert(match[0]);
            }
            
            if (zeroLoss.find(match[1]) != zeroLoss.end())
            {
                zeroLoss.erase(match[1]);
                oneLoss.insert(match[1]);
            }
            else if (oneLoss.find(match[1]) != oneLoss.end())
            {
                oneLoss.erase(match[1]);
                moreLoss.insert(match[1]);
            }
            else if (moreLoss.find(match[1]) == moreLoss.end())
            {
                oneLoss.insert(match[1]);
            }
        }
        
        return {
            vector<int>(zeroLoss.begin(), zeroLoss.end()),
            vector<int>(oneLoss.begin(), oneLoss.end())
            };
    }
};