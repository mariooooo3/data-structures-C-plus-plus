#include <iostream>

typedef int Atom;

struct Element
{
    Atom data;
    Element *succ;
};

typedef Element *Stiva;

void init(Stiva &s)
{
    s = nullptr;
}

bool isEmpty(Stiva s)
{
    return s == nullptr;
}

void push(Stiva &s, Atom val)
{
    Element *nodNou = new Element;
    nodNou->data = val;
    nodNou->succ = s;
    s = nodNou;
}

Atom top(Stiva s)
{
    if(isEmpty(s))
    {
        std::cout<<"Stiva este goala"<<std::endl;
        return 0;
    }
    return s->data;
}

void pop(Stiva &s)
{
    if(isEmpty(s))
    {
        std::cout<<"Stiva este goala"<<std::endl;
    }
    else
    {
        Element *temp = s;
        s = s->succ;
        delete temp;
    }
}

void afisare(Stiva s)
{
    if(isEmpty(s))
    {
        std::cout<<"Stiva este goala"<<std::endl;
        return;
    }

    std::cout<<"Stiva:"<<std::endl;
    while(s != nullptr)
    {
        std::cout<<s->data<<" ";
        s = s->succ;
    }
}

int main(void)
{
    Stiva s;

    init(s);
    push(s, 5);
    push(s, 10);
    push(s, 15);
    push(s, 20);

    std::cout<<"Top:"<<top(s)<<std::endl;
    afisare(s);

    pop(s);
    pop(s);
    if(isEmpty(s))
    {
        pop(s);
    }

    push(s, 100);
    afisare(s);
}
