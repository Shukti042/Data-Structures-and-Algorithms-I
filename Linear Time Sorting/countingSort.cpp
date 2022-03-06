#include<bits/stdc++.h>
using namespace std;
void countingSort(int a[],int b[],int n)
{
    int kmax=a[0],kmin=a[0];;
    for(int i=0;i<n;i++)
    {
        if(kmax<a[i])
            kmax=a[i];
        if(kmin>a[i])
            kmin=a[i];
    }
    int s=kmax-kmin+1;
   int c[s];
    for(int i=0;i<s;i++)
        c[i]=0;
    for(int i=0;i<n;i++)
        c[a[i]-kmin]= c[a[i]-kmin]+1;
    for(int i=1;i<s;i++)
        c[i]=c[i]+c[i-1];
    for(int i=n-1;i>=0;i--)
    {
        b[c[a[i]-kmin]-1]=a[i];
         c[a[i]-kmin]= c[a[i]-kmin]-1;

    }

}
main()
{
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        b[i]=0;
        countingSort(a,b,n);
    for(int i=0;i<n;i++)
        cout<<b[i]<<" ";
}
