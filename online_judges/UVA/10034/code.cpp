#include <bits/stdc++.h>
#define MAX 10100
#define pow2(a) ((a)*(a))

using namespace std;

struct pos{

	float x;
	float y;
	int id;

	pos(float x, float y, int id){
		this->x=x;
		this->y=y;
		this->id = id;
	}
	pos(){};

};

	float dist(pos b, pos a){
		return sqrt(pow2((b.x - a.x)) + pow2((b.y - a.y)));
	}

struct node{
	pos a;
	pos b;
	float weight;
	node(pos a, pos b, float weight){
		this->a = a;
		this->b = b;
		this->weight = weight;
	}
};

vector<node> edges;
vector<pos> nodes;

int uni[MAX];
void initSet() { for(int i = 0; i < MAX; i++) uni[i] = i;}
int findSet(int x) { return x == uni[x] ? x : (x = findSet(uni[x]));}
bool isSameSet(int a, int b) { return findSet(a) == findSet(b); }
void connect(int a, int b) { uni[findSet(a)] = findSet(b); }

float kruskal(){
	initSet();
	float answer = 0;
	for(int i = 0 ; i < edges.size(); i++)
		if(!isSameSet(edges[i].a.id,edges[i].b.id))
			{answer += edges[i].weight; connect(edges[i].a.id,edges[i].b.id);}

	return answer;
}

bool comp(node a, node b) { return a.weight < b.weight;}

int main() {

	int n,m;
	int e;
	float x,y;
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		if(i >= 1) printf("\n");
		nodes.clear(); edges.clear();
		scanf("%d",&m);
		for(int j = 0; j < m ; j++) {
			scanf("%f %f",&x,&y);
			nodes.push_back(pos(x,y,j));
		}
		
		for(int j = 0; j < m; j++)
			for(int k = j+1; k < m; k++)
				edges.push_back(node(nodes[j],nodes[k],dist(nodes[j],nodes[k])));
		sort(edges.begin(),edges.end(),comp);
		printf("%.2f\n",kruskal());
	
	}

	return 0;
}
