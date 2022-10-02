class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList)
    {
        int firstInd = 0;
        int secondInd = 0;
        
        vector<vector<int>> ans;
        
        while (firstInd < firstList.size() and secondInd < secondList.size())
        {
            int l = max(firstList[firstInd][0], secondList[secondInd][0]);
            int r = min(firstList[firstInd][1], secondList[secondInd][1]);
            
            if (l <= r)
            {
                ans.push_back({ l, r });
            }
            
            if (firstList[firstInd][1] < secondList[secondInd][1])
            {
                ++firstInd;
            }
            else
            {
                ++secondInd;
            }
        }
        
        return ans;
    }
};