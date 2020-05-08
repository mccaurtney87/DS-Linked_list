#include <iostream>

using namespace std;

class Node 
{
    public:
        Node *prev;
        int data;
        Node *next;
};

class LL
{
    private:   
        Node *first; 
    public:    
        LL(){first=NULL;}    
        LL(int A[],int n);    
        ~LL();        
        void Display();
        int Length();    
        void Insert(int index,int x);    
        void Delete(int index);    
        void Reverse();
        Node * Search(int key);
}; 


//Creation of doubly linked list using array(Parameterised Constructor);
LL::LL(int A[],int n)
{
    Node *last,*t;
    int i=0;
    first=new Node;
    first->data=A[0];    
    first->prev = first->next = NULL;    
    last=first; 
    
    for(i=1; i<n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

//Destructor
LL::~LL() 
{    
    Node *p=first;
    while(first)    
    {        
        first=first->next;        
        delete p;        
        p=first;    
    }
}

//Prints the list
void LL::Display()
{   
    cout<<"\n\n";
    Node *p = first;
    while(p)
    {
        cout<<p->data<<"\n";
        p = p->next;
    }
}

//counts number of nodes
int LL::Length()
{
    Node *p = first;
    int length = 0;
    while(p)
    {
        length++;
        p = p->next;
    }
    return(length);
}

void LL::Insert(int index,int x)
{
    int i;
    Node *p = first;
    Node *t = new Node;
    if(index<0 || index>Length())
        return;
    if(index==0)
    {
        t->data = x;
        t->prev = p;
        t->next = p;
        p->prev = t;
        p = t;
    }
    else
    {
        t->data = x;
        for(i=0;i<index-1;i++)
            p = p->next;
        t->next = p->next;
        t->prev = p;
        if(p->next)
            (p->next)->prev = t;
        p->next = t;
    }
}

void LL::Delete(int index)
{
    int i;
    Node *p = first;
    if(index < 1 || index > Length())
        return;
    if(index==0)
    {
        first = first->next;
        delete p;
        if(first)
            first->prev = NULL;
    }
    else
    {
        for(i=0; i<index-1; i++)
            p = p->next;
        (p->prev)->next = p->next;
        if(p->next)
            (p->next)->prev = p->prev;
        delete p;
    }
}

void LL::Reverse()
{
    Node *temp;
    Node *p = first;
    while(p)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = temp;
        if(p!=NULL && p->next==NULL)
            first = p;
    }
}

Node * LL::Search(int key)
{
    Node *p = first;
    while(p)
    {
        if(key==p->data)
            return(p);
        p=p->next;
    }
    return(p);
}

int main()
{
    int A[]={1,2,3,4,5};
    LL l(A,5);
    l.Insert(4,8);
    l.Display();
    l.Delete(3);
    Node *a = l.Search(8);
    if(a)
        cout<<"\nKey found";
    else
        cout<<"Not found";
    l.Reverse();
    l.Display();
    return 0; 
}