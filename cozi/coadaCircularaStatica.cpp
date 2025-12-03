#include <iostream>
#define MAX 10

typedef int Atom;

struct Queue
{
    Atom head;
    Atom tail;
    Atom vect[MAX];
};

void init(Queue &q)
{
    q.head = q.tail = 0;
}

bool isEmpty(Queue &q)
{
    return q.head == q.tail;
}

bool isFull(Queue &q)
{
    return (q.tail + 1) % MAX == q.head;
}

Atom front(Queue &q)
{
    if(isEmpty(q))
    {
        std::cout<<"Coada este goala"<<std::endl;
        return 0;
    }
    return q.vect[q.head];
}

void enqueue(Queue &q, Atom val)
{
    if(isFull(q))
    {
        std::cout<<"Coada este plina"<<std::endl;
        return;
    }
    q.vect[q.tail] = val;
    q.tail = (q.tail + 1) % MAX;
}

Atom dequeue(Queue &q)
{
    if(isEmpty(q))
    {
        std::cout<<"Coada este goala"<<std::endl;
        return 0;
    }
    Atom val = q.vect[q.head];
    q.head = (q.head + 1) % MAX;
    return val;
}

void afisare(Queue &q)
{
    if(isEmpty(q))
    {
        std::cout<<"Coada este goala!"<<std::endl;
        return;
    }

    std::cout<<"Elementele din coada sunt: ";
    int i = q.head;
    while(i != q.tail)
    {
        std::cout<<q.vect[i]<<" ";
        i = (i + 1) % MAX;
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
    enqueue(q, 50);
    afisare(q);

    std::cout<<"Front: "<<front(q)<<std::endl;
    dequeue(q);
    dequeue(q);
    afisare(q);
}
