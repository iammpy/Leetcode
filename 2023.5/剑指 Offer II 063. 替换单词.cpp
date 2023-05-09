struct Trie {
    unordered_map<char, Trie *> children;
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string res="";
        // 初始化前缀树
        Trie* tr=new Trie();
        for(string& str: dictionary){
            Trie* node=tr;
            for(char c:str){
                if(node->children.find(c)!=node->children.end()&&node->children[c]->children.size()==0) {
                    node=node->children[c];
                    break;
                }
                if(node->children.find(c)==node->children.end()){
                    node->children.insert(make_pair(c, new Trie()));
                }
                
                node=node->children[c];
            }
             node->children.clear();
        }


        int l=0;
        sentence.push_back(' ');
        int r=sentence.find(' ');
        while(r<sentence.size()){
            string temp="";
            if(tr->children.find(sentence[l])==tr->children.end()){
                // 不进行替换
                temp=sentence.substr(l,r-l+1);
                res+=temp;
            }else{
                // 替换
                Trie* node=tr;
                string sub=sentence.substr(l,r-l);
                while(l<r){
                    char c=sentence[l];
                    if(node->children.find(c)!=node->children.end()){
                        temp+=c;
                        node=node->children[c];
                        l++;
                    }else{
                        if(node->children.size()==0) break;
                        else{
                            temp=sub;
                            break;
                        }
                    }
                    

                }
                res+=temp;
                res+=' ';
            }

            l=r+1;
            r=sentence.find(' ',l);
            
        }

        res.erase(res.size()-1, res.size());
        



        return res;

    }

    
};
