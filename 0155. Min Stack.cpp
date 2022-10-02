class MinStack
{
    stack<int> s;
    multiset<int> ms;
public:
    void push(int val)
    {
        s.push(val);
        ms.insert(val);
    }
    
    void pop()
    {
        ms.erase(ms.find(s.top()));
        s.pop();
    }
    
    int top()
    {
        return s.top();
    }
    
    int getMin()
    {
        return *ms.begin();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */