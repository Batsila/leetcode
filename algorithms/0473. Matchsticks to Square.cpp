class Solution
{
    vector<int> nums;
    int side;
    int sides[4];
public:
    bool makesquare(vector<int>& matchsticks)
    {
        nums = matchsticks;
        
        int sum = 0;
        for (int n : nums)
        {
            sum += n;
        }
        
        if (sum % 4)
        {
            return false;
        }
        
        side = sum / 4;
        
        return help(0);
    }
    
    bool help(int ind)
    {
        if (ind < nums.size())
        {
            int num = nums[ind++];
            
            for (int i = 0; i < 4; ++i)
            {
                if (sides[i] + num <= side)
                {
                    sides[i] += num;
                    
                    if (help(ind))
                    {
                        return true;
                    }
                    
                    sides[i] -= num;
                }
            }
            
            return false;
        }
        else
        {
            return sides[0] == sides[1] and sides[1] == sides[2] and sides[2] == sides[3];
        }
    }
};