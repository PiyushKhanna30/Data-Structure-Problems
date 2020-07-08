class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    vector<int>deque;
    int count;
    int front;
    int rear;
    int length;
    MyCircularQueue(int k):deque(k,0)  {
        count=0;
        front=0;
        rear=k-1;
        length=k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(length==count)
            return false;
        deque[front]=value;
        front=(front+1)%length;
        count++;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(count==0)
            return false;
        rear=(rear+1)%length;
        count--;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        
        if(count==0)
            return -1;
        return deque[(rear+1)%length];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(count==0)
            return -1;
        return deque[(front-1+length)%length];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return (count==0)?true:false;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (count==length)?true:false;
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