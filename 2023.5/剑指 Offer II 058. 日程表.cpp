class MyCalendar {
    map<int,int> cal;
public:
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        auto it=cal.lower_bound(end);
 
        
        if(it == cal.begin() || (--it)->second <= start){
            cal.insert(make_pair(start,end));
            return true;
        }
        return false;


    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
