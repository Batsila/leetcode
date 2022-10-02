class Solution
{
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed)
    {
        int p = 0;
        
        char ans;
        int mt = 0;
        
        for (int i = 0; i < releaseTimes.size(); ++i)
        {
            int t = releaseTimes[i] - p;
            
            if (t > mt or t == mt and ans < keysPressed[i])
            {
                ans = keysPressed[i];
                mt = t;
            }
            
            p = releaseTimes[i];
        }
        
        return ans;
    }
};