class RecentCounter {
    queue<int> req;
public:
    RecentCounter() {
        req.push(-3000);

    }
    
    int ping(int t) {
        
        req.push(t);
        while(req.front()<t-3000) req.pop();
        return req.size();



    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
