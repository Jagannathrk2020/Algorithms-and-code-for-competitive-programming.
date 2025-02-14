#include <bits/stdc++.h> 

#define MAX 1000100 
#define ll long long int
#define F first
#define S second 
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define vi vector<int> 
#define vpii vector<pair<int,int> >
 
using namespace std; 

int n,m,x,y;
int aux_array[MAX];
int suffix_array[MAX];

void countingSort(int k) {

  //classic counting sort, just be careful about index
  int sum, maxi = max(300, n);
  int count[MAX];
  int temp_suffix_array[MAX];

  memset(count, 0, sizeof count);

  for (int i = 0; i < n; i++)
    count[i + k < n ? aux_array[i + k] : 0]++;

  for (int i = sum = 0; i < maxi; i++) {
    int t = count[i]; count[i] = sum; sum += t;
  }

  for (int i = 0; i < n; i++) 
    temp_suffix_array[count[suffix_array[i] + k < n ? aux_array[suffix_array[i] + k] : 0]++] = suffix_array[i];
  
  for (int i = 0; i < n; i++)                   
    suffix_array[i] = temp_suffix_array[i];

}

void constructSA(string s) {      

  int r;
  int temp_aux_array[MAX];
  for (int i = 0; i < n; i++) aux_array[i] = s[i];
  for (int i = 0; i < n; i++) suffix_array[i] = i;   

  for (int k = 1; k < n; k <<= 1) {       
    countingSort(k); countingSort(0);  
    temp_aux_array[aux_array[0]] = r = 0;    
    for (int i = 1; i < n; i++) {
      if(aux_array[suffix_array[i]] == aux_array[suffix_array[i-1]] && aux_array[suffix_array[i]+k] == aux_array[suffix_array[i-1]+k])
	 temp_aux_array[suffix_array[i]] = r;
      else
	 temp_aux_array = r++;
    }
    for (int i = 0; i < n; i++)
      aux_array[i] = temp_aux_array[i];

	if (aux_array[suffix_array[n-1]] == n-1) break;
  }
}

int LCP(string s) {
  int i, L;
  
  Phi[SA[0]] = -1;                                        
  for (i = 1; i < n; i++)                           
    Phi[SA[i]] = SA[i-1];    
  for (i = L = 0; i < n; i++) {             
    if (Phi[i] == -1) { PLCP[i] = 0; continue; }            
    while (s[i + L] == s[Phi[i] + L]) L++;       
    PLCP[i] = L;
    L = max(L-1, 0);                             
  }
  for (i = 0; i < n; i++)                           
    LCP[i] = PLCP[SA[i]];   

  return L;
}

int main() {
 


	return 0; 
}
