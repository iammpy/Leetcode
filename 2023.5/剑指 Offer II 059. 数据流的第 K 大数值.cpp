// 只需要维护最大的k个数就行


class KthLargest {
    priority_queue<int, vector<int>, greater<int>> que;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        for(int num:nums){
            que.push(num);
            if(que.size()>k) que.pop();
        }
        this->k=k;

    }
    
    int add(int val) {
        // if(val<que.top()) return que.top();
        que.push(val);
        if(que.size()>k){
            que.pop();
        }
        return que.top();

    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
