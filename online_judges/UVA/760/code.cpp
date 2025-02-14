#include <bits/stdc++.h>
#define MAX 400
using namespace std;

int memo[MAX][MAX];
string s1,s2,s[MAX];
int s1l, s2l;
int func(int i, int j) {

    if(i==s1l || j==s2l)    return 0;
    if(memo[i][j]!=-1)      return memo[i][j];
    int ret=0;
    if(s1[i]==s2[j])
        ret=1+func(i+1,j+1);

    return memo[i][j]=ret;
}

int main()
{
    int count = 1;
    while(getline(cin,s1))
    {
        if(count != 1)
            getline(cin,s1);
        getline(cin,s2);
        s1l=s1.length();
        s2l=s2.length();
        int res = 0;
        memset(memo,-1,sizeof memo);
        for(int i=0;i<s1l;i++)
            for(int j=0;j<s2l;j++)
                res=max(res,func(i,j));
       
        if(count != 1)
            cout<<endl;

        if(!res)
            cout<<"No common sequence."<<endl;
        else
        {
            int cnt=0;
            for(int i=0;i<s1l;i++)
                for(int j=0;j<s2l;j++)
                    if(memo[i][j]==res) {
                        s[cnt]="";
                        for(int k=i;k<i+res;k++)
                            s[cnt]+=s1[k];
                        cnt++;
                    }
            sort(s,s+cnt);
            cout<<s[0]<<endl;

            for(int i=1;i<cnt;i++)
                if(s[i]!=s[i-1])
                    cout<<s[i]<<endl;
        }
        count++;
    }
}
