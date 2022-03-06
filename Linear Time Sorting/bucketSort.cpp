#include<bits/stdc++.h>
using namespace std;
void bucketSort(float arr[],float b[],int n)
{
    vector<vector<float > >  buck1(5, vector<float> ());
    int t;
    float f;
    int ii=0;
    vector<float> a,c;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<0)
        {
            c.push_back(arr[i]);
        }
        else
            a.push_back(arr[i]);
    }
     for(int i=0;i<c.size();i++)
    {
        f=abs(c[i])-abs(int(c[i]));
        t=f*5;
        buck1[t].push_back(c[i]);
    }
    for(int i=0;i<5;i++)
        sort(buck1[i].begin(),buck1[i].end());
    /*for(int j=0;j<5;j++)
        {
            for(int k=0;k<buck1[j].size();k++)
            {
                cout<<buck1[j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;*/
    float kmin;
    if(c.size()>0)
        kmin=c[0];
    for(int i=0;i<c.size();i++)
    {
        if(kmin>c[i])
            kmin=c[i];
    }
    kmin=int(kmin);
    int ki[5];
    for(int i=0;i<5;i++)
        ki[i]=0;
    for(;ii<c.size();)
    {
        for(int j=4;j>=0;j--)
        {
            for(int k=ki[j];k<buck1[j].size();k++)
            {
                if(int(buck1[j][k])>kmin)
                break;
                b[ii]=buck1[j][k];
                ii++;
                ki[j]=ki[j]+1;
            }
        }
        kmin++;
    }


    vector<vector<float > >  buck(5, vector<float> ());
    for(int i=0;i<a.size();i++)
    {
        f=abs(a[i])-abs(int(a[i]));
        t=f*5;
        buck[t].push_back(a[i]);
    }
    for(int i=0;i<5;i++)
        sort(buck[i].begin(),buck[i].end());
    if(a.size()>0)
        kmin=c[0];
    for(int i=0;i<a.size();i++)
    {
        if(kmin>a[i])
            kmin=a[i];
    }
    kmin=int(kmin);
    for(int i=0;i<n;i++)
        ki[i]=0;
    for(;ii<n;)
    {
        for(int j=0;j<5;j++)
        {
            for(int k=ki[j];k<buck[j].size();k++)
            {
                if(int(buck[j][k])>=kmin)
                break;
                b[ii]=buck[j][k];
                ii++;
                ki[j]=ki[j]+1;
            }
        }
        kmin++;
    }
}
main()
{
     int n;
    cin>>n;
    float a[n],b[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        b[i]=0;
        bucketSort(a,b,n);
    for(int i=0;i<n;i++)
        cout<<b[i]<<" ";
}
