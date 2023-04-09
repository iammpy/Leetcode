//设置四个边界，然后在指针移动的过程中判断是否触碰边界,然后调整前进方向和边际位置 
//没必要一步一步前进，可以一个循环内直接碰到边界 

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int up=-1,down=matrix.size(),left=-1,right=matrix[0].size();
        int barrier[4]={right,down,left,up};
        int direction=0; //direction is right
        int i=0,j=-1;
        while(v.size()<matrix[0].size()*matrix.size()){
            switch(direction){
                case 0:
                    if(barrier[0]>j+1){
                        j++;
                    }else{
                        direction=1;
                        barrier[3]++;
                        i++;
                        
                    }
                    break;
                 case 1:
                    if(barrier[1]>i+1){
                        i++;
                    }else{
                        direction=2;
                        barrier[0]--;
                        j--;
                        
                    }
                    break;
                 case 2:
                    if(barrier[2]<j-1){
                        j--;
                    }else{
                        direction=3;
                        barrier[1]--;
                        i--;
                        
                    }
                    break;
                 case 3:
                    if(barrier[3]<i-1){
                        i--;
                    }else{
                        direction=0;
                        barrier[2]++;
                        j++;
                        
                    }
                    break;


            }
            v.push_back(matrix[i][j]);
        }
        return v;

    }
};
