#include<bits/stdc++.h>
using namespace std;
#define NULL_VALUE -999999;
class maxheap
{
        int heapSize;
        int length;
        int *a;
    public:
        int Size()
        {
            return heapSize;
        }
        bool isEmpty()
        {
            return heapSize>0;
        }
        maxheap()
        {
            heapSize=0;
            length=0;
            a=new int[100];;
        }
        maxheap(int l,int b[])
        {
            a=new int[100];
            length=l;
            heapSize=l;
            for(int k=0;k<l;k++)
                a[k]=b[k];
            buildHeap();
        }
        int parent(int i)
        {
            return i/2;
        }
        int left(int i)
        {
            return 2*i;
        }
        int right(int i)
        {
            return (2*i)+1;
        }
        void maxHeapify(int i)
        {
            int largest;
            int l=left(i);
            int r=right(i);
            if(l<heapSize&&l>=0&&a[l]>a[i])
                largest=l;
            else
                largest=i;
            if(r<heapSize&&r>=0&&a[r]>a[largest])
                largest=r;
            if(largest!=i)
            {
                int t;
                t=a[i];;
                a[i]=a[largest];
                a[largest]=t;
                maxHeapify(largest);
            }

        }
        int findMax()
        {
            if(heapSize<=0)
            {
                cout<<"The Heap is empty"<<endl;
                return NULL_VALUE;
            }
            return a[0];
        }
        void buildHeap()
        {
            heapSize=length;
            for(int i=length/2;i>=0;i--)
                maxHeapify(i);
        }
        int ExtractMax()
        {
            if(heapSize>0)
            {
                int m=a[0];
                a[0]=a[heapSize-1];
                heapSize--;
                maxHeapify(0);
                return m;
            }
            return NULL_VALUE;
        }
        int Replace(int j)
        {
            int m=a[0];
            a[0]=j;
            maxHeapify(0);
            return m;
        }
        void deleteMax()
        {
            ExtractMax();
        }
        void Insert(int n)
        {
            a[heapSize]=n;
            int i=heapSize;
            heapSize++;
            ShiftUp(i);
        }
        static maxheap Merge(maxheap x,maxheap y)
        {
            maxheap c(x.heapSize,x.a);
            for(int j=0;j<y.heapSize;j++)
                c.Insert(y.a[j]);
            return c;
        }
        static maxheap Meld(maxheap &x,maxheap &y)
        {
            maxheap c(x.heapSize,x.a);
            for(int j=0;j<y.heapSize;j++)
                c.Insert(y.a[j]);
            delete x.a;
            delete y.a;
            x.heapSize=0;
            y.heapSize=0;
            return c;
        }
        void ShiftUp(int i)
        {
            while(i>0&&a[parent(i)]<a[i])
            {
                int t=a[parent(i)];
                a[parent(i)]=a[i];
                a[i]=t;
                i=parent(i);
            }
        }
        void ShiftDown(int i)
        {
            maxHeapify(i);//actually two jobs are same
        }
        void increaseKey(int i,int key)
        {
            if(i>=0&&i<heapSize)
            {
                if(key<a[i])
                {
                    cout<<"new key is smaller than current key"<<endl;
                    return;
                }
                a[i]=key;
                ShiftUp(i);
            }

        }
        void decreaseKey(int i,int key)
        {
            if(i>=0&&i<heapSize)
            {
                if(key>a[i])
                {
                    cout<<"new key is greater than current key"<<endl;
                    return;
                }
                a[i]=key;
                ShiftDown(i);
            }
        }
        void Delete(int key)
        {
            int i=-1;
            for(int j=0;j<heapSize;j++)
            {
                if(a[j]==key)
                {
                    i=j;
                    break;
                }
            }
            if(i!=-1)
            {
                int m=a[i];
                a[i]=a[heapSize-1];
                heapSize--;
                ShiftDown(i);
            }
        }
};
main()
{
    int a[]={7,3,17,8,4,10};
    cout<<"a[]={7,3,17,8,4,10}"<<endl;
    maxheap m(6,a);
    cout<<m.findMax()<<"//findMax()"<<endl;
    cout<<"Insert(30)"<<endl;
    m.Insert(30);
    cout<<m.findMax()<<"//findMax()"<<endl;
    cout<<"Insert(40)"<<endl;
    m.Insert(40);
    cout<<m.ExtractMax()<<"//ExtractMax()"<<endl;
    cout<<m.Replace(32)<<"//Replace(32)"<<endl;
    cout<<m.findMax()<<"//findMax()"<<endl;
    cout<<m.Size()<<"//Size()"<<endl;
    int b[]={50,12,7,9};
    cout<<"b[]={50,12,7,9}"<<endl;
    maxheap n(4,b);
    cout<<"c=merge(a,b)"<<endl;
    maxheap c=maxheap::Merge(m,n);
    cout<<c.ExtractMax()<<"//ExtractMax() of c"<<endl;
    cout<<c.ExtractMax()<<"//ExtractMax() of c"<<endl;
    cout<<c.Size()<<"//Size of c"<<endl;
    cout<<n.findMax()<<"//findMax() of b"<<endl;
    cout<<m.findMax()<<"//findMax() of a"<<endl;
    cout<<m.Size()<<"//Size() of a"<<endl;
    cout<<n.Size()<<"//Size() of b"<<endl;
    cout<<"d=meld(a,b)"<<endl;
    maxheap d=maxheap::Meld(m,n);//try meld
    cout<<d.ExtractMax()<<"//ExtractMax() of d"<<endl;
    cout<<d.findMax()<<"//FindMax() of d"<<endl;
    cout<<d.Size()<<"//Size of d"<<endl;
    cout<<n.findMax()<<"//findMax() of b"<<endl;
    cout<<m.findMax()<<"//findMax() of a"<<endl;
    cout<<m.Size()<<"//Size() of a"<<endl;
    cout<<n.Size()<<"//Size() of b"<<endl;
    cout<<"d.delete(32)"<<endl;
    d.Delete(32);
    cout<<d.Size()<<"//Size of d"<<endl;
    cout<<d.findMax()<<"//FindMax() of d"<<endl;
    d.increaseKey(5,60);
    cout<<"d.increaseKey(5,60)"<<endl;
    cout<<d.findMax()<<"//FindMax() of d"<<endl;
    d.decreaseKey(0,10);
    cout<<"d.decreaseKey(0,10)"<<endl;
    cout<<d.findMax()<<"//FindMax() of d"<<endl;

}
