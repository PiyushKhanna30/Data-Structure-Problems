class CustomStack {
public:
    vector<int>st;
    int maxSize;
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if(st.size()<maxSize)
            st.push_back(x);
    }
    
    int pop() {
        if(st.size()==0)
            return -1;
        int top = st[st.size()-1];
        st.pop_back();
        return top;
    }
    
    void increment(int k, int val) {
        int end = k<st.size()?k:st.size();
        for(int i=0;i<end;i++)
            st[i]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */