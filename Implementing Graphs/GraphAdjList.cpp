#include<stdio.h>
#include<stdlib.h>
#define NULL_VALUE -999999
#define INFINITY 999999
#define WHITE 1
#define GREY 2
#define BLACK 3

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

//****************Dynamic ArrayList class based************************
class ArrayList
{
	int * list;
	int length ;
	int listMaxSize ;
	int listInitSize ;
public:
	ArrayList() ;
	~ArrayList() ;
	int searchItem(int item) ;
    void insertItem(int item) ;
	void removeItem(int item) ;
	void removeItemAt(int item);
	int getItem(int position) ;
	int getLength();
	bool empty();
	void printList();
} ;


ArrayList::ArrayList()
{
	listInitSize = 2 ;
	listMaxSize = listInitSize ;
	list = new int[listMaxSize] ;
	length = 0 ;
}

void ArrayList::insertItem(int newitem)
{
	int * tempList ;
	if (length == listMaxSize)
	{
		//allocate new memory space for tempList
		listMaxSize = 2 * listMaxSize ;
		tempList = new int[listMaxSize] ;
		int i;
        for( i = 0; i < length ; i++ )
        {
            tempList[i] = list[i] ; //copy all items from list to tempList
        }
        delete[] list ; //free the memory allocated before
        list = tempList ; //make list to point to new memory
	};

	list[length] = newitem ; //store new item
	length++ ;
}

int ArrayList::searchItem(int item)
{
	int i = 0;
	for (i = 0; i < length; i++)
	{
		if( list[i] == item ) return i;
	}
	return NULL_VALUE;
}

void ArrayList::removeItemAt(int position) //do not preserve order of items
{
	if ( position < 0 || position >= length ) return ; //nothing to remove
	list[position] = list[length-1] ;
	length-- ;
}


void ArrayList::removeItem(int item)
{
	int position;
	position = searchItem(item) ;
	if ( position == NULL_VALUE ) return ; //nothing to remove
	removeItemAt(position) ;
}


int ArrayList::getItem(int position)
{
	if(position < 0 || position >= length) return NULL_VALUE ;
	return list[position] ;
}

int ArrayList::getLength()
{
	return length ;
}

bool ArrayList::empty()
{
    if(length==0)return true;
    else return false;
}

void ArrayList::printList()
{
    int i;
    for(i=0;i<length;i++)
        printf("%d ", list[i]);
    printf("Current size: %d, current length: %d\n", listMaxSize, length);
}

ArrayList::~ArrayList()
{
    if(list) delete [] list;
    list = 0 ;
}

//******************ArrayList class ends here*************************

//******************Graph class starts here**************************
class Graph
{
	int nVertices, nEdges ;
	bool directed ;
	ArrayList  * adjList ;
	int *color,*parent,*distance,*p,*c,*dt,*ft,time;
	//define other variables required for bfs such as color, parent, and dist
	//you must use pointers and dynamic allocation

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
	void dfs(int source); //will run dfs in the graph
	void visit(int u);
	void dfs();
};


Graph::Graph(bool dir)
{
	nVertices = 0 ;
	nEdges = 0 ;
	adjList = 0 ;
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
	if(adjList!=0) delete[] adjList ; //delete previous list
	adjList = new ArrayList[nVertices] ;
}

void Graph::addEdge(int u, int v)
{
    if(u<0 || v<0 || u>=nVertices || v>=nVertices) return; //vertex out of range
    this->nEdges++ ;
	adjList[u].insertItem(v) ;
	if(!directed) adjList[v].insertItem(u) ;
}

void Graph::removeEdge(int u, int v)
{
    //write this function
     if(u<0 || v<0 || u>=nVertices || v>=nVertices) return; //vertex out of range
    this->nEdges-- ;
	adjList[u].removeItem(v) ;
	if(!directed) adjList[v].removeItem(u) ;
}

bool Graph::isEdge(int u, int v)
{
    //returns true if (u,v) is an edge, otherwise should return false
     if(u<0 || v<0 || u>=nVertices || v>=nVertices) return false;
     int t=adjList[u].searchItem(v);
     if(t!=NULL_VALUE)
        return true;
     return false;
}

int Graph::getDegree(int u)
{
    //returns the degree of vertex u
    return adjList[u].getLength();
}

bool Graph::hasCommonAdjacent(int u, int v)
{
    //returns true if vertices u and v have common adjacent vertices
    int l=adjList[u].getLength();
    for(int i=0;i<l;i++)
    {
        if(isEdge(v,adjList[u].getItem(i)))
            return true;
    }
    return false;

}

void Graph::bfs(int source)
{
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
    //complete this function
    //initialize BFS variables
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
            visit(u);
        }

    }

}
void Graph::visit(int u)
{
    time=time+1;
    dt[u]=time;
    c[u]=GREY;
    printf("Node:%d Discovery time:%d Color:Grey\n",u,dt[u]);
    for(int v=0;v<nVertices;v++)
    {
        if(isEdge(u,v)&&c[v]==WHITE)
        {
            p[v]=u;
            visit(v);
        }
    }
    c[u]=BLACK;
    time=time+1;
    ft[u]=time;
    printf("Node:%d Finish time:%d Color:Black\n",u,ft[u]);
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
        for(int j=0; j<adjList[i].getLength();j++)
        {
            printf(" %d", adjList[i].getItem(j));
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
    if(adjList)
    {
            delete[] adjList;
    }
        adjList=0;
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
