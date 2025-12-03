#include <iostream>
#define MAX 100

int A[MAX];
int n = 0;

void afisareInordine(int i)
{
    if(i <= n)
    {
        afisareInordine(i * 2);
        std::cout << A[i] << " ";
        afisareInordine(2 * i + 1);
    }
}

void afisarePostordine(int i)
{
    if(i <= n)
    {
        afisarePostordine(i * 2);
        afisarePostordine(i * 2 + 1);
        std::cout << A[i] << " ";
    }
}

void afisarePreordine(int i)
{
    if(i <= n)
    {
        std::cout << A[i] << " ";
        afisarePreordine(i * 2);
        afisarePreordine(i * 2 + 1);
    }
}

void insert(int x)
{
    A[++n] = x;
    int fiu = n;
    int parinte = fiu / 2;

    while(parinte >= 1 && A[parinte] < A[fiu])
    {
        std::swap(A[parinte], A[fiu]);
        fiu = parinte;
        parinte = fiu / 2;
    }
}

int remove()
{
    if(n == 0)
    {
        std::cout << "Arborele este gol" << std::endl;
        return -1;
    }

    int valMax = A[1];
    A[1] = A[n--];
    int parinte = 1;
    int fiu = 2 * parinte;

    while(fiu <= n)
    {
        if(fiu + 1 <= n && A[fiu] < A[fiu + 1])
            fiu++;
        if(A[parinte] < A[fiu])
        {
            std::swap(A[parinte], A[fiu]);
            parinte = fiu;
            fiu = parinte * 2;
        }
        else
            break;
    }
    return valMax;
}

void retro(int i)
{
    int parinte = i;
    int fiu = 2 * i;

    while(fiu <= n)
    {
        if(fiu + 1 <= n && A[fiu] < A[fiu + 1])
            fiu++;
        if(A[parinte] < A[fiu])
        {
            std::swap(A[parinte], A[fiu]);
            parinte = fiu;
            fiu = parinte * 2;
        }
        else
            break;
    }
}

void buildHeap()
{
    for(int i = n / 2; i >= 1; i--)
        retro(i);
}

void HeapSort()
{
    buildHeap();
    int m = n;
    for(int i = n; i >= 1; i--)
    {
        std::swap(A[1], A[i]);
        n--;
        retro(1);
    }
    n = m;
}

int main()
{
    int valori[] = {0, 10, 5, 15, 3, 7, 12, 20};
    n = 7;
    for(int i = 1; i <= n; i++) A[i] = valori[i];

    std::cout << "Parcurgere inordine: ";
    afisareInordine(1);
    std::cout << "\n\n";

    n = 0;
    insert(50);
    insert(30);
    insert(20);
    insert(15);
    insert(10);

    std::cout << "Scoatem elemente din heap: ";
    while(n > 0)
    {
        std::cout << remove() << " ";
    }
    std::cout << "\n\n";

    int v[] = {0, 40, 25, 60, 35, 55};
    n = 5;
    for(int i = 1; i <= n; i++) A[i] = v[i];

    HeapSort();

    std::cout << "Vector sortat descrescator: ";
    for(int i = 1; i <= n; i++)
        std::cout << A[i] << " ";
    std::cout << "\n";

    return 0;
}
