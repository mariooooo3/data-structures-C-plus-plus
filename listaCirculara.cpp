#include <iostream>

typedef int Atom;

struct Element
{
    Atom data;
    Element* succ;
};

void afisare(Element *cap)
{
    Element *temp;
    temp = cap;

    if(cap == nullptr)
    {
        std::cout<<"Lista este goala"<<std::endl;
        return;
    }
    else
    {
        std::cout<<"Lista este:"<<std::endl;
    }
    
    do
    {
        std::cout<<temp->data<<" ";
        temp = temp->succ;
    }
    while(temp != cap);

    std::cout<<std::endl;    
    
}

void inserareFata(Element *&cap, Atom val)
{
    Element *nodNou = new Element;
    Element *temp;
    temp = cap;
    nodNou->data = val;
    nodNou->succ = nullptr;

    if(cap == nullptr)
    {
        nodNou->succ = nodNou;
        cap = nodNou;
    }
    else
    {
        while(temp->succ != cap)
        {
            temp = temp->succ;
        }
        nodNou->succ = cap;
        cap = nodNou;
        temp->succ = cap;
    }
}

void inserareSpate(Element *&cap, Atom val)
{
    Element *nodNou = new Element;
    Element *temp;
    temp = cap;
    nodNou->data = val;
    nodNou->succ = nullptr;

    if(cap == nullptr)
    {
        nodNou->succ = nodNou;
        cap = nodNou;
    }
    else
    {
        while(temp->succ != cap)
        {
            temp = temp->succ;
        }
        temp->succ = nodNou;
        nodNou->succ = cap;
    }

}

void createList(Element *&cap)
{
    int n;
    std::cout<<"Introduceti lista:(o-termina!!)"<<std::endl;
    std::cin>>n;

    while(n)
    {
        inserareFata(cap, n);
        std::cin>>n;
    }
    afisare(cap);
}


int main(void)
{
    Element *lista = nullptr;
    createList(lista);
    inserareSpate(lista, 5);
    inserareSpate(lista, 6);
    afisare(lista);

}