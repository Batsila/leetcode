class MyStack
{
    queue<int> a;
    int t;
public:
    void push(int x)
    {
        a.push(x);
        t = x;
    }
    
    int pop()
    {
        queue<int> b;
        
        while (a.size() > 1)
        {
            t = a.front();
            a.pop();
            b.push(t);
        }
        
        int ans = a.front();
        a.pop();
        a = b;
        
        return ans;
    }
    
    int top()
    {
        return t;
    }
    
    bool empty()
    {
        return a.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */