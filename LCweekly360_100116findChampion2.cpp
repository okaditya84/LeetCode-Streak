class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        // n is the number of edges in the graph and edges is the adjacency matrix where edges[i]=[u,v] means there is an edge from u to v
        // find the champion of the graph
        // champion is the node that has no incoming edges
        // if there is no champion or there are multiple champions, return -1
        // if there is a champion, return its value

        // create a vector of size n to store the number of incoming edges for each node
        vector<int> incoming(n,0);
        // loop through the edges matrix and update the incoming vector
        for(int i=0;i<edges.size();i++){
            incoming[edges[i][1]]++;
        }
        // loop through the incoming vector and find the champion
        int champion=-1;
        for(int i=0;i<n;i++){
            if(incoming[i]==0){
                if(champion==-1){
                    champion=i;
                }
                else{
                    return -1;
                }
            }
        }
        return champion;

    }
};