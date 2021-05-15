class RecentCounter {
public:
    queue<int>q;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        q.push(t);
        while(q.front()<t-3000)
        {
            q.pop();
        }
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */


/*
Here we tell how many call were made within 3000 millisecond.
eg 1st call at 1 millisecond so  q=[1,] 
	s=1
   2nd call at 100 millisecond so q=[1,100,]
	Now when we insert we check if 1st call was made before 3000 millisecond using if q.front() ie 1<100-3000 
	s=2
   3rd call at 3001 millisecond so q=[1,100,3001,]
	if q.front()<3001-3000
	s=3
   4th call at 3002 millisecond so q=[1,100,3001,3002,]
	so now observe 1st call was at 1 milllisecond so it was made before 3001 millisecond ie >3000 so we will remove it
	if q.front()<3002-3000
	q=[100,3001,3002,]
	s=3

*/