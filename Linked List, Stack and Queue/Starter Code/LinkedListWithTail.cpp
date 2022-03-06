#include<stdio.h>
#include<stdlib.h>


#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

class ListNode
{
public:
    int item;
    ListNode * next;
};

class LinkedListWithTail
{
    ListNode * list;
    ListNode * tail;
    int length;

public:
    LinkedListWithTail()
    {
        list = 0;  //initially set to NULL
        tail = 0;
        length=0;
    }

    int getLength()
    {
        return length;
    }

    //add required codes to set up tail pointer
    int insertItem(int item) //insert at the beginning
    {
        ListNode * newNode ;
        newNode = new ListNode() ;
        newNode->item = item ;
        newNode->next = list ; //point to previous first node
        list = newNode ; //set list to point to newnode as this is now the first node
        length++;
        if(tail==0)
            tail=newNode;
        return SUCCESS_VALUE ;
    }

    //add required codes to set up tail pointer
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
             if(temp==tail)
                tail=0;
            list = list->next ;
            delete temp ;
            length--;
        }
        else
        {
            if(temp==tail)
                tail=prev;
            prev->next = temp->next ;
            delete temp;
            length--;
        }
        return SUCCESS_VALUE ;
    }

    //add required codes to set up tail pointer
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
        printf("Length: %d\n",getLength());
    }

    //------------write code for the functions below-----------
    int insertLast(int item)
    {
        if(length==0)
        {
            insertItem(item);
            return SUCCESS_VALUE;

        }

        ListNode * newNode ;
        newNode = new ListNode() ;
        newNode->item = item ;
        tail->next=newNode;
        tail=newNode;
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

    int deleteLast()
    {
        if(length==0)
            return NULL_VALUE;

        ListNode * temp;
        temp = list;
        if(length==1)
        {
            list=0;
            tail=0;
            delete temp;
            length--;
            return SUCCESS_VALUE;

        }
        for(int i=2;i<length;i++)
            temp=temp->next;
        ListNode * temp2;
        temp2 = tail;
        tail=temp;
        delete temp2;
        tail->next=new ListNode;
        tail->next=0;
        length--;
        return SUCCESS_VALUE;

    }
};

int main(void)
{
    LinkedListWithTail ll;

    while(1)
    {
        printf("1. Insert new item. 2. Delete item. 3. Search item. \n");
        printf("4. Insert Last. 5. Print. 6. Delete last. 7.getItemAt 8.Exit\n");


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
        else if(ch==5)
        {
            ll.printList();
        }
        else if(ch==4)
        {
            int item;
            scanf("%d", &item);
            ll.insertLast(item);
        }
        else if(ch==6)
        {
           ll.deleteLast();

        }
        else if(ch==7)
        {
            int i;
            scanf("%d", &i);
            printf("%d\n",ll.getItemAt(i)->item);
        }
         else if(ch==8)
        {
           break;

        }
    }

}
