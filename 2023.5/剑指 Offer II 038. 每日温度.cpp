class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res;
        stack<int> st;
        // vector<int> st;
        //栈中存储下标，而不是温度
        for(int i=temperatures.size()-1;i>=0;--i){
            int tem=temperatures[i];
            int day=0;

            // int j=st.size()-1;
            while(!st.empty()){
                
                if(tem<temperatures[st.top()]){
                    // day++;
                    day=st.top()-i;
                    break;

                }else if(tem>=temperatures[st.top()]){
                    if(st.size()==1) {
                        day=0;
                        break;
                    }
                    st.pop();
                    
                }

            }
            st.push(i);
            res.push_back(day);

            
        }

        reverse(res.begin(),res.end());


        return  res;


    }
};
