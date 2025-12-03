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

bool isEmpty(Stiva s)
{
    return s.varf == -1;
}

bool isFull(Stiva s)
{
    return s.varf == MAX - 1;
}

int top(Stiva s)
{
    if(isEmpty(s))
    {
        std::cout<<"Stiva este goala"<<std::endl;
        return 0;
    }
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

void afisare(Stiva s)
{
    if(isEmpty(s))
    {
        std::cout<<"Stiva este goala"<<std::endl;
        return;
    }

    std::cout<<"Stiva este:"<<std::endl;
    for(int i = s.varf; i >= 0; i--)
    {
        std::cout<<s.vect[i]<<" ";
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
