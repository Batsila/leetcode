class FreqStack
{
    map<int, int> freq;
    map<int, stack<int>> group;
    int maxFreq = 0;
public:  
    void push(int val)
    {
        ++freq[val];
        maxFreq = max(maxFreq, freq[val]);
        group[freq[val]].push(val);
    }
    
    int pop()
    {
        int val = group[maxFreq].top();
        group[maxFreq].pop();
        --freq[val];
        
        if (group[maxFreq].empty())
        {
            --maxFreq;
        }
        
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */