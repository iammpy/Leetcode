class Solution {
public:
    int maximalRectangle(vector<string>& matrix) {
        //动规
        if(matrix.size()==0) return 0;
        int res=0;
        // 对于每一个点都可以用四个数来确定他周围的格子的情况
        // 对于一个新的格子，通过他上面和左面的两个格子中的八个数字来导出他向左边延伸和向上方延伸分别能达到的最大方块，分别用两对长宽表示，共四个数字

        vector<vector<pair<pair<int,int>,pair<int,int>>> resNums(matrix.size(),vector<pair<int,int>,pair<int,int>(vector[0].size,make_pair(make_pair(0,0),make_pair(0,0))));
        for(int i=0;i<matrix.size(),++i){
            string str=matrix[i];
            // resNums.push_back({});
            for(int j=0;j<str.size();j++){
                char c=str[j];
                pair<int,int> up=make_pair(make_pair(0,0),make_pair(0,0));
                pair<int,int> left=make_pair(make_pair(0,0),make_pair(0,0));
                if(c=='0'){
                    // resNums[i][j]
                    continue;
                }

                // 当为1时，怎么更新根据前两个格子更新当前的格子
                
                // if(i>0){
                //     left.first=resNums[i-1][j].first++;
                //     left.second=resNums[i-1][j].second;

                // }
                // if(j>0){
                //     up.first=resNums[i][j-1].first++;
                //     left.second=resNums[i][j-1].second++;
                // }
                // pair<int,int> cur=make_pair(0,0);
                // // cur.first=

                // res=max(res,cur.first*cur.second);


            }
        }
        

    }
};
