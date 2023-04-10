class Solution {
    
public:
    bool verifyPostorder(vector<int>& postorder) {
        int ptr=postorder.size()-1;
        if(ptr==-1) return true;
        int limit=INT_MAX;
        vector<int> stack;
        stack.push_back(INT_MIN);

        
        for(;ptr>-1;--ptr){           
            int temp=postorder[ptr];

            if(temp>limit) return false;
            if(temp>stack.back()){
                stack.push_back(temp);
            }else if(temp<stack.back()){
                 int root=stack.back();
                while(temp<stack.back()){
                   root=stack.back();
                stack.pop_back();
                

                }
                limit=root;


            }

            
        }

        return true;



    }
};
