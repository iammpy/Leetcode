class Solution {


public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> resNums;
        int res=0;
        // int i=0;
        // st存储递增的高度，以及该高度的起始宽度
        vector<pair<int,int>> st; 

        for(int i;i<heights.size();++i){
            int h=heights[i];
            //入栈的时候存储该高度的l，出栈时计算r-l得出宽度
            // if(st.empty()||h>=st[st.size()-1].first){
            //     st.push_back(make_pair(h,i));
            //     break;

            // }

            //对于一个高度的起点应该从哪里开始
            int cur=i;
            
            while(!st.empty()&&h<st[st.size()-1].first){
              pair<int,int> p=st[st.size()-1];
            int width=i-p.second;
            resNums.push_back(width*p.first);
            cur=p.second;
            st.pop_back();
            

            }

            st.push_back(make_pair(h,cur));
            


            // i++;
        }
        while(!st.empty()){
             pair<int,int> p=st[st.size()-1];
            int width=heights.size()-p.second;
            resNums.push_back(width*p.first);
            st.pop_back();

        }



        for(int r:resNums){
            res=max(res,r);
        }
        return res;

    }
};
