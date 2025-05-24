#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstdlib>

typedef char Atom;

struct Element
{
    Atom data;
    Element *stanga;
    Element *dreapta;
};

static Atom car = 0;

static void eroare()
{
    std::cout<<"Sirul introdus este eronat"<<std::endl;
    std::cout<<"Apasati o tasta..."<<std::endl;
    getchar();
    exit(1);
}

static Atom readChar()
{
    Atom c;
    do c = getchar(); while(c == ' ' || c == '\n');
    return c;
}

static Atom readNumber()
{
    Atom c;
    if(!isalpha(car))
        eroare();
    c = car;
    car = readChar();
    return c;
}

static Element* citesteArbore()
{
    Element *radacina;

    if(car == '-')
    {
        radacina = nullptr;
        car = readChar();
    }
    else
    {
        radacina = new Element;
        radacina->data = readNumber();

        if(car != '(')
        {
            radacina->dreapta = nullptr;
            radacina->stanga = nullptr;
        }
        else
        {
            car = readChar();
            radacina->stanga = citesteArbore();

            if(car != ',')
                radacina->dreapta = nullptr;
            else
            {
                car = readChar();
                radacina->dreapta = citesteArbore();
            }

            if(car != ')')
                eroare();
            car = readChar();
        }
    }
    return radacina;
}

Element* creareArbore()
{
    std::cout<<"Exemplu: A(B(-,C),D(E(F,-),G(H,-)))"<<std::endl;
    std::cout<<"Introduceti arborele:"<<std::endl;

    car = readChar();
    return citesteArbore();
}

void afisareInordine(Element* radacina)
{
    if(radacina == nullptr)
        return;
    afisareInordine(radacina->stanga);
    std::cout<<radacina->data<<" ";
    afisareInordine(radacina->dreapta);
}

void afisarePreordine(Element *radacina)
{
    if(radacina == nullptr)
        return;
    std::cout<<radacina->data<<" ";
    afisarePreordine(radacina->stanga);
    afisarePreordine(radacina->dreapta);
}

void afisarePostordine(Element *radacina)
{
    if(radacina == nullptr)
        return;
    afisarePostordine(radacina->stanga);
    afisarePostordine(radacina->dreapta);
    std::cout<<radacina->data<<" ";
    
}

int adancime(Element *radacina)
{
    if(radacina == nullptr)
        return 0;
    int adancimeStanga = adancime(radacina->stanga);
    int adancimeDreapta = adancime(radacina->dreapta);

    return 1 + std::max(adancimeDreapta,adancimeStanga);
}

int numarNoduri(Element *radacina)
{
    if(radacina == nullptr)
        return 0;
    int nrStanga = numarNoduri(radacina->stanga);
    int nrDreapta = numarNoduri(radacina->dreapta);
    
    return 1 + nrDreapta + nrStanga;
}

int numarFrunze(Element* radacina)
{
    if(radacina == nullptr)
        return 0;
    if(radacina->stanga == nullptr && radacina->dreapta == nullptr)
        return 1;
    int nrStanga = numarFrunze(radacina->stanga);
    int nrDreapta = numarFrunze(radacina->dreapta);

    return nrDreapta + nrStanga;
}

Atom literaMaxima(Element *radacina)
{
    if(radacina == nullptr)
        return 'A' - 1;
    Atom maxDreapta = literaMaxima(radacina->dreapta);
    Atom maxStanga = literaMaxima(radacina->stanga);
    Atom max = radacina->data;

    if(maxStanga > max)
        max = maxStanga;
    if(maxDreapta > max)
        max = maxDreapta;
    return max;
}

int main(void)
{
    Element *radacina = creareArbore();

    std::cout<<"Afisare inordine"<<std::endl;
    afisareInordine(radacina);
    std::cout<<"\nAfisare preordine"<<std::endl;
    afisarePreordine(radacina);
    std::cout<<"\nAfisare postordine"<<std::endl;
    afisarePostordine(radacina);
    std::cout << "\n\n";

    std::cout << "Adancimea arborelui: " << adancime(radacina) << std::endl;
    std::cout << "Numarul total de noduri: " << numarNoduri(radacina) << std::endl;
    std::cout << "Numarul de frunze: " << numarFrunze(radacina) << std::endl;
    std::cout << "Litera maxima din arbore: " << literaMaxima(radacina) << std::endl;

    return 0;
}