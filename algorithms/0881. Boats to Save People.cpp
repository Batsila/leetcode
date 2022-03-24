class Solution
{
public:
    int numRescueBoats(vector<int>& people, int limit)
    {
        sort(people.begin(), people.end());
        
        int ans = 0;
        int l = 0;
        int r = people.size() - 1;
        
        while (r >= l)
        {
            if (people[r] + people[l] <= limit)
            {
                ++l;
            }
            
            --r;
            ++ans;
        }
        
        return ans;
    }
};