#include<stdio.h>
#include<stdlib.h>


#define NULL_VALUE -99999
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

int main(void)
{
    LinkedList ll;

    while(1)
    {
        printf("1. Insert new item. 2. Delete item. 3. Search item. \n");
        printf("4. Insert Last. 5. Print. 6. exit.\n");
        printf("7. Insert After. 8. Get Item At. 9. Delete First.\n");


        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            ll.insertItem(item);
        }
        else if(ch==2)
        {
            int item;
            scanf("%d", &item);
            ll.deleteItem(item);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            ListNode * res = ll.searchItem(item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch==4)
        {
            int item;
            scanf("%d", &item);
            ll.insertLast(item);
        }
        else if(ch==5)
        {
            ll.printList();
        }
        else if(ch==6)
        {
            break;
        }
        else if(ch==7)
        {
            int oi,ni;
            scanf("%d%d",&oi,&ni);
            ll.insertAfter(oi,ni);
        }
        else if(ch==8)
        {
            int i;
            scanf("%d",&i);
            ListNode *p=ll.getItemAt(i);
            if(p==0)
                printf("Index Out of Bound\n");
            else
            p->printNode();
        }
        else if(ch==9)
        {
            ll.deleteFirst();
        }

    }


}
