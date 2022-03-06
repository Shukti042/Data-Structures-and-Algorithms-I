#include<bits/stdc++.h>
using namespace std;
#define NULL_VALUE -999999;
class node
{
    public:
    string bit;
    int freq;
    node *left;
    node *right;
    char ch;
    node()
    {
        left=0;
        right=0;
        freq=NULL_VALUE;
        bit="999999";
        ch='@';
    }
};
class myComparator
{
public:
    int operator() (const node* p1, const node* p2)
    {
        return p1->freq > p2->freq;
    }
};
void setbits(node *p,string st)
{
    if(p->left!=0)
    {
        string t1=st;
        setbits(p->left,t1.append("0"));
    }
    if(p->right!=0)
    {
         string t2=st;
        setbits(p->right,t2.append("1"));
    }
    if(p->ch!='@')
    {
        p->bit=st;
        cout<<p->ch<<" "<<p->bit<<endl;
    }
}
main()
{
    priority_queue <node*, vector<node*>, myComparator > pq;
    int n,m;
    node *t;
    char c;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>c;
        cin>>m;
        t=new node();
        t->freq=m;
        t->ch=c;
        pq.push(t);
    }
    if(n==1)
    {
        cout<<0;
        exit(0);
    }
   /* while (pq.empty() == false)
    {
        node *p = pq.top();
        cout << p->ch<<" "<<p->freq<<endl;
        pq.pop();
    }*/
    for(int i=0;i<n-1;i++)
    {
        node *z=new node();
        t=pq.top();
        z->left=t;
        pq.pop();
        t=pq.top();
        z->right=t;
        pq.pop();
        z->freq=z->left->freq+z->right->freq;
        pq.push(z);

    }
    if(n!=0)
    {
        t=pq.top();
        setbits(t,"");
    }

}
