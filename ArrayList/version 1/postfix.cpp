#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 2
#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

int listMaxSize;
int * list;
int length;


void initializeList()
{
	listMaxSize = LIST_INIT_SIZE;
	list = (int*)malloc(sizeof(int)*listMaxSize) ;
	length = 0 ;
}
int shrink()
{
    int * tempList ;
    if(listMaxSize==LIST_INIT_SIZE)
        return NULL_VALUE;
    if(length==listMaxSize/2)
    {
        listMaxSize=listMaxSize/2;
        tempList = (int*) malloc (listMaxSize*sizeof(int)) ;
		int i;
        for( i = 0; i < length ; i++ )
        {
            tempList[i] = list[i] ; //copy all items from list to tempList
        }
        free(list) ; //free the memory allocated before
        list = tempList ;
    };
    return SUCCESS_VALUE;
}

int searchItem(int item)
{
	int i = 0;
	for (i = 0; i < length; i++)
	{
		if( list[i] == item ) return i;
	}
	return NULL_VALUE;
}

int insertItem(int newitem)
{
	int * tempList ;
	if (length == listMaxSize)
	{
		//allocate new memory space for tempList
		listMaxSize = 2 * listMaxSize ;
		tempList = (int*) malloc (listMaxSize*sizeof(int)) ;
		int i;
        for( i = 0; i < length ; i++ )
        {
            tempList[i] = list[i] ; //copy all items from list to tempList
        }
        free(list) ; //free the memory allocated before
        list = tempList ; //make list to point to new memory
	};
	if(length==0)
    {
        initializeList();
    }

	list[length] = newitem ; //store new item
	length++ ;
	return SUCCESS_VALUE ;
}
int insertItemAt(int pos,int newitem)
{
    if(pos>=length)
        return NULL_VALUE;
	int * tempList ;
	if (length == listMaxSize)
	{
		//allocate new memory space for tempList
		listMaxSize = 2 * listMaxSize ;
		tempList = (int*) malloc (listMaxSize*sizeof(int)) ;
		int i;
        for( i = 0; i < length ; i++ )
        {
            tempList[i] = list[i] ; //copy all items from list to tempList
        }
        free(list) ; //free the memory allocated before
        list = tempList ; //make list to point to new memory
	};

	int temp;
	temp=newitem;
	newitem=list[pos];
	list[pos]=temp;
	for(int i=pos+1;i<length;i++)
    {
        temp=newitem;
        newitem=list[i];
        list[i]=temp;
    }
    list[length] = newitem ; //store new item
	length++ ;
	return SUCCESS_VALUE ;
}


int deleteItemAt(int position) //version 2, do not preserve order of items
{
	if ( position >= length ) return NULL_VALUE;
	list[position] = list[length-1] ;
	length-- ;
	shrink();
	return SUCCESS_VALUE;
}
int deleteLast() //version 2, do not preserve order of items
{
	if ( length==0 ) return NULL_VALUE;
	length-- ;
	shrink();
	return SUCCESS_VALUE ;
}
void deleteall()
{
    initializeList();
}

int deleteItem(int item)
{
	int position;
	position = searchItem(item) ;
	if ( position == NULL_VALUE ) return NULL_VALUE;
	deleteItemAt(position) ;
	return SUCCESS_VALUE ;
}
void Clear()
{
    free(list);
    length=0;
    listMaxSize=LIST_INIT_SIZE;
}

void printList()
{
    int i;
    for(i=0;i<length;i++)
        printf("%d ", list[i]);
    printf("Current size: %d, current length: %d\n", listMaxSize, length);
}
int getLength()
{
    return length;
}


int main(void)
{
    initializeList();
    char c;
    int temp;
    scanf("%c",&c);
    while(c!='\n')
    {
        if(c>='0'&&c<='9')
        {
            insertItem(c-48);

        }
        else if(c=='+')
        {
            temp=list[length-2]+list[length-1];
            deleteLast();
            deleteLast();
            insertItem(temp);
        }
        else if(c=='-')
        {
            temp=list[length-2]-list[length-1];
            deleteLast();
            deleteLast();
            insertItem(temp);
        }
        else if(c=='/')
        {
            temp=list[length-2]/list[length-1];
            deleteLast();
            deleteLast();
            insertItem(temp);
        }
        else if(c=='*')
        {
            temp=list[length-2]*list[length-1];
            deleteLast();
            deleteLast();
            insertItem(temp);
        }
        scanf("%c",&c);


    }
    printf("%d",list[0]);


}
