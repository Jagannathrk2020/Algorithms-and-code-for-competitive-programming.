#include <bits/stdc++.h>
#define INF 1000009
#define MAX 100024

using namespace std;

struct data{

	int a,b,w;
	bool used;
	data(int a, int b, int w){
		this->a=a;
		this->b=b;
		this->w=w;
		used = false;
	}
};

bool comp(data a, data b) { return a.w < b.w; }

vector<data> edges;
int uni[MAX];
void initUni(){ for(int i = 0; i < MAX; i++) uni[i] = i; }
int findSet(int x) { return (x == uni[x]) ? x : (uni[x] = findSet(uni[x]));}
bool isSameSet(int x, int y) { return findSet(x) == findSet(y); }
void connect(int x, int y) { uni[findSet(x)] = findSet(y); }

int kruskal(int v){
	sort(edges.begin(),edges.end(),comp);
	int k = 0;
	for(int i = 0; i < edges.size(); i++){
		if(!isSameSet(edges[i].a,edges[i].b))
			{
				connect(edges[i].a,edges[i].b);
				edges[i].used = true;
			}

		else k++;
	}
	
	return k;
}

int main(){

	int t;
	int n,m,a;
	int x,y,c;

	while(1){
		scanf("%d %d",&n,&m);
		if(n == 0) break;
		initUni();		
		edges.clear();
		
		for(int j = 0 ; j < m; j++)
		{
			scanf("%d %d %d",&x,&y,&c);
			edges.push_back(data(x,y,c));
		}

		int answer = kruskal(n);
		if(answer == 0)
			printf("forest\n");
		else
			{			
			int c = 0;			
			for(int j = 0; j < m; j++)				
				if(!edges[j].used)
					if(c++ == 0)
						printf("%d",edges[j].w);
					else printf(" %d",edges[j].w);
				printf("\n");
			}
		}	

	return 0;
}
