#include <iostream>

typedef int Key;

struct Element
{
    Key data;
    Element *dreapta;
    Element *stanga;
};

Element *creareNod(Key val)
{
    Element *nodNou = new Element;
    nodNou->data = val;
    nodNou->dreapta = nodNou->stanga = nullptr;
    return nodNou;
}

void insert(Element *&radacina, Key val)
{
    if(radacina == nullptr)
    {
        radacina = creareNod(val);
        return;
    }
    if(val < radacina->data)
        insert(radacina->stanga, val);
    else if(val > radacina->data)
        insert(radacina->dreapta, val);
}

void createArbore(Element *&radacina)
{
    int n;
    std::cout << "Introduceti elementele arborului:(0-termina!!)" << std::endl;
    std::cin >> n;
    while(n)
    {
        insert(radacina, n);
        std::cin >> n;
    }
}

bool search(Element *radacina, Key val)
{
    if(radacina == nullptr)
        return false;
    if(radacina->data == val)
        return true;
    if(val < radacina->data)
        return search(radacina->stanga, val);
    return search(radacina->dreapta, val);
}

void afisareInordine(Element *radacina)
{
    if(radacina == nullptr)
        return;
    afisareInordine(radacina->stanga);
    std::cout << radacina->data << " ";
    afisareInordine(radacina->dreapta);
}

void afisarePreordine(Element *radacina)
{
    if(radacina == nullptr)
        return;
    std::cout << radacina->data << " ";
    afisarePreordine(radacina->stanga);
    afisarePreordine(radacina->dreapta);
}

void afisarePostordine(Element *radacina)
{
    if(radacina == nullptr)
        return;
    afisarePostordine(radacina->stanga);
    afisarePostordine(radacina->dreapta);
    std::cout << radacina->data << " ";
}

Element *removeGreatest(Element *&radacina)
{
    if(radacina->dreapta == nullptr)
    {
        Element *temp = radacina;
        radacina = radacina->stanga;
        return temp;
    }
    return removeGreatest(radacina->dreapta);
}

void deleteRoot(Element *&radacina)
{
    Element *temp = radacina;
    if(radacina->stanga == nullptr)
        radacina = radacina->dreapta;
    else if(radacina->dreapta == nullptr)
        radacina = radacina->stanga;
    else
    {
        Element *max = removeGreatest(radacina->stanga);
        max->stanga = radacina->stanga;
        max->dreapta = radacina->dreapta;
        radacina = max;
    }
    delete temp;
}

void deleteNod(Element *&radacina, Key val)
{
    if(radacina == nullptr)
    {
        std::cout << "Arborele este gol" << std::endl;
        return;
    }
    if(val < radacina->data)
        deleteNod(radacina->stanga, val);
    else if(val > radacina->data)
        deleteNod(radacina->dreapta, val);
    else
        deleteRoot(radacina);
}

int main()
{
    Element *radacina = nullptr;
    createArbore(radacina);

    std::cout << "Arborele inordine: ";
    afisareInordine(radacina);
    std::cout << "\nArborele preordine: ";
    afisarePreordine(radacina);
    std::cout << "\nArborele postordine: ";
    afisarePostordine(radacina);
    std::cout << "\n";

    int val;
    std::cout << "Introduceti o valoare care trebuie cautata:" << std::endl;
    std::cin >> val;
    if(search(radacina, val))
        std::cout << "Element gasit!" << std::endl;
    else
        std::cout << "Elementul nu se regaseste in arbore!" << std::endl;

    std::cout << "Introduceti o valoare de sters: ";
    std::cin >> val;
    deleteNod(radacina, val);
    std::cout << "Arborele dupa stergere (inordine): ";
    afisareInordine(radacina);

    return 0;
}
