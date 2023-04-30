//查分数组加哈希表


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // int res=0;
        // vector<int> dif(nums.size()+1);
        // dif[0]=0;
        // for(int i=0;i<nums.size();++i){
        //     if(nums[i]==1){
                
        //         dif[i+1]=dif[i]+1;
        //     }else{
        //         dif[i+1]=dif[i]-1;
        //     }
        // }

        // for(int i=0;i<dif.size();++i){
        //     for(int j=0;j<i;++j){
        //         if(dif[i]-dif[j]==0){
        //             res=(i-j)>res? (i-j):res;
 
        //         }
        //     }
        // }

        // return res;

        int res=0;
        unordered_map<int ,int> dif;
        dif.insert(make_pair(0,0));
        int current=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==0){
                current--;
                auto it=dif.find(current);
                if(it!=dif.end()){
                    res=max(i+1-it->second,res);

                }else{
                    dif.insert(make_pair(current,i+1));

                }
            }else{
                current++;
                auto it=dif.find(current);
                if(it!=dif.end()){
                    res=max(i+1-it->second,res);

                }else{
                    dif.insert(make_pair(current,i+1));

                }
            }
        }



        return res;

    }
};
