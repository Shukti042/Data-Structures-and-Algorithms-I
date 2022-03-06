#include<bits/stdc++.h>
using namespace std;
vector< pair <int,int> > Merge(vector< pair <int,int> > vect1,vector< pair <int,int> > vect2)
{
    int n=vect2.size();
    vector< pair <int,int> > vectn;
    int a=vect1[0].second;
    for(int i=0;i<vect1.size();i++)
    {
        if(vect1[i].second<a)
            a=vect1[i].second;
    }
    for(int i=0;i<n;i++)
    {
        if(a<=vect2[i].second)
            continue;
        vectn.push_back(vect2[i]);
    }
    vect1.insert( vect1.end(), vectn.begin(), vectn.end() );
    //sort(vect1.begin(), vect1.end(), sortbysec);
    return vect1;
}
vector< pair <int,int> > Skyline(vector< pair <int,int> > vect)
{
    int s=vect.size();
    if(s==1)
        return vect;
    vector< pair <int,int> > vect1(vect.begin()+0,vect.begin()+vect.size()/2);
    vector< pair <int,int> > vect2(vect.begin()+(vect.size()/2),vect.end());
    vect1=Skyline(vect1);
    vect2=Skyline(vect2);
    vector< pair <int,int> > res=Merge(vect1,vect2);
    return res;
}
int main()
{
    vector< pair <int,int> > vect,res;
    int n;
    cin>>n;
    int a,b;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        vect.push_back(make_pair(a,b));
    }
    sort(vect.begin(),vect.end());
    res=Skyline(vect);
    cout<<"The Points Does not Dominate:"<<endl;
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i].first<<" "<<res[i].second<<endl;
    }

}
