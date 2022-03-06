#include<stdio.h>
#include<stdlib.h>
#define NULL_VALUE -999999
#define INFINITY 999999
#define WHITE 0
#define GREY 1
#define BLACK 2
#define SUCCESS_VALUE 99999
class ListNode
{
public:
    int item;
    ListNode * next;
    void printNode()
    {
        printf("%d\n",item);
    }
};

class LinkedList
{

    ListNode * list;
    int length;

public:
    LinkedList()
    {
        list=0; //initially set to NULL
        length=0;
    }


    int getLength()
    {
        return length;
    }

    int insertItem(int item) //insert at the beginning
    {
        ListNode * newNode = new ListNode() ;
        newNode->item = item ;
        newNode->next = list ; //point to previous first node
        list = newNode ; //set list to point to newnode as this is now the first node
        length++;
        return SUCCESS_VALUE ;
    }

    int deleteItem(int item)
    {
        ListNode *temp, *prev ;
        temp = list ; //start at the beginning
        while (temp != 0)
        {
            if (temp->item == item) break ;
            prev = temp;
            temp = temp->next ; //move to next node
        }
        if (temp == 0) return NULL_VALUE ; //item not found to delete
        if (temp == list) //delete the first node
        {
            list = list->next ;
            delete temp;
            length--;
        }
        else
        {
            prev->next = temp->next ;
            delete temp;
            length--;
        }
        return SUCCESS_VALUE ;
    }


    ListNode * searchItem(int item)
    {
        ListNode * temp ;
        temp = list ; //start at the beginning
        while (temp != 0)
        {
            if (temp->item == item) return temp ;
            temp = temp->next ; //move to next node
        }
        return 0 ; //0 means invalid pointer in C, also called NULL value in C
    }

    void printList()
    {
        ListNode * temp;
        temp = list;
        while(temp!=0)
        {
            printf("%d->", temp->item);
            temp = temp->next;
        }
        printf("\n");
        printf("Length: %d\n",length);
    }

    //------------write code for the functions below-----------

    int insertLast(int item)
    {
        ListNode * newNode = new ListNode() ;
        newNode->item = item ;
        if(list==0)
        {
            list=newNode;
            length++;
            return SUCCESS_VALUE;
        }

        ListNode * temp ;
        temp = list ; //start at the beginning
        while (temp->next != 0)
        {
            temp = temp->next ; //move to next node
        }
        temp->next=newNode;
        length++;
        return SUCCESS_VALUE;
    }

    int insertAfter(int oldItem, int newItem)
    {
        ListNode *temp=searchItem(oldItem);
        if(temp==0)
            return NULL_VALUE;
        ListNode * newNode = new ListNode() ;
        newNode->item = newItem ;
        newNode->next=temp->next;
        temp->next=newNode;
        length++;
        return SUCCESS_VALUE;
    }

    ListNode * getItemAt(int pos)
    {
        if(pos>length||pos<=0)
            return 0;
        ListNode * temp ;
        temp = list ;
        for(int i=1;i<pos;i++)
            temp=temp->next;
        return temp;

    }

    int deleteFirst()
    {
        if(list==0||length==0)
            return NULL_VALUE;
        ListNode *temp=list;
        list=list->next;
        length--;
        delete temp;
        free(temp);
        return SUCCESS_VALUE;
    }


    ~LinkedList()
    {
       ListNode *temp=list;
        while(list!=0)
        {
            temp=list;
            list=list->next;
            delete temp;
        }
        free(temp);
        free(list);
        //printf("Destructor Called");
    }

};
class Stack
{
    LinkedList ll;
public:
    Stack()
    {

    }
    void push(int item)
    {
        //write your codes here
        ll.insertItem(item);
    }
    int pop()
    {
        //write your codes here
        ListNode * temp ;
        temp=ll.getItemAt(1);
        int a=NULL_VALUE;
        if(temp!=0)
            a=temp->item;
        else
            printf("The Stack Is Empty");
        ll.deleteFirst();
        return a;
    }
    int top()
    {
        //write your codes here
        ListNode * temp ;
        temp=ll.getItemAt(1);
        int a=NULL_VALUE;
        if(temp!=0)
            a=temp->item;
        return a;
    }
    bool isEmpty()
    {
        if(ll.getItemAt(1)==0)
            return true;
        return false;
    }
    void print()
    {
        ll.printList();
    }
};
class Queue
{
    int queueInitSize ;
    int queueMaxSize;
    int * data;
    int length;
    int front;
    int rear;
public:
    Queue();
    ~Queue();
    void enqueue(int item); //insert item in the queue
    int dequeue(); //returns the item according to FIFO
    bool empty(); //return true if Queue is empty
};

Queue::Queue()
{
    queueInitSize = 2 ;
    queueMaxSize = queueInitSize;
    data = new int[queueMaxSize] ; //allocate initial memory
    length = 0 ;
    front = 0;
    rear = 0;
}


void Queue::enqueue(int item)
{
	if (length == queueMaxSize)
	{
		int * tempData ;
		//allocate new memory space for tempList
		queueMaxSize = 2 * queueMaxSize ;
		tempData = new int[queueMaxSize] ;
		int i, j;
		j = 0;
		for( i = rear; i < length ; i++ )
		{
			tempData[j++] = data[i] ; //copy items from rear
		}
		for( i = 0; i < rear ; i++ )
		{
			tempData[j++] = data[i] ; //copy items before rear
		}
		rear = 0 ;
		front = length ;
		delete[] data ; //free the memory allocated before
		data = tempData ; //make list to point to new memory
	}

	data[front] = item ; //store new item
	front = (front + 1) % queueMaxSize ;
	length++ ;
}


bool Queue::empty()
{
	if(length == 0) return true ;
	else return false ;
}


int Queue::dequeue()
{
	if(length == 0) return NULL_VALUE ;
	int item = data[rear] ;
	rear = (rear + 1) % queueMaxSize ;
	length-- ;
	return item ;
}


Queue::~Queue()
{
    if(data) delete[] data; //deallocate memory
    data = 0; //set to NULL
}

//****************Queue class ends here************************


//******************Graph class starts here**************************
class Graph
{
	int nVertices, nEdges ;
	bool directed ;
	int ** matrix ; //adjacency matrix to store the graph
	//define other variables required for bfs such as color, parent, and dist
	//you must use pointers and dynamic allocation
	int *color,*parent,*distance,*p,*c,*dt,*ft,time;

public:
	Graph(bool dir = false);
	~Graph();
	void setnVertices(int n);
	void addEdge(int u, int v);
	void removeEdge(int u, int v);
	bool isEdge(int u, int v);
    int getDegree(int u);
    bool hasCommonAdjacent(int u, int v);
    int getDist(int u, int v);
    void printGraph();
	void bfs(int source); //will run bfs in the graph
	void visit(int u);
    void dfs();
};


Graph::Graph(bool dir)
{
	nVertices = 0 ;
	nEdges = 0 ;
	matrix = 0 ;
	directed = dir ; //set direction of the graph
	//define other variables to be initialized
	color=0;
	distance=0;
	parent=0;
	p=0;
	c=0;
	dt=0;
	ft=0;
}

void Graph::setnVertices(int n)
{
	this->nVertices = n ;

	//allocate space for the matrix
    matrix = new int*[nVertices];
    for(int i=0;i<nVertices;i++)
    {
        matrix[i] = new int[nVertices];
        for(int j=0;j<nVertices;j++)
            matrix[i][j] = 0; //initialize the matrix cells to 0
    }

}

void Graph::addEdge(int u, int v)
{
    //write your code here
    if(u<0 || u>=nVertices || v<0 || v>=nVertices) return;
    matrix[u][v] = 1;
    if(!directed) matrix[v][u] = 1;
    nEdges++;

}

void Graph::removeEdge(int u, int v)
{
    //write this function
    if(u<0 || u>=nVertices || v<0 || v>=nVertices) return;
    matrix[u][v] = 0;
    if(!directed) matrix[v][u] = 0;
    nEdges--;
}

bool Graph::isEdge(int u, int v)
{
    //returns true if (u,v) is an edge, otherwise should return false
    if(u<0 || u>=nVertices || v<0 || v>=nVertices) return false;
    if(matrix[u][v]==1)
        return true;
    return false;
}

int Graph::getDegree(int u)
{
    //returns the degree of vertex u
    if(u<0 || u>=nVertices) return NULL_VALUE;
    int degree=0;
    for(int j=0;j<nVertices;j++)
    {
        if(matrix[u][j]==1)
            degree++;
    }
    return degree;
}

bool Graph::hasCommonAdjacent(int u, int v)
{
    //returns true if vertices u and v have common adjacent vertices
    if(u<0 || u>=nVertices || v<0 || v>=nVertices) return false;
    for(int j=0;j<nVertices;j++)
    {
        if(matrix[u][j]==1&&matrix[v][j]==1)
            return true;
    }
    return false;

}

void Graph::bfs(int source)
{
    //complete this function
    //initialize BFS variables
    int u,v;
    if(color)
        delete[] color;
    if(distance)
        delete [] distance;
    if(parent)
        delete [] parent;
    color=new int[nVertices];
    parent=new int[nVertices];
    distance=new int[nVertices];

    for(int i=0; i<nVertices; i++)
    {
        color[i] = WHITE ;
        parent[i] = -1 ;
        distance[i] = INFINITY ;
    }
    Queue q ;
    color[source] = GREY;
    distance[source] = 0 ;
    q.enqueue(source) ;
    printf("Node=%d Parent=%d Distance=%d Grey\n",source,parent[source],distance[source]);
    while( !q.empty() )
    {
        //complete this part
        u=q.dequeue();
        for(v=0;v<nVertices;v++)
        {
            if(isEdge(u,v))
            {
                if(color[v]==WHITE)
                {
                    color[v]=GREY;
                    distance[v]=distance[u]+1;
                    parent[v]=u;
                    q.enqueue(v);
                    printf("Node:%d Parent:%d Distance:%d Grey\n",v,parent[v],distance[v]);

                }
            }
        }
        color[u]=BLACK;
        printf("Node:%d Parent:%d Distance:%d black\n",u,parent[u],distance[u]);
    }

}

void Graph::dfs()
{
    //write this function
    Stack st;
    if(c)
        delete[] c;
    if(p)
        delete [] p;
    if(dt)
        delete [] dt;
    if(ft)
        delete [] ft;
    c=new int[nVertices];
    p=new int[nVertices];
    dt=new int[nVertices];
    ft=new int[nVertices];
    int u,v;
    for(u=0;u<nVertices;u++)
    {
        c[u]=WHITE;
        p[u]=NULL_VALUE;
    }
    time=0;
    for(u=0;u<nVertices;u++)
    {
        if(c[u]==WHITE)
        {
            time=time+1;
            dt[u]=time;
            c[u]=GREY;
            printf("Node:%d Discovery time:%d Color:Grey\n",u,dt[u]);
            st.push(u);
            while(!st.isEmpty())
            {
                u=st.top();
                for(int v=0;v<nVertices;v++)
                {
                    if(isEdge(u,v)&&c[v]==WHITE)
                    {
                        time=time+1;
                        p[v]=u;
                        st.push(v);
                        dt[v]=time;
                        c[v]=GREY;
                        printf("Node:%d Discovery time:%d Color:Grey\n",v,dt[v]);
                        break;
                    }
                }
                if(u==st.top())
                {
                    c[u]=BLACK;
                    time=time+1;
                    ft[u]=time;
                    printf("Node:%d Finish time:%d Color:Black\n",u,ft[u]);
                    st.pop();
                }
            }
        }

    }

}

int Graph::getDist(int u, int v)
{
    //returns the shortest path distance from u to v
    //must call bfs using u as the source vertex, then use distance array to find the distance
    if(u<0 || u>=nVertices || v<0 || v>=nVertices) return INFINITY;
    bfs(u);
    return distance[v];
    return INFINITY ;
}


void Graph::printGraph()
{
    printf("\nNumber of vertices: %d, Number of edges: %d\n", nVertices, nEdges);
    for(int i=0;i<nVertices;i++)
    {
        printf("%d:", i);
        for(int j=0; j<nVertices;j++)
        {
            if(matrix[i][j]==1)
                printf(" %d", j);
        }
        printf("\n");
    }
}

Graph::~Graph()
{
    //write your destructor here
     if(c)
        delete[] c;
        c=0;
    if(p)
        delete [] p;
        p=0;
    if(dt)
        delete [] dt;
        dt=0;
    if(ft)
        delete [] ft;
        ft=0;
    if(parent)
        delete[] parent;
        parent=0;
    if(color)
        delete[] color;
        color=0;
    if(distance)
        delete[] distance;
        distance=0;
    if(matrix)
        {
            for(int i=0;i<nVertices;i++)
            {
                delete[] matrix[i];
            }
            delete[] matrix;
        }
        matrix=0;
}


//**********************Graph class ends here******************************


//******main function to test your code*************************
int main(void)
{
    int n;
    Graph g;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    g.setnVertices(n);

    while(1)
    {
        printf("1. Add edge. 2.is Edge 3.Get Degree\n");
        printf("4. has Common Adj. 5. Print Graph  6. Exit.\n");
        printf("7. bfs. 8.Shortest Distance 9.dfs 10.Remove Edge\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            g.addEdge(u, v);
        }
        else if(ch==2)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            if(g.isEdge(u,v))
                printf("They are an Edge\n");
            else
                printf("They are not Edge\n");

        }
        else if(ch==3)
        {
            int u;
            scanf("%d", &u);
            printf("%d\n",g.getDegree(u));

        }
        else if(ch==4)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            if(g.hasCommonAdjacent(u,v))
                printf("They have common Adjacent\n");
            else
                printf("They haven't common Adjacent\n");

        }
        else if(ch==5)
        {
            g.printGraph();
        }
        else if(ch==6)
        {
            break;
        }
        else if(ch==7)
        {
            int u;
            scanf("%d", &u);
            g.bfs(u);
        }
        else if(ch==8)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            printf("Distance=%d\n",g.getDist(u,v));
        }
        else if(ch==9)
        {
            g.dfs();
        }
        if(ch==10)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            g.removeEdge(u, v);
        }
    }

}

