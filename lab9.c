#include <stdio.h>
#include <stdlib.h>
typedef struct nod
{
    int info;
    struct nod *next;
}nod;
typedef struct nod2
{
    int info;
    struct nod2 *next;
    struct nod2 *prev;
}nod2;
nod2 *new_nod2(int info)
{
    nod2 *nou = NULL;
    if((nou = (nod2 *)malloc(sizeof(nod2))) == NULL)
        exit(-1);
    nou->info = info;
    nou->prev = NULL;
    nou->next = NULL;
    return nou;
}
nod2 *adauga_la_sfarsit(int info, nod2 *lista)
{
    nod2 *nou = NULL, *aux = NULL;
    nou = new_nod2(info);
    if(lista == NULL)
        lista = nou;
    else
    {
        for(aux = lista; aux -> next != NULL; aux = aux->next);
        aux->next = nou;
        nou->prev = aux;
    }
    return lista;
}
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
nod2 *init()
{
    int x = 0;
    nod2 *lista = NULL;
    while(scanf("%d", &x) == 1)
        lista = adauga_la_sfarsit(x, lista);
    return lista;
}
nod2 *stergere(nod2 *lista)
{
    nod2 *aux = lista;
    lista = lista->next;
    free(aux);
    for(aux = lista; aux->next != NULL; aux = aux->next);
    nod2 *ultim = aux;
    aux->prev->next = NULL;
    free(ultim);
    return lista;
}
void ex4()
{
    nod2 *lista = NULL, *aux = NULL;
    lista = init();
    for(aux = lista; aux != NULL && aux ->next != NULL; aux = aux->next->next)
    {
        int c = aux->info;
        aux -> info = aux->next->info;
        aux->next->info = c;
    }
    afisare(lista);
    eliberare(lista);
}
void ex5()
{
    nod2 *lista = NULL;
    lista = init();
    lista = stergere(lista);
    afisare(lista);
}
void ex6()
{
    nod2 *lista = NULL;
    lista = init();
    nod2 *aux = NULL, *inceput = lista, *sfarsit = NULL;
    for(aux = lista; aux->next != NULL; aux = aux->next);
    aux->next = lista;
    afisare(lista);
}
int palindrom(int n)
{
    int inv = 0;
    int cn = n;
    while(cn)
    {
        inv = inv * 10 + cn % 10;
        cn = cn / 10;
    }
    if(inv == n)
        return 1;
    return 0;

}
void ex7()
{
    nod2 *lista, *aux;
    lista = init();
    int nr = 0;
    for(aux = lista; aux != NULL; aux = aux->next)
    {
        int  x = aux->info;
        nr = nr * 10 + x;
    }
    printf("%d", palindrom(nr));
}
void ex8()
{
    nod2 *lista = NULL;
    lista = init();
    nod2 *aux = NULL, *inceput = lista, *sfarsit = NULL;
    lista = adauga_la_sfarsit(lista->info, lista);
    lista = lista->next;
    afisare(lista);
}
nod *init1()
{
    int x;
    nod *lista = NULL;
    while(scanf("%d", &x) == 1)
        lista = adaugare_final(x, lista);
    return lista;
}
nod *stergere9(nod *lista)
{
    nod *p = NULL, *q = NULL, *aux  = NULL;
    if(lista == NULL)
        return lista;
    while(lista->info % 2 == 0)
    {
        aux = lista;
        lista = lista->next;
        free(aux);
    }
    for(p = lista, q = lista->next; q != NULL; p = q, q = q->next)
    {
        if(q->info % 2 == 0)
             {
                 aux = q;
                 p->next = q->next;
                 free(aux);
                 q = p;
             }

    }
    return lista;
}
void ex9()
{
    nod *lista = NULL, *aux = NULL;
    lista = init1();
    lista = stergere9(lista);
    afisare(lista);
}
void ex10()
{
    nod *lista = NULL, *lista_pare = NULL, *lista_impare = NULL, *aux = NULL;
    lista = init1();
    for(aux = lista; aux != NULL; aux = aux->next)
    {
        int x = aux->info;
        if(aux->info % 2 == 0)
            lista_pare = adaugare_final(x, lista_pare);
        else
            lista_impare = adaugare_final(x, lista_impare);
    }
    afisare(lista_impare);
    afisare(lista_pare);
}
int main()
{
    ex7();
    return 0;
}
