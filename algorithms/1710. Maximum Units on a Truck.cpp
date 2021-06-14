class Solution
{
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize)
    {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int> a, vector<int> b){
            return a[1] > b[1];
        });
        
        int ans = 0;
        int ind = 0;
        
        while (truckSize > 0 and ind < boxTypes.size())
        {
            if (truckSize > boxTypes[ind][0])
            {
                ans += boxTypes[ind][0] * boxTypes[ind][1];
                
                truckSize -= boxTypes[ind][0];
            }
            else
            {
                ans += truckSize * boxTypes[ind][1];
                
                truckSize = 0;
            }
            
            ++ind;
        }
        
        return ans;
    }
};