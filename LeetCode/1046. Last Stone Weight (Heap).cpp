class Solution 
{
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        priority_queue heap = priority_queue(stones.begin(), stones.end());
        
        while(heap.size() > 1)
        {
            int x = heap.top();
            heap.pop();
            
            int y = heap.top();
            heap.pop();
            
            if (x - y)
            {
                heap.push(x - y);
            }
        }
        
        return heap.size() ? heap.top() : 0;
    }
};