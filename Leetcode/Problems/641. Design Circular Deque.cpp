class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    vector<int>deque;
    int count;
    int front;
    int rear;
    int length;
    MyCircularDeque(int k):deque(k,0) 
    {
        count=0;
        front=0;
        rear=k-1;
        length=k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(length==count)
            return false;
        deque[front]=value;
        front=(front+1)%length;
        count++;
        return true;
    }
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(length==count)
            return false;
        deque[rear]=value;
        rear=(rear-1+length)%length;
        count++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(count==0)
            return false;
        front=(front-1+length)%length;
        count--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(count==0)
            return false;
        rear=(rear+1)%length;
        count--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(count==0)
            return -1;
        return deque[(front-1+length)%length];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(count==0)
            return -1;
        return deque[(rear+1)%length];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return (count==0)?true:false;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return (count==length)?true:false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */