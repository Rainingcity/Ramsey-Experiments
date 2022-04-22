#include <iostream>
#include <vector>
using namespace std;
int n,N,M;
vector<int> v;
vector<int> vb;
vector<bool> f;

bool next(){
	int j=n-1,k=N;
	for(;j>=0;j--,k--){
		if (v[j]!=k){
			v[j]++;
			break;
		}
	}
	if (j==-1) return false;
	for(j=j+1;j<n;j++){
		v[j]=v[j-1]+1;
	}
	return true;
}

int main(){
	cin>>n;
	N=2*n+1;
	M=4*n+3;
	v.resize(n);
	vb.resize(n);
	int best=1000000;
	for(int i=0;i<n;i++) v[i]=i+2;
	while(next()){
		f.clear();
		f.resize(M);
		for(int t=0;t<n;t++) f[v[t]]=f[M-v[t]]=true;
		bool F=0;
		for(int d1=1;d1<M && !F;d1++){
			if (!f[d1]) continue;
			for(int d2=d1+1;d2<M && !F;d2++){
				if (!f[d2]) continue;
				if (!f[d2-d1]) continue;
				for(int d3=d2+1;d3<M && !F;d3++){
					if (!f[d3]) continue;
					if (!f[d3-d1]) continue;
					if (!f[d3-d2]) continue;
					for(int d4=d3+1;d4<M && !F;d4++){
						if (!f[d4]) continue;
						if (!f[d4-d1]) continue;
						if (!f[d4-d2]) continue;
						if (!f[d4-d3]) continue;
						F=1;
					}
				}
			}
		}
		if (F) continue;
		f.clear();
		f.resize(M,true);
		for(int t=0;t<n;t++) f[v[t]]=f[M-v[t]]=false;
		int cnt=0;
		for(int d1=1;d1<M;d1++){
			if (!f[d1]) continue;
			for(int d2=d1+1;d2<M;d2++){
				if (!f[d2]) continue;
				if (!f[d2-d1]) continue;
				for(int d3=d2+1;d3<M;d3++){
					if (!f[d3]) continue;
					if (!f[d3-d1]) continue;
					if (!f[d3-d2]) continue;
					for(int d4=d3+1;d4<M;d4++){
						if (!f[d4]) continue;
						if (!f[d4-d1]) continue;
						if (!f[d4-d2]) continue;
						if (!f[d4-d3]) continue;
						cnt++;
					}
				}
			}
		}
		if (cnt==5){
			for(int t=0;t<n;t++) cout<<v[t]<<" ";
			cout<<endl;
			f.clear();
			f.resize(M,true);
			for(int t=0;t<n;t++) f[v[t]]=f[M-v[t]]=false;
			for(int d1=1;d1<M;d1++){
				if (!f[d1]) continue;
				for(int d2=d1+1;d2<M;d2++){
					if (!f[d2]) continue;
					if (!f[d2-d1]) continue;
					for(int d3=d2+1;d3<M;d3++){
						if (!f[d3]) continue;
						if (!f[d3-d1]) continue;
						if (!f[d3-d2]) continue;
						for(int d4=d3+1;d4<M;d4++){
							if (!f[d4]) continue;
							if (!f[d4-d1]) continue;
							if (!f[d4-d2]) continue;
							if (!f[d4-d3]) continue;
							cout<<0<<" "<<d1<<" "<<d2<<" "<<d3<<" "<<d4<<endl;
						}
					}
				}
			}
		}
		if (cnt<best){
			best=cnt;
			for(int t=0;t<n;t++) vb[t]=v[t];
		}
	}
	cout<<"Best: "<<best<<endl;
	for(int i=0;i<n;i++) cout<<vb[i]<<" ";
	cout<<endl;
	f.clear();
	f.resize(M,true);
	for(int t=0;t<n;t++) f[vb[t]]=f[M-vb[t]]=false;
	for(int d1=1;d1<M;d1++){
		if (!f[d1]) continue;
		for(int d2=d1+1;d2<M;d2++){
			if (!f[d2]) continue;
			if (!f[d2-d1]) continue;
			for(int d3=d2+1;d3<M;d3++){
				if (!f[d3]) continue;
				if (!f[d3-d1]) continue;
				if (!f[d3-d2]) continue;
				for(int d4=d3+1;d4<M;d4++){
					if (!f[d4]) continue;
					if (!f[d4-d1]) continue;
					if (!f[d4-d2]) continue;
					if (!f[d4-d3]) continue;
					cout<<0<<" "<<d1<<" "<<d2<<" "<<d3<<" "<<d4<<endl;
				}
			}
		}
	}
	return 0;
}
