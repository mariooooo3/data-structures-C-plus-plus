#include <iostream>

typedef int Atom;

struct Element
{
    Atom data;
    Element *succ;
};

typedef Element* Queue;

void init(Queue &t)
{
    t = nullptr;
}

bool isEmpty(Queue &t)
{
    return t == nullptr;
}

void enqueue(Queue &t, Atom val)
{
    Element *nodNou = new Element;
    nodNou->data = val;
    nodNou->succ = nullptr;

    if(isEmpty(t))
    {
        nodNou->succ = nodNou;
        t = nodNou;
    }
    else
    {
        nodNou->succ = t->succ;
        t->succ = nodNou;
        t = nodNou;
    }
}

void dequeue(Queue &t)
{
    if(isEmpty(t))
    {
        std::cout<<"Coada este goala"<<std::endl;
        return;
    }

    Element *temp = t->succ;
    if(temp == t)
    {
        delete temp;
        t = nullptr;
    }
    else
    {
        t->succ = temp->succ;
        delete temp;
    }
}

void front(Queue &t)
{
    if(isEmpty(t))
    {
        std::cout<<"Coada este goala"<<std::endl;
    }
    else
    {
        std::cout<<"\nElementul din fata este: "<<t->succ->data<<std::endl;
    }
}

void afisare(Queue &t)
{
    if(isEmpty(t))
    {
        std::cout<<"Coada este goala"<<std::endl;
        return;
    }

    std::cout<<"\nCoada este:"<<std::endl;
    Element *temp = t->succ;
    while(true)
    {
        std::cout<<temp->data<<" ";
        if(temp == t)
        {
            break;
        }
        temp = temp->succ;
    }
    std::cout<<std::endl;
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
    afisare(q);
    front(q);
}
