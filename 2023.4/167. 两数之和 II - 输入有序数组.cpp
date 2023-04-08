class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0,right=numbers.size()-1;
        vector<int> v(2,0);
        while(left<right){
            int sum=numbers[left]+numbers[right];
            if(sum==target) {
                v[0]=left+1;
                v[1]=right+1;
                return v;
            }else if(sum>target){
                right--;
            }else{
                left++;
            }
        }
        return v;
    }
};
