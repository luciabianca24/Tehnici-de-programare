#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define DIM_MAX 100
typedef struct
{
    int nr_picioare: 10;
    int periculos: 1;
    int varsta: 11;
    char specie[9];
    float greutate;
} Animal;
typedef struct
{
    int grad: 2;
    int reteta:1;
    int varsta:5;
} Medicament;
void ex4()
{
    Animal a;
int aux;
printf("Introduceti numarul de picioare\n");
scanf("%d", &aux);
a.nr_picioare = aux;
printf("Introduceti greutatea\n");
scanf("%f", &a.greutate);
printf("Introduceti specia\n");
scanf("%s", a.specie);
printf("Introduceti daca animalul este sau nu periculos\n");
scanf("%d", &aux);
a.periculos = aux;
printf("Introduceti varsta\n");
scanf("%d", &aux);
aux = a.varsta;
printf("Animalul este %s, are %d picioare, %f kilograme, %d ani", a.specie, a.nr_picioare, a.greutate, a.varsta);
}
void ex5()
{
    Medicament m;
    char s[DIM_MAX];
    int aux;
    printf("Introduceti gradul de periculozitate\n");
    scanf("%s", s);
    if(strcmp(s,"scazuta") == 0)
        m.grad = 1;
    if(strcmp(s, "medie") == 0)
        m.grad = 2;
    if(strcmp(s, "mare") == 0)
        m.grad = 3;
    printf("Daca ai nevoie de reteta\n");
    scanf("%s", s);
    if(strcmp(s, "da") == 0)
        m.reteta = 1;
    else
        m.reteta = 0;
    scanf("%d", &aux);
    m.varsta = aux;
    printf("gradul de periculozitate este 1-scazuta 2-medie 3-mare%d\n ", m.grad);
    printf("daca se elibereaza pe baza de reteta 0-da  1-nu%d\n", m.reteta);
    printf("varsta minima este\n%d\n", m.varsta);
}
typedef struct
{
    char nume[DIM_MAX];
    int nota;
} Student;
Student student;
typedef struct
{
    int dimensiune:11;
    int tip_doc:2;//.txt - 0 .doc -1 .xls - 2
    int tip_file:1; // normal - 0 read_only - 1
    char nume[DIM_MAX];
} Fisier;
Fisier fis;
void ex0()
{
    int aux;
    scanf("%s", student.nume);
    scanf("%d", &aux);
    student.nota = aux;
    printf("%s %d", student.nume, student.nota);
}
void ex1()
{
    int aux = 0;
    scanf("%d", &aux);
    fis.dimensiune = aux;
    scanf("%d", &aux);
    fis.tip_doc = aux;
    scanf("%d", &aux);
    fis.tip_file = aux;
    scanf("%s", fis.nume);
    //tip_doc .txt - 0 .doc -1 .xls - 2
    // tip_file normal - 0 read_only - 1
    printf("Numele fisierului este %s, are dimensiunea %d, este de tip %d si tipul fisierului este %d", fis.nume, fis.dimensiune, fis.tip_doc, fis.tip_file);
}
Fisier f[10];
void ex2()
{

    int aux = 0;
    for(int i = 0; i < 3; i ++)
    {
        scanf("%d", &aux);
        f[i].dimensiune = aux;
        scanf("%d", &aux);
        f[i].tip_doc = aux;
        scanf("%d", &aux);
        f[i].tip_file = aux;
        scanf("%s", &f[i].nume);
        printf("Numele fisierului este %s, are dimensiunea %d, este de tip %d si tipul fisierului este %d", f[i].nume, f[i].dimensiune, f[i].tip_doc, f[i].tip_file);
    }
}

typedef struct
{
    int cod_masina,nr_locuri, putere, an_fabricatie;
    char marca[DIM_MAX], culoare[DIM_MAX];
} Automobil;
Automobil *parc_a = NULL;
int cmp(const void *elem1, const void *elem2)
{
    const Automobil *e1 =(const Automobil *)elem1;
    const Automobil *e2 =(const Automobil *)elem2;
    if(e1->an_fabricatie<=e2->an_fabricatie)
        return -1;
    if(e1->an_fabricatie>e2->an_fabricatie)
        return 1;
        return 0;
}

void ex1_ex()
{
    /*
    Meniu:
        1: Introducerea unui automobil nou
        2: Stergerea unui automobil al carui cod e citit de la tastatura
        3: Afisarea listei de automobile
        4: Afisarea pe ecran a automobilelor cu un anumit nr de locuri
        5: Ordonarea listei in functie de anul fabricatie
    */
    int op, nr_auto = 0, cod  = 0, loc = 0;
    char aux[DIM_MAX];
    for(;;)
    {
        if(scanf("%d", &op) != 1)
            return;
        switch(op)
        {
        case 1:
            if((parc_a = realloc(parc_a, nr_auto+1)) == NULL)
            {
                printf("Memorie insuficienta");
                free(parc_a);
                return;
            }
            scanf("%d",&parc_a[nr_auto].cod_masina);
            scanf("%d",&parc_a[nr_auto].an_fabricatie);
            scanf("%d",&parc_a[nr_auto].putere);
            scanf("%d",&parc_a[nr_auto].nr_locuri);
            scanf("%s", parc_a[nr_auto].marca);
            scanf("%s", parc_a[nr_auto].culoare);
            nr_auto++;
            break;
        case 3:
            printf("%d\n",nr_auto);
            for(int i = 0; i < nr_auto; i++)
                printf("%d %d %d %d %s %s\n", parc_a[i].cod_masina, parc_a[i].an_fabricatie, parc_a[i].putere, parc_a[i].nr_locuri, parc_a[i].marca, parc_a[i] .culoare);
            break;
        case 2:
            scanf("%d", &cod);
            for(int i = 0; i < nr_auto; i++)
            {
                if(parc_a[i].cod_masina == cod)
                {
                    for(int j = i + 1; j < nr_auto; j++)
                        parc_a[j-1] = parc_a[j];
                    nr_auto--;
                    i--;
                }
            }
            parc_a= realloc(parc_a, nr_auto * sizeof(Automobil));
            break;
        case 4:
            scanf("%d", &loc);
            for(int i = 0; i < nr_auto; i++)
            {
                if(parc_a[i].nr_locuri==loc)
                    printf("%d %d %d %d %s %s\n", parc_a[i].cod_masina, parc_a[i].an_fabricatie, parc_a[i].putere, parc_a[i].nr_locuri, parc_a[i].marca, parc_a[i] .culoare);
            }
            break;
        case 5:
            qsort(parc_a, nr_auto, sizeof(Automobil), cmp);
            break;
        case 6:
            free(parc_a);
            break;
        }

    }
}
int main(void)
{
    ex1_ex();
    return 0;
}
