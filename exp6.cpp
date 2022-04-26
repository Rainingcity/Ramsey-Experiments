#include <iostream>
#include <vector>
using namespace std;
const int n=43;
int max_reached=0;
vector<int> vis{};

int get_id(int id, int inc){
	return (id+inc+n)%n;
}

void change_vis(int id, int inc){
	vis[get_id(id, -8)]+=inc;
	vis[get_id(id, -10)]+=inc;
	vis[get_id(id, 8)]+=inc;
	vis[get_id(id, 10)]+=inc;
}

void dfs(int cur);
void dfs_process(int nxt){
	if (!(vis[get_id(nxt, -8)]==2 || vis[get_id(nxt, -10)]==2)){
		vis[nxt]=2;
		change_vis(nxt, -1);
		dfs(nxt);
		change_vis(nxt, 1);
		vis[nxt]=0;
	}
}

void dfs(int cur){
	max_reached=max(max_reached, cur);
	if (cur>=38){
		for(int i=0;i<=cur;i++) if (vis[i]==2) cout<<i<<" ";
		cout<<endl;
		if (cur>=40) return;
	}
	if (vis[cur+1]==0){
		int nxt=get_id(cur, 1);
		dfs_process(nxt);
	}
	if (vis[cur+2]==0){
		int nxt=get_id(cur, 2);
		dfs_process(nxt);
	}
	if (vis[cur+3]==0){
		int nxt=get_id(cur, 3);
		dfs_process(nxt);
	}
	return;
}
int main(){
	vis.resize(n);
	vis[0]=2;
	change_vis(0, -1);
	dfs(0);
	change_vis(0, 1);
	vis[0]=0;
	cout<<max_reached<<endl;
	for(int i=0;i<n;i++) if (vis[i]!=0){cout<<"Leak Detected!"<<endl;return 0;}
	return 0;
}
