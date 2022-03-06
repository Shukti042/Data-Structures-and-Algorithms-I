#include<bits/stdc++.h>
using namespace std;
class Customer
{
    public:
    int st;
    int ind;
};
 bool operator < (Customer const & a, Customer const & b)
    {
        return a.st < b.st;
    }
main()
{
    int n;
    cin>>n;
    Customer c[n];
    for(int i=0;i<n;i++)
    {
          cin>>c[i].st;
          c[i].ind=i+1;
    }
    sort(c+0,c+n);
    for(int i=0;i<n;i++)
        cout<<c[i].ind<<" ";

}
