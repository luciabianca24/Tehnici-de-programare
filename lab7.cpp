#include <iostream>
#include <stdint.h>
using namespace std;
typedef struct nod
{
    int info;
    struct nod *next;
}nod;
nod *new_nod(int info, nod *next)
{
    nod *nou = NULL;
    if((nou=(nod*)malloc(sizeof(nod))) == NULL)
    {
        printf("out of memory");
        exit(EXIT_FAILURE);
    }
    nou->info = info;
    nou->next = next;
    return nou;
}
void afisare(nod *lista)
{
    nod *aux = NULL;
    for(aux = lista; aux != NULL; aux = aux->next)
        printf("%d ", aux->info);

}
nod *add_end(int info, nod *lista)
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
nod *delete_beggining(nod *lista)
{
    if (lista == NULL)
        return lista;
    lista = lista->next;
    return lista;
}
nod *init(int *lsize)
{
    nod *lista = NULL;
    int info = 0, list_size;
    scanf("%d", &list_size);
    *lsize = list_size;
    for(int i = 0; i < list_size; i++)
    {
        scanf("%d", &info);
        lista = add_end(info, lista);
    }
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
void ex1()
{
    nod *lista1 = NULL, *lista2 = NULL;
    int list1_size = 0, list2_size = 0, info1,info2;
    lista1 = init(&list1_size);
    lista2 = init(&list2_size);
    if(list1_size != list2_size)
       {
           printf("0");
           return;
       }
    for(int i = 0; i < list1_size; i++)
    {
        info1 = lista1->info;
        info2 = lista2->info;
        if(info1 != info2)
        {
            printf("0");
            freeList(lista1);
            freeList(lista2);
            return;
        }
        delete_beggining(lista1);
        delete_beggining(lista2);
    }
    printf("1");
    freeList(lista1);
    freeList(lista2);
}
int isinlist(nod *lista, int info)
{
    nod *aux;
    int data;
    for(aux = lista; aux != NULL; aux = aux->next)
    {
        data = aux->info;
        if(data == info)
            return 1;
    }
    return 0;
}
void ex3()
{
    nod *list1 = NULL, *list2 = NULL, *lista = NULL;
    int list1_size, list2_size, l, data1, data2;
    list1 = init(&list1_size);
    list2 = init(&list2_size);
    printf("%d", isinlist(list1, 3));
    for(int i = 0; i < list1_size; i++)
    {

        data1 = list1->info;
        if(isinlist(lista,data1) == 0)
            lista = add_end(data1, lista);
        list1 = delete_beggining(list1);
    }
    for(int i = 0; i < list2_size; i++)
    {

        data2 = list2->info;
        if(isinlist(lista, data2) == 0)
            lista = add_end(data2, lista);
        list2 = delete_beggining(list2);
    }
    afisare(lista);
    freeList(list1);
    freeList(list2);
    freeList(lista);
}
int main()
{
    ex3();
}
