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

bool isEmpty(Stiva &s)
{
    if(s == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push(Stiva &s, Atom val)
{
    
    Element *nodNou = new Element;
    nodNou->data = val;
    nodNou->succ = nullptr;
    nodNou->succ = s;
    s = nodNou;
    
}

Atom top(Stiva &s)
{
    if(isEmpty(s))
    {
        std::cout<<"Stiva este goala"<<std::endl;
        return 0;
    }
    else
    {
        return s->data;
    }
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

void afisare(Stiva &s)
{
    Element *temp = s;
    if(isEmpty(temp))
    {
        std::cout<<"Stiva este goala"<<std::endl;
    }
    else
    {
        std::cout<<"Stiva:"<<std::endl;
    }

    while(temp != nullptr)
    {
        std::cout<<temp->data<<" ";
        temp = temp->succ;
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