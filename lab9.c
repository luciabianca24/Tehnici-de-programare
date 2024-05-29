#include <stdio.h>
#include <stdlib.h>
typedef struct nod
{
    int info;
    struct nod *next;
}nod;
nod *new_nod(int info, nod *next)
{
    nod *nou = NULL;
    if((nou = (nod *)malloc(sizeof(nod))) == NULL)
        exit(-1);
    nou->info = info;
    nou->next = next;
    return nou;
}
nod *adaugare_final(int info, nod *lista)
{
    nod *nou = NULL;
    nou = new_nod(info, NULL);
    if(lista == NULL)
        lista = nou;
    else
    {
        nod *aux = NULL;
        for(aux = lista; aux -> next != NULL; aux = aux -> next);
        aux -> next = nou;
    }
    return lista;
}
void afisare(nod *lista)
{
    nod *aux = NULL;
    for(aux = lista; aux != NULL; aux = aux -> next)
        printf("%d ", aux->info);
    printf("\n");
}
void eliberare(nod *lista)
{
    nod *aux = NULL;
    while(lista != NULL)
    {
        aux = lista -> next;
        free(lista);
        lista = aux;
    }
}
void ex1()
{
    FILE *in;
    nod *lista_pare = NULL, *lista_impare = NULL;
    if((in = fopen("numere.txt", "r")) == NULL)
    {
        printf("Nu s-a putut deschide fisierul");
        return 0;
    }
    int x;
    while(fscanf(in,"%d", &x) == 1)
    {
        if(x % 2 == 0)
            lista_pare = adaugare_final(x, lista_pare);
        else
            lista_impare = adaugare_final(x, lista_impare);
    }
    afisare(lista_pare);
    afisare(lista_impare);
    if(fclose(in))
    {
        printf("Nu s-a putut inchide fisierul");
    }
    eliberare(lista_pare);
    eliberare(lista_impare);
}
nod *inserare(nod *lista)
{
    nod *p = NULL, *q = NULL, *nou = NULL;
    for(p = lista, q = lista -> next; q != NULL; p = q, q = q-> next)
    {
        int x = p -> info;
        if(x % 2 == 0)
        {
            nou = new_nod(x/2, lista);
            p -> next = nou;
            nou -> next = q;
        }
    }
    if(p -> info % 2 == 0)
        lista = adaugare_final(p->info/2, lista);
    return lista;
}
void ex3()
{
    nod *lista = NULL;
    FILE *in;
    if((in = fopen("numere.txt", "r")) == NULL)
    {
        printf("Nu s-a putut deschide fisierul");
        return 0;
    }
    int x;
     while(fscanf(in,"%d", &x) == 1)
        lista = adaugare_final(x, lista);
    lista = inserare(lista);
    afisare(lista);
    eliberare(lista);
     if(fclose(in))
    {
        printf("Nu s-a putut inchide fisierul");
    }
}
int main()
{
    ex3();
    return 0;
}
