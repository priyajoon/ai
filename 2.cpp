#include <bits/stdc++.h>
using namespace std;

map<vector<vector<int>>,int>mp;
vector<vector<int>> initial,dummy,final;

void func(vector<vector<vector<int>>> &v,int k){
	vector<vector<vector<int>>> pass1;
	vector<pair<int,vector<vector<int>>>> vp;
	cout<<"------------------------------------------"<<endl;

	if(v.size()==0){
		cout<<"No solution "<<endl;
		return;
	}

	for(int il=0;il<v.size();il++){
		vector<vector<int>> d=v[il];

		//if final state achieved
		if(d==final){
			cout<<"final state is achieved after " << k-1 << " steps"<<endl;
			return ;
		}
		//finding space
		int x,y;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(d[i][j]==0){
					x=i;y=j;
				}
			}       
		}
		int h;			//misplaced tiles or heuristic
		cout<<endl;

		cout<<"-----------states after level "<<k<<" is -------"<<endl;

		if(x-1>=0){
			d[x][y]=d[x-1][y];
			d[x-1][y]=0;
			h=0;

			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					cout<<d[i][j]<<" ";
					if(final[i][j]==0){

					}
					else if(final[i][j]!=d[i][j]){
						h++;
					}
				}
				cout<<endl;
			}
			cout<<endl;

			if(mp[d]==0){
				mp[d]++;
				vp.push_back({k+h,d});
			}
			else{
				cout<<"-----this state is repeating-----"<<endl;
			}
			d[x-1][y]=d[x][y];
			d[x][y]=0;
			cout<<"g(n) = "<<k<<endl;
			cout<<"h(n) = "<<h<<endl;
			cout<<"f(n) = "<<k+h<<endl<<endl;
		}



		if(x+1<3){
			d[x][y]=d[x+1][y];
			d[x+1][y]=0;
			h=0;

			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					cout<<d[i][j]<<" ";
					if(final[i][j]==0){

					}
					else if(final[i][j]!=d[i][j]){
						h++;
					}
				}
				cout<<endl;
			}
			cout<<endl;

			if(mp[d]==0){
				mp[d]++;
				vp.push_back({k+h,d});
			}
			else{
				cout<<"-----this state is repeating-----"<<endl;
			}
			d[x+1][y]=d[x][y];
			d[x][y]=0;
			cout<<"g(n) = "<<k<<endl;
			cout<<"h(n) = "<<h<<endl;
			cout<<"f(n) = "<<k+h<<endl<<endl;
		}

		if(y-1>=0){
			d[x][y]=d[x][y-1];
			d[x][y-1]=0;
			h=0;

			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					cout<<d[i][j]<<" ";
					if(final[i][j]==0){

					}
					else if(final[i][j]!=d[i][j]){
						h++;
					}
				}
				cout<<endl;
			}
			cout<<endl;

			if(mp[d]==0){
				mp[d]++;
				vp.push_back({k+h,d});
			}
			else{
				cout<<"-----this state is repeating-----"<<endl;
			}
			d[x][y-1]=d[x][y];
			d[x][y]=0;
			cout<<"g(n) = "<<k<<endl;
			cout<<"h(n) = "<<h<<endl;
			cout<<"f(n) = "<<k+h<<endl<<endl;
		}

		if(y+1<3){
			d[x][y]=d[x][y+1];
			d[x][y+1]=0;
			h=0;

			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					cout<<d[i][j]<<" ";
					if(final[i][j]==0){

					}
					else if(final[i][j]!=d[i][j]){
						h++;
					}
				}
				cout<<endl;
			}
			cout<<endl;

			if(mp[d]==0){
				mp[d]++;
				vp.push_back({k+h,d});
			}
			else{
				cout<<"-----this state is repeating-----"<<endl;
			}
			d[x][y]=d[x][y+1];
			d[x][y+1]=0;
			cout<<"g(n) = "<<k<<endl;
			cout<<"h(n) = "<<h<<endl;
			cout<<"f(n) = "<<k+h<<endl<<endl;
		}
	}

	if(vp.size()==0){
		cout<<"NO solution. All states are repeating"<<endl;
		return;
	}

	sort(vp.begin(),vp.end());
	pass1.push_back(vp[0].second);
	cout<<endl;

	for(auto xp:vp){
		cout<<xp.first<<" ";
	}
	cout<<endl;

	for(int i=1;i<vp.size();i++){
		if(vp[i].first==vp[i-1].first){
			pass1.push_back(vp[i].second);
		}
		else{
			break;
		}
	}

	cout<<"*******states with minimum huiristic values are ******** "<<endl;
	for(int i=0;i<pass1.size();i++){
		vector<vector<int>> p=pass1[i];
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				cout<<p[j][k]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		cout<<"f(n) = "<<vp[i].first<<endl;
	}
	func(pass1,k+1);

}
int main(){
	cout<<"enter initial state "<<endl;
	for(int i=0;i<3;i++){
		vector<int>v;
		for(int j=0;j<3;j++){
			int k;cin>>k;
			v.push_back(k);	
		}
		dummy.push_back(v);
		initial.push_back(v);
	} 
	cout<<"enter final state "<<endl;
	for(int i=0;i<3;i++){
		vector<int>v1;
		for(int j=0;j<3;j++){
			int k;cin>>k;
			v1.push_back(k);
		}
		final.push_back(v1);
	}

	vector<vector<vector<int>>> pass;
	pass.push_back(dummy);
	int k=1;
	func(pass,k);
}