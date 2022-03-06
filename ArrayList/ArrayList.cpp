#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 2
#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

int listMaxSize;
int * list;
int length;
int isClear=0;

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
	if(isClear==-1)
    {
        initializeList();
        isClear=0;
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
    listMaxSize = LIST_INIT_SIZE;
    length=0;
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
    isClear=-1;
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
    while(1)
    {
        printf("1. Insert new item. 2. Delete item at. 3. Delete item.\n");
        printf("4. Insert item at. 5. Print. 6. Get length.\n");
        printf("7. delete last item. 8. Clear. 9. DeleteAll. 0.Exit\n");
        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            insertItem(item);
        }
        else if(ch==2)
        {
            int pos;
            scanf("%d", &pos);
            deleteItemAt(pos);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            deleteItem(item);
        }
        else if(ch==5)
        {
            printList();
        }
        else if(ch==4)
        {
            int item,position;
            scanf("%d%d",&position,&item);
            insertItemAt(position,item);
        }
        else if(ch==6)
        {
            printf("%d\n",getLength());
        }
        else if(ch==7)
        {
            deleteLast();
        }
        else if(ch==8)
        {
            Clear();
        }
         else if(ch==9)
        {
            deleteall();
        }
         else if(ch==0)
        {
            break;
        }
    }

}
