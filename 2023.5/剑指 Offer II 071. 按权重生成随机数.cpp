class Solution {
    int sum=0;
    vector<int> v;
    vector<int> pre;
public:
    Solution(vector<int>& w) {
        int j=0;
        pre.push_back(0);
        for(int i:w){
            
            sum+=i;
            pre.push_back(sum);
           
            
            
        }
        v=w;

    }
    
    int pickIndex() {
        int ran=random()%sum;
        int i=0,j=v.size();
        while(i<j){
            int mid=(i+j)/2;
            if(pre[mid]<ran){
                if(pre[mid+1]>=ran){
                     return mid;
                }else{
                    i=mid+1;

                }

            }else{
                j=mid;
            }
            
        }
        return i;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
