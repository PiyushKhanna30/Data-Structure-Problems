class Task implements Comparable<Task>{
    int start;
    int end;
    Task(int start, int end){
        this.start = start;
        this.end = end;
    }
    public int compareTo(Task t){
        return t.start < start ? 1:-1;
    }  
    
    public String toString(){
        return "["+start+", "+end+"]";
    }
}
class MyCalendar {

    ArrayList<Task>q;
    public MyCalendar() {
        q = new ArrayList<>();
    }
    
    public boolean book(int start, int end) {
        int index = 0;
        while(index < q.size()){
            Task t = q.get(index);
            if((t.start<= start && start<t.end) || (t.start< end && end<t.end))return false;
            if((start<= t.start && t.start<end) || (start< t.end && t.end<end))return false;
            if(start<t.start && start<t.end)break;
            index+=1;
        }
        q.add(new Task(start,end));
        Collections.sort(q);
        
        // System.out.println(q);
        return true;
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(start,end);
 */
