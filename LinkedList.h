#include<iostream>

class Node
{
    public:
    int data;
    Node *next;
};

class LinkedList : public Node
{
private:
    /* data */
    Node *head;

public:
    LinkedList();
    ~LinkedList();
    void add(int new_data);
    void add(int pos, int new_data);
    void removeFirst();
    void removeLast();
    void removeAt(int pos);
    void clear();
    void printList();
};

LinkedList::LinkedList()
{
    this->head = NULL;
}

LinkedList::~LinkedList()
{
}

/*
Inserts the element at the last(append) of the list
*/
void LinkedList::add(int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    if(this->head==NULL)
        this->head = new_node;
    else{
        Node *temp;
        temp = this->head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = NULL;
    }
}

/*
Inserts at last when the required position is larger than the linked list size, otherwise inserts at
the required position
*/
void LinkedList::add(int pos, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    int ctr=0;
    if(this->head == NULL)
        this->head = new_node;
    else{
        if(pos==1)
        {
            new_node->next = this->head;
            this->head = new_node;
        }
        else{
            Node *temp;
            temp = this->head;
            while(temp->next!=NULL)
            {
                ctr++;
                if(ctr == (pos-1))
                {
                    new_node->next = temp->next;
                    temp->next = new_node;
                }
                temp = temp->next;
            }
            if(pos >= ctr+1)
            {
                add(new_data);
            }
        }
    }
}
/*
prints the data in the linked list
*/
void LinkedList::printList()
{
    Node *temp;
    temp = this->head;
    if(temp==NULL)
        std::cout<<"Error: Nothing to print. LinkedList is empty!\n";
    else{
        while(temp!=NULL)
        {
            std::cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
}

/*
Removes the first element of the linked list
*/
void LinkedList::removeFirst()
{
    if(this->head==NULL)
        std::cout<<"Error: Nothing to delete. LinkedList is empty!\n";
    else if((this->head)->next==NULL)
    {
        this->head = NULL;
        free(this->head);
    }
    else
        this->head = this->head->next;
}

/*
Removes the last element of the linked list
*/
void LinkedList::removeLast()
{
    Node *temp;
    temp = this->head;
    if(temp == NULL)
        std::cout<<"Error: Nothing to delete. LinkedList is empty!\n";
    else if(temp->next == NULL)
    {
        temp = NULL;
        free(temp);
    }
    else{
        while(temp->next->next!=NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

/*
Removes the last element when the specified position is larger than the linked list size, otherwise removes the
element at the specified position
*/
void LinkedList::removeAt(int pos)
{
    Node *temp, *store;
    temp = this->head;
    int ctr=0;
    if(temp==NULL)
        std::cout<<"Error: Nothing to delete. LinkedList is empty!\n";
    else if(temp->next == NULL)
    {
        temp=NULL;
        free(temp);
    }
    else{
        if(pos==1)
        {
            removeFirst();
        }
        else{
            while(temp!=NULL)
            {
                ctr++;
                if(ctr == (pos-1))
                {
                    store = temp->next->next;
                    free(temp->next);
                    temp->next = store;
                }
                temp = temp->next;
            }
        }
    }
}

/*
Deletes the entire linked list
*/
void LinkedList::clear()
{
    Node *temp, *next_node;
    temp = this->head;
    while(temp!=NULL)
    {
        next_node = temp->next;
        free(temp);
        temp = next_node;
    }
    this->head = NULL;
}

