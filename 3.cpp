#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> pairInt;


//prims-kruskal

class mst{
    int n,m;
    int adj[100][100];
    int id[100];
    bool visited[100];
    vector<pair<int, pair<int, int>>> p;
    
    public:
        mst(){
            n=0;
            m=0;
            for(int i=0;i<100;i++){
                id[i]=i;
            }
            for(int i=0;i<100;i++){
                for(int j=0;j<100;j++){
                    adj[i][j]=0;
                }
            }
        }

        void input(){
            cout << "ENTER NUMBER OF NODES AND EDGES " << endl;
            cin >> n >> m;
            cout << "ENTER EDGES CONNECTING NODES AND EDGE's WEIGHT" << endl;
            for (int i = 0; i < m; i++)
            {
                int x, y, weight;
                cin >> x >> y >> weight;
                p.push_back(make_pair(weight, make_pair(x, y)));
                adj[x][y] = weight;
                adj[y][x] = weight;
            }
        }
        int g_size(){
        	return n;
        }

        void Union(int x,int y){
            id[root(x)]=root(y);
        }

        int root(int x){
            if(id[x]==x){
                return x;
            }
            else{
                return root(id[x]);
            }
        }

        void kruskals(){
            int mncost=0;
            sort(p.begin(),p.end());
            cout<<"Weight and edges selected = "<<endl;
            for(int i=0;i<m;i++){
                if(root(p[i].second.first)!=root(p[i].second.second)){
                    cout<<"WEIGHT : "<<p[i].first<<" NODES : "<<p[i].second.first<<" "<<p[i].second.second<<" "<<endl;
                    mncost+=p[i].first;
                    Union(p[i].second.first,p[i].second.second);
                }
            }
            cout << "COST BY KRUSHKALS IS :" << mncost << endl;


        }

        void Prims(){
            //memset(visited, false, sizeof(visited));
            for(int i=0;i<n;i++){
                visited[i]=false;
            }
            visited[0]=true;
            int mncost=0;
            
            for(int k=0;k<n-1;k++){
                int min=INT_MAX;
                int start, end;
                for(int i=0;i<n;i++){
                    if(visited[i]==false){
                        continue;
                    }

                    for(int j=0;j<n;j++){
                        if(adj[i][j]==0 || visited[j]==true){
                            continue;
                        }
                        if(adj[i][j]<min){
                            start=i;
                            end=j;
                            min=adj[i][j];
                        }
                    }
                }
                cout << "WEIGHT :  " << adj[start][end] << " NODES : " << start << " " << end << endl;
                mncost += adj[start][end];
                visited[start] = true;
                visited[end] = true;

            }
            cout << "COST BY PRIMS : " << mncost << endl;
        }



        //diji
        int min_dist(int dist[],bool sptSet[]){
		    int min=INT_MAX;
		    int min_index;
		    for(int i=0;i<n;i++){
		        if(sptSet[i]==false && dist[i]<=min){
		            min=dist[i];
		            min_index=i;
		        }
		    }
		    return min_index;
		}

		void display(int dist[]){
		    //cout<<"Distance from source = "<<endl;
		    for(int i=0;i<n;i++){
		        cout<<i<<"    "<<dist[i]<<endl;
		    }
		}

		void construct_path(int prev[],int dest){
		    vector<int> path;
		    stack<int> s;
		    int curr=dest;
		    while(curr!=-1){
		        s.push(curr);
		        curr=prev[curr];
		    }

		    while(!s.empty()){
		        path.push_back(s.top());
		        s.pop();
		    }

		    for(int i=0;i<path.size();i++){
		        cout<<path[i];
		        if (i!= path.size() - 1) {
		            cout << " -> ";
		         }
		    }
		    
		}

		// void dis2(int dist[]){
		    
		//         for(int j=0;j<n;j++){
		//             cout<<dist[j]<<" ";
		//         }
		//         cout<<endl;
		    
		// }

		void dijkstra(int src){
		    
		    int dist[n];
		    bool sptSet[n];
		    int prev[n];
		    for(int i=0;i<n;i++){
		        dist[i]=INT_MAX;
		        sptSet[i]=false;
		        prev[i]=-1;
		    }
		    dist[src]=0;
		    
		    for(int count=0;count<n-1;count++){
		        int u=min_dist(dist,sptSet);
		        sptSet[u]=true;
		        
		        for(int i=0;i<n;i++){
		            if(!sptSet[i] && adj[u][i] && dist[u]!=INT_MAX && dist[u]+adj[u][i]<dist[i]){
		                dist[i]=dist[u]+adj[u][i];
		                prev[i]=u;
		            }
		        }

		        
		    }
		    display(dist);
		 
		    cout << "Shortest distances from source node " << src << ":\n";
		    for (int i = 0; i < n; ++i) {
		        cout << "Node " << i << ": " << dist[i] << "\tPath: ";
		        construct_path(prev,i);
		        cout<<endl;
		    }
		    

		    
		    
		}




};


//selection sort


// void selection_sort(vector<int>& arr,int num){
//     int comp=0,swaps=0;
//     int i, j, min_idx; 
  
//     // One by one move boundary of 
//     // unsorted subarray 
//     for (i = 0; i < num - 1; i++) { 
  
//         // Find the minimum element in 
//         // unsorted array 
//         min_idx = i; 
//         for (j = i + 1; j < num; j++) { 
//             if (arr[j] < arr[min_idx]) 
//                 min_idx = j; 
//         } 
  
//         // Swap the found minimum element 
//         // with the first element 
//         if (min_idx != i) 
//             swap(arr[min_idx], arr[i]); 
//     } 
//     cout<<"Comparisons in selection sort: "<<comp<<endl;
//     cout<<"Swaps in selection sort: "<<swaps<<endl;
// }

void selection_sort(vector<int>& arr,int num){
    int comp=0,swaps=0;
    for(int i=0;i<num-1;i++){
        int minn=arr[i];
        int index=i;
        for(int j=i+1;j<num;j++){
            comp++;
            if(arr[j]<minn){
                index=j;
                minn=arr[j];
            }
        }
        comp++;
        if(index!=i){
            int a=arr[index];
            arr[index]=arr[i];
            arr[i]=a;
            swaps++;
        }
        cout<<"Pass "<<i+1<<":"<<endl;
        for(int j=0;j<num;j++){
            cout<<arr[j]<<" ";
        }
        cout<<endl;

    }
    //cout<<"Comparisons in selection sort: "<<comp<<endl;
    ///cout<<"Swaps in selection sort: "<<swaps<<endl;
}


int main(){
	cout<<"*********Greedy Algorithms***********"<<endl;
	cout<<endl;
	int ch;
	//selection
	int num,k;
	vector<int> arr;

	//prims-krus-dij
	int c;
	mst t;
	


	while(1){
		cout<<"1. Selection Sort"<<endl;
		cout<<"2. Input Graph"<<endl;
		cout<<"3. Prims Algorithm"<<endl;
		cout<<"4. Kruskal Algorithm"<<endl;
		cout<<"5. Dijikstra's Algorithm"<<endl;
		cout<<"6. Exit"<<endl;
		cout<<"Enter Your choice  = ";
		cin>>ch;

		switch(ch){
			case 1:
				cout<<"Enter number of elements = ";
				cin>>num;
				cout<<"Enter array elements = ";
				for(int i=0;i<num;i++){
				    cin>>k;
					arr.push_back(k);
					
				}
				selection_sort(arr,num);
				cout<<endl;
				cout<<"After Sorting"<<endl;
				for(int i=0;i<num;i++){
					cout<<arr[i]<<" ";
				}
				cout<<endl;
				cout<<endl;

				for(int i=0;i<num;i++){
					arr.pop_back();
				}
				break;
			case 2:
				t.input();
				cout<<endl;
				break;
			case 3:
				//t.input();
				//cout<<endl;
				t.Prims();
				cout<<endl;
				//t.kruskals();
				//cout<<endl;

				break;
			case 4:
				t.kruskals();
				cout<<endl;
				break;

			case 5:
			    //t.input();
			    //cout<<endl;
			    cout<<"Enter source node = ";
			    cin>>c;
			    t.dijkstra(c);
			    cout<<endl;
			    
			 	//cout<<"Distance from all elements "<<endl;


                //for(int i=0;i<t.g_size();i++){
                 //   cout<<"Distance from source = "<<endl;
                 //   cout<<i<<" : ";
                 //   t.dijkstra(i);
                //}

				break;
			case 6:
				exit(0);
				
			default:
				cout<<"Invalid operation!!!"<<endl;
		}
	}

}

/*
9 14
0 1 4
1 2 8
2 3 7
3 4 9
4 5 10
5 6 2
6 7 1
7 0 8
7 1 11
7 8 7
6 8 6
8 2 2
5 2 4
5 3 14*/

/*
6 9
0 1 4
0 2 5
1 3 9
1 2 11
2 4 3
1 4 7
3 4 13
3 5 2
4 5 6
*/
