#include<bits/stdc++.h>
using namespace std;
char res[100];
char* LCS(char a[],char b[])
{
    int t=0;
    int m,n;
    m=strlen(a)+1;
    n=strlen(b)+1;
    int i,j;
    int s[m][n];
    for(i=0;i<m;i++)
        s[i][0]=0;
    for(i=0;i<n;i++)
        s[0][i]=0;
    for(i=1;i<m;i++)
    {
        for(j=1;j<n;j++)
        {
            if(a[i-1]==b[j-1])
            {
                s[i][j]=1+s[i-1][j-1];
            }
            else
            {
               s[i-1][j]>s[i][j-1]?s[i][j]=s[i-1][j]:s[i][j]=s[i][j-1];
            }
        }
    }
    /* for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }*/
    i=m-1;
    j=n-1;
    while(s[i][j]!=0)
    {
        if(a[i-1]==b[j-1])
        {
            res[t]=a[i-1];
            t++;
            i--;
            j--;
        }
        else
        {
            s[i-1][j]>s[i][j-1]?s[i][j]=i--:j--;
        }
    }
    return strrev(res);

}
main()
{
    char a[100],b[100];
    cin>>a>>b;
    char *p;
    p=LCS(a,b);
    cout<<p<<endl<<strlen(p);
}
