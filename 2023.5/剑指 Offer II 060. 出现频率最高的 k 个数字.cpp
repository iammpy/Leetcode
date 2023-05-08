// 用到优先队列的重载函数

class Solution {
    static bool cmp(pair<int, int>& m, pair<int, int>& n) {
        return m.second > n.second;
    }

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 相比上一题，较小的数不能丢
        // 需要写一个堆的比较函数
       
        unordered_map<int,int> mp;
        for(auto& num:nums){
            mp[num]++;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(&cmp)> q(cmp);
        
        for (auto & p : mp) {
            if (q.size() == k) {
               
                   
                    q.push(p);
                     q.pop();
                    
                
            } else {
                q.push(p);
            }
        }

        
        vector<int> ret;
        while (!q.empty()) {
            ret.push_back(q.top().first);
            q.pop();
        }
        return ret;


    }
};
