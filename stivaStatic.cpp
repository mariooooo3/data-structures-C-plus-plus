#include <iostream>
#define MAX 10

typedef int Atom;

struct Stiva
{
    Atom varf;
    Atom vect[MAX];
};

void init(Stiva &s)
{
    s.varf = -1;
}

bool isEmpty(Stiva &s)
{
    return s.varf == -1;
}

bool isFull(Stiva &s)
{
    return s.varf == MAX - 1;
}

int top(Stiva &s)
{
    if(isEmpty(s))
    {
        std::cout<<"Stiva este goala"<<std::endl;
        return 0;
    }
    else
        return s.vect[s.varf];
}

void push(Stiva &s, Atom val)
{  
    if(isFull(s))
    {
        std::cout<<"Stiva este plina"<<std::endl;
        return;
    }
    s.varf++;
    s.vect[s.varf] = val;
}

void pop(Stiva &s)
{
    if(isEmpty(s))
    {
        std::cout<<"Stiva este goala"<<std::endl;
        return;
    }
    s.varf--;
}

void afisare(Stiva &s)
{
    int contor = s.varf;
    if(isEmpty(s))
    {
        std::cout<<"Stiva este goala"<<std::endl;
        return;
    }
    else
        std::cout<<"Stiva este:"<<std::endl;

    while(contor != -1)
    {
        std::cout<<s.vect[contor]<<" ";
        contor--;
    }
}

int main(void)
{
    Stiva s;
    init(s);
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    afisare(s);

    std::cout<<"\nTop:"<<top(s)<<std::endl;
    pop(s);
    pop(s);
    pop(s);
    afisare(s);

}