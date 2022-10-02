class Solution 
{
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) 
    {
        priority_queue<int> pq;
        
        for (int i = 0; i < heights.size() - 1; ++i)
        {
            int d = heights[i + 1] - heights[i];
            
            if (d > 0)
            {
                pq.push(d);
                bricks -= d;
                
                if (bricks < 0)
                {
                    if (ladders > 0)
                    {
                        --ladders;
                        bricks += pq.top();
                        pq.pop();
                    }
                    else
                    {
                        return i;
                    }
                }
            }
        }
        
        return heights.size() - 1;
    }
};