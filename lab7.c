#include <stdint.h>
#include <stdio.h>
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
        exit(-1);
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
    printf("\n");

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
void ex2()
{
    nod *lista = NULL;
    int l_size = 0;
    lista = init(&l_size);
    nod *pre = NULL, *urm = NULL, *p = NULL;
    for(p = lista->next, pre = lista; p ->next != NULL; pre = p, p = urm)
    {
        urm = p ->next;
        p->next = pre;

    }
    p->next = pre;
    lista->next = NULL;
    lista = p;
    afisare(lista);
    freeList(lista);
}
void ex5()
{
    nod *lista1 = NULL;
    nod *lista2 = NULL;
    int size_lista1, size_lista2, ok = 1;
    lista1 = init(&size_lista1);
    lista2 = init(&size_lista2);
    nod *aux = NULL;
    for(aux = lista1; aux != NULL; aux = aux -> next)
    {
        int info = aux -> info;
        if(isinlist (lista2, info) == 0)
        {
            ok = 0;
            break;
        }
    }
    for(aux = lista2; aux != NULL; aux = aux -> next)
    {
        int info = aux -> info;
        if(isinlist (lista1, info) == 0)
        {
            ok = 0;
             break;
        }
    }
    freeList(lista1);
    freeList(lista2);
    if(ok == 1)
        printf("Listele sunt la fel");
    else
        printf("Listele sunt diferite");
}
int *stergere(int x, nod *lista)
{
    nod *p = NULL, *pre = NULL;
    if(lista -> info == x)
    {
        lista = lista -> next;
        return lista;
    }
    for(pre = lista, p = lista -> next; p != NULL; pre = p, p = p -> next)
    {
        int info;
        info = p -> info;
        if(info == x)
        {
            pre -> next = p -> next;
            free(p)
            break;
        }
    }
    return lista;
}
void ex4()
{
    int x, l_size;
    nod *lista = NULL;
    lista = init(&l_size);
    scanf("%d", &x);
    lista = stergere(x, lista);
    afisare(lista);
    freeList(lista);
}
nod* inserare_crescatoare(int x, nod *lista)
{
    nod *pre = NULL, *p = NULL, *nou = NULL;
    nou = new_nod(x, NULL);
    if(lista == NULL)
        lista = nou;
    else
    {
        if(x < lista -> info)
        {
            p = lista;
            lista = nou;
            nou -> next = p;
        }
        else
        {
            for(pre = lista, p = lista -> next; p != NULL; pre = p, p = p -> next)
            {
                if(pre -> info <= x && p -> info >= x)
                {
                    pre -> next = nou;
                    nou -> next = p;
                    break;
                }
            }
            if(p == NULL)
                add_end(x, lista);
        }
    }
        return lista;
}
nod *sortare(nod *lista)
{
    nod *lista_cresc = NULL, *aux = NULL;
    for(aux = lista; aux != NULL; aux = aux -> next)
    {
        int info = aux -> info;
        lista_cresc = inserare_crescatoare(info, lista_cresc);
    }
    return lista_cresc;
}
void ex6()
{
    nod *lista = NULL;
    int list_size = 0, x = 0;
    lista = init(&list_size);
    //scanf("%d", &x);
    //lista = inserare_crescatoare(x, lista);
    lista = sortare(lista);
    afisare(lista);
    freeList(lista);
}
void ex7()
{
    nod *lista1 = NULL, *lista2 = NULL, *lista = NULL, *aux;
    int l_size1, l_size2;
    lista1 = init(&l_size1);
    lista2 = init(&l_size2);
    for(aux = lista1; aux != NULL; aux = aux->next)
        lista = add_end(aux->info, lista);
    for(aux = lista2; aux != NULL; aux = aux->next)
        lista = add_end(aux->info, lista);
    lista = sortare(lista);
    afisare(lista);
}
int main()
{
    ex7();
}
