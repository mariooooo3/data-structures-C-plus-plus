#include <iostream>

typedef int Atom;

struct Element
{
    Atom data;
    Element *succ;
};

struct Queue
{
    Element *head;
    Element *tail;
};

void init(Queue &q)
{
    q.head = q.tail = nullptr;
}

bool isEmpty(Queue &q)
{
    return q.head == nullptr;
}

void enqueue(Queue &q, Atom val)
{
    Element *nodNou = new Element;
    nodNou->data = val;
    nodNou->succ = nullptr;

    if(isEmpty(q))
    {
        q.head = q.tail = nodNou;
    }
    else
    {   
        q.tail->succ = nodNou;
        q.tail = nodNou;
    }
}

void dequeue(Queue &q)
{
    if(isEmpty(q))
    {
        std::cout<<"Coada este goala"<<std::endl;
    }
    else
    {
        Element *temp = q.head;
        q.head = q.head->succ;
        if(q.head == nullptr)
            q.tail = nullptr;
        delete temp;
    }
}

Atom front(Queue &q)
{
    if(isEmpty(q))
    {
        std::cout<<"Coada este goala"<<std::endl;
        return 0;
    }
    return q.head->data;
}

void afisare(Queue &q)
{
    if(isEmpty(q))
    {
        std::cout<<"Coada este goala"<<std::endl;
        return;
    }

    std::cout<<"Coada este:"<<std::endl;
    Element *temp = q.head;
    while(temp != nullptr)
    {
        std::cout<<temp->data<<" ";
        temp = temp->succ;
    }
}

int main(void)
{
    Queue q;
    init(q);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    afisare(q);
    dequeue(q);

    std::cout<<"\nFront:"<<front(q)<<std::endl;
    if(isEmpty(q))
        dequeue(q);

    afisare(q);
}
