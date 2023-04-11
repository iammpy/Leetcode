class Solution {
    vector<bool> visited;
    vector<int> path;
    vector<vector<int>> totalPath;
    int target;
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        if(graph.size()==0) return {};
        target=graph.size()-1;
        visited=vector<bool>(graph.size(),false);
        traverse(graph, 0);
        return totalPath;

    }

    void traverse(vector<vector<int>>& graph,int s){
        if(visited[s]) return;
        visited[s]=true;
        path.push_back(s);
        if(s==target) {
            totalPath.push_back(path);
            path.pop_back();
            visited[s]=false;
            return;
        }
        for(auto i:graph[s]){
            traverse(graph, i);
        }
        path.pop_back();
        visited[s]=false;

    }
};
