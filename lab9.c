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
    if((nou = (nod*)malloc(sizeof(nod))) == NULL)
    {
        printf("out of memory");
        exit(-1);
    }
    nou->info = info;
    nou->next = next;
    return nou;
}
void afisare(nod *lista)
{
    nod *aux = NULL;
    for(aux = lista; aux->next != NULL; aux = aux->next)
        printf("%d", aux->info);
}
void adaugare_lista(int info, nod *lista)
{
    nod *nou = NULL, *aux = NULL;
    nou = new_nod(info, NULL);
    if(lista == NULL)
        lista = nou;
    else
    {
        for(aux = lista; aux->next != NULL; aux = aux->next);
            aux->next = nou;
    }
    return lista;
}
nod *stergere_inceput(nod *lista)
{
    if(lista == NULL)
        return lista;
    nod *aux = NULL;
    aux = lista;
    free(aux);
    lista = lista->next;
    return lista;
}
void freeList(nod *lista)
{
    nod *aux;
    while (lista != NULL)
    {
        aux = lista->next;
        free(lista);
        lista = aux;
    }
}
nod *citire(int *lsize)
{
    int lista_size = 0, info;
    nod *lista = NULL;
    scanf("%d", &lista_size);
    for(int i = 0; i < lista_size; i++)
    {
        scanf("%d", &info);
        lista = aduagare_lista(info, lista);
    }
    *lsize = lista_size;
    return lista;
}
void ex1()
{
    nod *lista =  NULL;

}
int main()
{
    printf("Hello world!\n");
    return 0;
}
