#include <iostream>

typedef int Atom;

struct Element
{
    Atom data;
    Element* succ;
    Element* pred;
};

void afisare(Element *cap)
{
    if(cap == nullptr)
    {
        std::cout<<"Lista este goala"<<std::endl;
        return;
    }

    std::cout<<"Lista este:"<<std::endl;
    while(cap != nullptr)
    {
        std::cout<<cap->data<<" ";
        cap = cap->succ;
    }
}

void inserareFata(Element *&cap, Atom val)
{
    Element *nodNou = new Element;
    nodNou->data = val;
    nodNou->succ = cap;
    nodNou->pred = nullptr;

    if(cap != nullptr)
    {
        cap->pred = nodNou;
    }
    cap = nodNou;
}

void inserareSpate(Element *&cap, Atom val)
{
    Element* nodNou = new Element;
    nodNou->data = val;
    nodNou->succ = nullptr;
    nodNou->pred = nullptr;

    if(cap == nullptr)
    {
        cap = nodNou;
        return;
    }

    Element* temp = cap;
    while(temp->succ != nullptr)
    {
        temp = temp->succ;
    }
    temp->succ = nodNou;
    nodNou->pred = temp;
}

void createList(Element *&cap)
{
    int n;
    std::cout<<"Introduceti valorile listei(0-termina!!)"<<std::endl;
    std::cin>>n;

    while(n)
    {
        inserareFata(cap, n);
        std::cin>>n;
    }
    afisare(cap);
}

void stergeElementN(Element *&cap, Atom n)
{
    if(cap == nullptr)
    {
        std::cout<<"Lista este goala"<<std::endl;
        return;
    }

    Element *temp = cap;
    for(int i = 0; i < n - 1; i++)
    {
        if(temp->succ == nullptr) return;
        temp = temp->succ;
    }

    Element *stergema = temp->succ;
    if(stergema == nullptr) return;

    temp->succ = stergema->succ;
    if(stergema->succ != nullptr)
    {
        stergema->succ->pred = temp;
    }
    delete stergema;

    std::cout<<"\n";
    afisare(cap);
}

int main(void)
{
    Element* lista = nullptr;
    createList(lista);
    inserareSpate(lista, 5);
    inserareSpate(lista, 6);
    afisare(lista);
    stergeElementN(lista, 3);
}
