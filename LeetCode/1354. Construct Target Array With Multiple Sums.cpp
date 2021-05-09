class Solution 
{
public:
    bool isPossible(vector<int>& target) 
    {
        if (target.size() == 1)
        {
            return target[0] == 1;
        }
        
        long long sum = 0;
        priority_queue<long long> pq;
        
        for (int n : target)
        {
            sum += n;
            pq.push(n);
        }
        
        while (pq.top() > 1)
        {
            long long maxn = pq.top();
            pq.pop();
            
            long long r = sum - maxn;
            
            if(r >= maxn or r == 0)
            {
                return false;
            }
                    
            pq.push(maxn % r);
            sum -= maxn - maxn % r;
        }
        
        return true;
    }
};