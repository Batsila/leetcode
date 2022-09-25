class MyCircularQueue 
{
private:
    vector<int> v;
    int head = 0;
    int tail = 0;
    int capacity;
public:
    MyCircularQueue(int k) 
    {
        v = vector<int>(k, -1);
        capacity = k;
    }
    
    bool enQueue(int value) 
    {
        if (isFull())
        {
            return false;
        }
        
        v[tail % capacity] = value;
        
        ++tail;
        
        return true;
    }
    
    bool deQueue() 
    {
        if (isEmpty())
        {
            return false;
        }
        
        v[head % capacity] = -1;
        
        ++head;
        
        return true;
    }
    
    int Front() 
    {
        return v[head % capacity];
    }
    
    int Rear() 
    {
        return v[(tail - 1 + capacity) % capacity];
    }
    
    bool isEmpty() 
    {
        return head == tail;
    }
    
    bool isFull() 
    {
        return tail - head == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */