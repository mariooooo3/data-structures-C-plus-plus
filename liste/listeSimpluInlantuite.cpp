#include <iostream>

typedef int Atom;

struct Element
{
    Atom data;
    Element* succ;
};

void inserareFata(Element *&cap, Atom val)
{
    Element *nodNou = new Element;
    nodNou->data = val;
    nodNou->succ = cap;
    cap = nodNou;
}

void inserareSpate(Element *&cap, Atom val)
{
    Element *nodNou = new Element;
    nodNou->data = val;
    nodNou->succ = nullptr;

    if(cap == nullptr)
    {
        cap = nodNou;
    }
    else
    {
        Element *temp = cap;
        while(temp->succ != nullptr)
        {
            temp = temp->succ;
        }
        temp->succ = nodNou;
    }
}

void createList(Element *&cap)
{
    int n;
    std::cout<<"Introduceti element(0-termina!)"<<std::endl;
    std::cin>>n;

    while(n)
    {
        inserareFata(cap,n);
        std::cin>>n;
    }
}

void afisareLista(Element *cap)
{
    if(cap == nullptr)
    {
        std::cout<<"Lista este goala"<<std::endl;
        return;
    }

    std::cout<<"Lista este:";
    Element* temp = cap;
    while(temp != nullptr)
    {
        std::cout<<temp->data<<" ";
        temp = temp->succ;
    }
}

void gasesteX(Element *cap)
{
    int x;
    std::cout<<"\nIntroduceti elementul pe care doriti sa-l gasiti"<<std::endl;
    std::cin>>x;
    bool este = false;

    while(cap != nullptr)
    {
        if(cap->data == x)
        {
            este = true;
            break;
        }
        cap = cap->succ;
    }

    if(este)
    {
        std::cout<<"Elementul se regaseste in lista"<<std::endl;
    }
    else
    {
        std::cout<<"Elementul NU se regaseste in lista"<<std::endl;
    }
}

int dimensiuneLista(Element *cap)
{
    int contor = 0;
    while(cap != nullptr)
    {
        contor++;
        cap = cap->succ;
    }
    return contor;
}

void inserareDupaElement(Element *&cap, Atom n, Atom data)
{
    if(cap == nullptr)
    {
        std::cout<<"Lista este goala"<<std::endl;
        return;
    }

    if(n >= dimensiuneLista(cap))
    {
        std::cout<<"Elementul dat depaseste lista"<<std::endl;
        return;
    }

    Element *nodNou = new Element;
    nodNou->data = data;
    nodNou->succ = nullptr;

    Element *temp = cap;
    for(int i = 0; i < n; i++)
    {
        temp = temp->succ;
    }
    nodNou->succ = temp->succ;
    temp->succ = nodNou;

    afisareLista(cap);
}

void stergeElementFata(Element *&cap)
{   
    if(cap == nullptr)
    {
        std::cout<<"Lista este goala"<<std::endl;
        return;
    }

    Element *temp = cap;
    cap = cap->succ;
    delete temp;

    std::cout<<"\n";
    afisareLista(cap);
}

void stergeElementN(Element *&cap, Atom n)
{
    if(cap == nullptr)
    {
        std::cout<<"Lista este goala"<<std::endl;
        return;
    }

    if(n >= dimensiuneLista(cap))
    {
        std::cout<<"Numarul introdus este mai mare decat dimensiunea listei"<<std::endl;
        return;
    }

    if(n == 0)
    {
        stergeElementFata(cap);
        return;
    }

    Element *temp = cap;
    for(int i = 0; i < n - 1; i++)
    {
        temp = temp->succ;
    }
    Element* stergema = temp->succ;
    temp->succ = stergema->succ;
    delete stergema;

    std::cout<<"\n";
    afisareLista(cap);
}

int main(void)
{
    Element* lista = nullptr;
    createList(lista);
    inserareSpate(lista, 5);
    inserareSpate(lista, 6);
    afisareLista(lista);
    gasesteX(lista);
    std::cout<<"\nDimensiunea listei este: "<<dimensiuneLista(lista)<<std::endl;
    inserareDupaElement(lista, 3, 100);
    stergeElementFata(lista);
    stergeElementN(lista, 3);
}
