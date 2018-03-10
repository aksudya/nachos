
#include "dllist.h"

DLLElement::DLLElement(void *itemPtr, int sortKey)
{
	//currentThread->Yield();		//error
    item=itemPtr;
    //currentThread->Yield();		//error
    key=sortKey;
    //currentThread->Yield();		//error
    prev=NULL;
    //currentThread->Yield();		//error
    next=NULL;
    //currentThread->Yield();		//error
}

DLList::DLList()
{
    first=NULL;
    last=NULL;
}

DLList::~DLList()
{

}

bool DLList::IsEmpty()
{
    if(first==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void DLList::Prepend(void *item)
{
    if(this->IsEmpty())
    {
        DLLElement *temp=new DLLElement(item,START_KEY);
        temp->prev=NULL;
        temp->next=NULL;
        first=temp;
        last=temp;
    }
    else
    {
        DLLElement *temp=new DLLElement(item,first->key-1);

        temp->prev=NULL;
        temp->next=first;
        first->prev=temp;
        first=temp;
    }
}

void DLList::Append(void *item)
{
    if(this->IsEmpty())
    {
        DLLElement *temp=new DLLElement(item,START_KEY);
        temp->prev=NULL;
        temp->next=NULL;
        first=temp;
        last=temp;
    }
    else
    {
        DLLElement *temp=new DLLElement(item,last->key+1);
        temp->prev=last;
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }
}

void *DLList::Remove(int *keyPtr)
{
    void *RemovedItem;
    if(this->IsEmpty())
    {
    	//currentThread->Yield();
        keyPtr=NULL;
        //currentThread->Yield();
        return NULL;
    }
    else
    {
    	//currentThread->Yield();
        *keyPtr=first->key;
        //currentThread->Yield();
        RemovedItem=first->item;
        //currentThread->Yield();
        first=first->next;
        //currentThread->Yield();
        if(first==NULL)
        {
        	//currentThread->Yield();
            last = NULL;
            //currentThread->Yield();
        }
        else
        {
        	//currentThread->Yield();		//error
            first->prev=NULL;
            //currentThread->Yield();
        }
    }
    return RemovedItem;
}

void DLList::SortedInsert(void *item, int sortKey)
{
    if(this->IsEmpty())
    {
        DLLElement *temp=new DLLElement(item,sortKey);
        temp->prev=NULL;
        //currentThread->Yield();
        temp->next=NULL;
        //currentThread->Yield();
        first=temp;
        last=temp;
    }
    else
    {
    	//currentThread->Yield();
        DLLElement *temp=new DLLElement(item,sortKey);
        //currentThread->Yield();
        DLLElement *find=first;
        //currentThread->Yield();					//error
        while (find!=NULL&&sortKey>=find->key  )
        {
        	//currentThread->Yield();				//error
            find=find->next;
            //currentThread->Yield();				//error
        }
        if(find==NULL)
        {
            if(this->IsEmpty())
            {
                temp->prev=NULL;
                temp->next=NULL;
                //currentThread->Yield();
                first=temp;
                //currentThread->Yield();
                last=temp;
            }
            else
            {
                //currentThread->Yield();
                temp->prev=last;
                //currentThread->Yield();			//error
                temp->next=NULL;
                //currentThread->Yield();			//error
                last->next=temp;
                //currentThread->Yield();      		//error
                last=temp;
            }
        }
        else if(find==first)
        {
            if(this->IsEmpty())
            {
                temp->prev=NULL;
                temp->next=NULL;
                first=temp;
                last=temp;
            }
            else
            {
                temp->prev=NULL;
                temp->next=first;
                first->prev=temp;
                first=temp;
            }
        }
        else
        {

        	//currentThread->Yield();				//error
            temp->prev=find->prev;
            //currentThread->Yield();				//error
            find->prev->next=temp;
            //currentThread->Yield();				//error
            find->prev=temp;
            //currentThread->Yield();				//error
            temp->next=find;
            //currentThread->Yield();
        }
    }
}

void *DLList::SortedRemove(int sortKey)
{
    void *ReturnItem;
    if(this->IsEmpty())
    {
        return NULL;
    }
    else
    {
        DLLElement *find=first;
        while (find!=NULL&&sortKey!=find->key)
        {
            find=find->next;
        }
        if(find==NULL)
        {
            return NULL;
        }
        else
        {
            ReturnItem=find->item;
            if(find==first)
            {
                int *key;
                this->Remove(key);
            }
            else if(find==last)
            {
                last=last->prev;
                last->next=NULL;
                if(last==NULL)
                {
                    first = NULL;
                }
            }
            else
            {
                find->prev->next=find->next;
                find->next->prev=find->prev;
            }
            return ReturnItem;
        }
    }

}
