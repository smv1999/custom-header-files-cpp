#include<iostream>
#include<string>
typedef long long int LLI;

struct array
{
    int size;
    int *arr;
};

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
    void clear();
    bool contains(int data);
    LLI get(int index);
    LLI getFirst();
    LLI getLast();
    LLI getMiddle();
    int printList();
    void removeFirst();
    void removeLast();
    void removeAt(int pos);
    void reverse();
    int size();
    array toArray();
    std::string toString();
};

LinkedList::LinkedList()
{
    this->head = NULL;
}

LinkedList::~LinkedList()
{
    if(!this->head)
        free(this->head);
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


/*
Returns true if the list contains the specified element
*/
bool LinkedList::contains(int data)
{
    Node *temp;
    temp = this->head;
    while(temp!=NULL)
    {
        if(temp->data == data)
            return true;
        temp = temp->next;
    }
    return false;
}

/*
Returns the element at the specified position
*/
LLI LinkedList::get(int index)
{
    int ctr=0;
    Node *temp;
    temp = this->head;
    while(temp!=NULL)
    {
        ctr++;
        if(ctr==index)
            return temp->data;
        temp = temp->next;
    }
    return -1;
}

/*
Returns the First element of the list
*/
LLI LinkedList::getFirst()
{
    if(!this->head) return -1;
    return this->head->data;
}

/*
Returns the Last element of the list
*/
LLI LinkedList::getLast()
{
    Node *temp;
    temp = head;
    while(temp->next!=NULL)
        temp = temp->next;
    return temp->data;
}

/*
Returns the middle element of the linked list
*/
LLI LinkedList::getMiddle()
{
    Node *first=NULL, *second=NULL, *temp;
    temp = this->head;
    if(!temp) return -1;
    first = second = temp;
    while(second && second->next)
    {
        first = first->next;
        second = second->next;
        if(second)
            second = second->next;
    }

    return first->data;
}


/*
prints the data in the linked list
*/
int LinkedList::printList()
{
    Node *temp;
    int ctr = 0;
    temp = this->head;
    if(temp==NULL)
        std::cout<<"Error: Nothing to print. LinkedList is empty!\n";
    else{
        while(temp!=NULL)
        {
            std::cout<<temp->data<<" ";
            ctr++;
            temp = temp->next;
        }
    }
    return ctr;
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
Reverses the linked list
*/
void LinkedList::reverse()
{
    Node *curr, *prev=NULL, *next=NULL;
    curr = this->head;
    while(curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    this->head = prev;
}

/*
Returns the size of the linked list
*/
int LinkedList::size()
{
    Node *temp;
    temp = this->head;
    int ctr = 0;
    while(temp!=NULL)
    {
        ctr++;
        temp = temp->next;
    }
    return ctr;
}

/*
Stores the elements of the linked list in an array and
returns the array
*/
array LinkedList::toArray()
{
    int *res_arr, res_arr_ind=0;
    array arrObj;
    Node *temp;
    temp = this->head;
    res_arr = (int *)malloc((this->size()) * sizeof(int));
    while(temp!=NULL)
    {
        res_arr[res_arr_ind++] = temp->data;
        temp = temp->next;
    }
    arrObj.arr = res_arr;
    arrObj.size = this->size();
    return arrObj;
}

/*
Returns a string containing all of the elements in the list in
proper sequence (from first to last), each element is separated
by commas and the string is enclosed in square brackets
*/
std::string LinkedList::toString()
{
    std::string resStr = "[";
    Node *temp;
    temp = this->head;
    while(temp!=NULL)
    {
        resStr = resStr + std::to_string(temp->data)+", ";
        temp = temp->next;
    }
    resStr += "]";
    return resStr;
}
