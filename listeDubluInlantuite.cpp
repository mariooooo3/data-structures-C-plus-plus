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
    if(cap == 0)
    {
        std::cout<<"Lista este goala"<<std::endl;
    }
    else
    {
        std::cout<<"Lista este:"<<std::endl;
    }

    while(cap != 0)
    {
        std::cout<<cap->data<<" ";
        cap = cap->succ;
    }
}

void inserareFata(Element *&cap, Atom val)
{
    Element *nodNou = new Element;
    nodNou->data = val;
    nodNou->succ = nullptr;
    nodNou->pred = nullptr;

    if(cap == nullptr)
    {
        //std::cout<<"Lista este goala"<<std::endl;
        cap = nodNou;
    }
    else
    {
        cap->pred = nodNou;
        nodNou->succ = cap;
        cap = nodNou;
    }


}

void inserareSpate(Element *&cap, Atom val)
{
    Element* nodNou = new Element;
    Element* temp;
    temp = cap;
    nodNou->data = val;
    nodNou->succ = nullptr;
    nodNou->pred = nullptr;

    if(cap == nullptr)
    {
        std::cout<<"Lista este goala"<<std::endl;
        cap = nodNou;
    }
    else
    {
        while(temp->succ !=0 )
        {
            temp = temp->succ;
        }
        temp->succ = nodNou;
        nodNou->pred = temp;
        nodNou->succ = nullptr;

    }
    
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
    if(cap == 0)
    {
        std::cout<<"Lista este goala"<<std::endl;
    }
    else
    {
        Element *temp;
        temp = cap;
        for(int i=0; i<n-1;i++)
        {
            temp = temp->succ;
        }
        Element *stergema;
        stergema = temp->succ;
        temp->succ = stergema->succ;
        free(stergema);
    }
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