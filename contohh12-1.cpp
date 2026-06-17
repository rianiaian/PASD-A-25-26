#include <iostream>
#include <stdlib.h>
#define MAX 10
using namespace std;

int cost[MAX][MAX],i,j,k,n,stk[MAX],top,v,visit[MAX],visited[MAX];
int main(){
	int m;
	cout<<"\nMasukkan Vertex : ";
	cin>>n;
	cout<<"Masukkan Busur : ";
	cin>>m;
	cout<<"\nBUSUR"<<endl;
	for(k=1; k<=m; k++){
		cin>>i>>j;
		cost[i][j]=1;
	}
	cout<<"Inisialiasi Vertex = ";
	cin>>v;
	cout<<"DFS Order Vertex   = ";
	cout<<v<<" ";
	visited[v]=1;
	k=1;
	while(k<n){
		for(j=n; j>=1; j--)
			if(cost[v][j]!=0 && visited[j]!=1 && visit[j]!=1){
				visit[j]=1;
				stk[top]=j;
				top++;
			}
		v=stk[--top];
		cout<<v<<" ";
		k++;
		visit[v]=0;
		visited[v]=1;
	}
	cin.get();
	return 0;
}