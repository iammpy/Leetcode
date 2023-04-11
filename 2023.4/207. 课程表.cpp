判断是否成环

class Solution {
    vector<bool> onPath;
    vector<bool> visited;
    bool  can=true;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size()==0) return true;
        auto graph= vector<vector<int>>(numCourses);
        for(auto i:prerequisites){
            int from=i[1],to=i[0];
            graph[from].push_back(to);
        }
        onPath=vector<bool>(numCourses,false);
        visited=vector<bool>(numCourses,false);
        for(int i=0;i<numCourses;i++){
                dfs(graph,i);
        }




        return can;
    }

    void dfs(vector<vector<int>>& graph,int s){
        if(onPath[s]) {
            can=false;
            return;
        }
        if(!can||visited[s]) return;
        onPath[s]=true;
        visited[s]=true;
        for(auto i:graph[s]){
            dfs(graph,i);
        }

        onPath[s]=false;
    }
};
