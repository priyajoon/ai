#include <bits/stdc++.h>
using namespace std;

bool visited[20];
vector<int> gp[20];
int depth[20];
int parent[20];
vector<int> depth_limit;

void dfs(int v) {
    // Output the current vertex being visited
    cout << v << " ";
    visited[v] = 1;
     // Traverse through all adjacent vertices of vertex 'v'
    for(int i : gp[v]) {
        // Check if the adjacent vertex 'i' has already been visited
        if(visited[i]) {
            // If visited, skip to the next adjacent vertex
            continue;
        }
        
        // Update the depth of the adjacent vertex 'i' to the maximum of its current depth and (depth of 'v' + 1)
        depth[i] = max(depth[i], depth[v] + 1);
        
        // Recursively call DFS for the unvisited adjacent vertex 'i'
        dfs(i);
    }
}

//start= starting node
//limit_dp=end depth
void depth_limit_search(int v,int start,int limit_dp){
    // Check if the depth of the current vertex 'v' plus 1 falls within the specified depth limit and start depth
    if (depth[v]+1<=limit_dp and depth[v]+1>=start) {
        // If within the depth limit and start depth, add the current vertex 'v' to the depth-limited result
        depth_limit.push_back(v);
    }
    cout<<v<<" ";
    visited[v]=1;
    for(int i: gp[v]){
        if(visited[i]){
            continue;
        }
        // Set the parent of the adjacent vertex 'i' as 'v'
        parent[i]=v;
        depth[i] = max(depth[i], depth[v] + 1);
        depth_limit_search(i,start,limit_dp);

    }
}


void bfs(int v){
    queue<int> q;
    q.push(v);
    visited[v]=1;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        cout<<x<<" ";
        for(int i:gp[x]){
            if(visited[i]){
                continue;
            }
            q.push(i);
            visited[i]=1;
        }
    }
}

void dls(int val,int start,int end){
    
                
                
    
    int cnt=0;
    for(int i=0;i<depth_limit.size();i++){
        if(depth_limit[i]==val){
            cnt++;
            break;
        }
    }
    vector<int> path;
    if(cnt>0){
        cout<<"Element found"<<endl;
        cout<<"path is : ";
        int p;
        path.push_back(val);
        while(true){
            p=parent[val];
            val=p;
            if(p==-1){
                break;
            }
            path.push_back(p);
        }
        for(int i=path.size()-1;i>=0;i--){
            if(depth[path[i]]+1>=start){
                cout<<path[i]<<" ";
            }
        }
        cout<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }



}

void clear_vis(){
    for(int i=0;i<20;i++){
        visited[i]=0;
    }
}
int main(){
    int n,e;
    cout<<"Enter number of nodes = ";
    cin>>n;
    cout<<"Enter number of edges = ";
    cin>>e;
    cout<<"enter source and destination"<<endl;
    for(int i=0;i<e;i++){
        int x,y;
        
        cin>>x>>y;
        
        gp[x].push_back(y);
        gp[y].push_back(x);
    }

    int source=0;
    cout<<"Enter source node = ";
    cin>>source;
    parent[source]=-1;
    int start,end,val;
        


    while(1){
        cout<<"1 BFS"<<endl;
        cout<<"2 DFS"<<endl;
        cout<<"3 DLS"<<endl;
        cout<<"4 Exit"<<endl;
        cout<<"Enter choice = ";
        int ch;
        cin>>ch;
        switch(ch){
            case 1:
                
                
                bfs(source);
                cout<<endl;
                clear_vis();
                break;
            case 2:
                dfs(source);
                cout<<endl;
                clear_vis();
                break;
            case 3:
                cout<<"Enter the range of depth = ";
                cin>>start>>end;
                cout<<"Enter value to search = ";
                cin>>val;
                depth_limit_search(source,start,end);
                cout<<endl;
                dls(val,start,end);
                cout<<endl;
                for(int i=0;i<depth_limit.size();i++){
                    depth_limit.pop_back();
                }
                clear_vis();
                break;
            case 4:
                exit(1);
                break;
            default:
                cout<<"Invalid choice";

        }
    }


}