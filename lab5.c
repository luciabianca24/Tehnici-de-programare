#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#define BLOCK_SIZE 4096
void citire_matrice(int **a, int m, int n)
{
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
}
void p3()
{
    int m, n;
    FILE *fout = NULL;
    scanf("%d %d", &m, &n);
    int **a = NULL;
    if ((a = malloc(m * sizeof(int *))) == NULL)
    {
        printf("Memorie insuficienta");
        return;
    }
    int i, j;
    for (i = 0; i < m; i++)
    {
        if ((a[i] = malloc(n * sizeof(int))) == NULL)
        {
            for(int j = i - 1; j >= 0; j--)
                free(a[i]);
            free(a);
            printf("Memorie insuficienta");
            return;
        }
    }
    citire_matrice(a,m,n);
    if ((fout = fopen("matrice.txt", "wb")) == NULL)
    {
        printf("Nu s-a putut deschide fisierul");
        return;
    }
    fprintf(fout, "%d %d\n", m, n);
    for (i = 0; i < m; i++, fprintf(fout, "\n"))
        for (j = 0; j < n; j++)
            fprintf(fout, "%d ", a[i][j]);
    for (i = 0; i < m; i++)
    {
        free(a[i]);
    }
    free(a);

    if (fclose(fout) != 0)
    {
        printf("Nu s-a putut inchide fisierul");
        return;
    }
}
typedef struct
{
    char *nume;
    float pret;
} Produs;

Produs produse[1000];
int nProduse;

void citire()
{
    FILE *fis;
    unsigned short nNume;

    if ((fis = fopen("produse.dat", "rb")) == NULL)
        return;
    int dimensiune;
    fread(&dimensiune, sizeof(int), 1, fis);
    for (int i = 0; i < dimensiune; i++)
    {
        fread(&nNume, sizeof(unsigned short), 1, fis);
        char *pNume = (char *)malloc((nNume + 1) * sizeof(char));
        fread(pNume, sizeof(char), nNume, fis);
        pNume[nNume] = '\0';
        produse[nProduse].nume = pNume;
        fread(&produse[nProduse].pret, sizeof(float), 1, fis);
        nProduse++;
    }
}

void adaugare()
{
    Produs p;
    char nume[1000];

    printf("nume: ");
    fgets(nume, 1000, stdin);
    nume[strcspn(nume, "\r\n")] = '\0';
    if ((p.nume = (char *)malloc((strlen(nume) + 1) * sizeof(char))) == NULL)
    {
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
    }
    strcpy(p.nume, nume);
    printf("pret: ");
    scanf("%g", &p.pret);
    produse[nProduse] = p;
    nProduse++;
}

void afisare()
{
    int i;
    for (i = 0; i < nProduse; i++)
    {
        printf("%s: %g\n", produse[i].nume, produse[i].pret);
    }
}

void scriere()
{
    FILE *fis;
    int i;
    unsigned short nNume;

    if ((fis = fopen("produse.dat", "wb")) == NULL)
    {
        printf("nu se poate deschide fisierul\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < nProduse; i++)
    {
        nNume = (unsigned short)strlen(produse[i].nume);
        fwrite(&nNume, sizeof(unsigned short), 1, fis);
        fwrite(produse[i].nume, sizeof(char), nNume, fis);
        fwrite(&produse[i].pret, sizeof(float), 1, fis);
    }

    fclose(fis);
}

void eliberare()
{
    int i;
    for (i = 0; i < nProduse; i++)
        free(produse[i].nume);
}
void p2(int argc, char **argv)
{
    FILE *src = NULL, *dst = NULL;
    if ((src = fopen(argv[1], "rb")) == NULL)
    {
        printf("Nu s-a putut deschide fisierul sursa");
        return;
    }
    if ((dst = fopen(argv[2], "wb")) == NULL)
    {
        printf("Nu s-a putut deschide fisierul destinatie");
        return;
    }

    char buffer[BLOCK_SIZE];
    int bytes = 0;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0)
    {
        fwrite(buffer, 1, bytes, dst);
    }

    if (fclose(src) != 0)
    {
        printf("Nu s-a putut inchide fisierul sursa");
        return;
    }
    if (fclose(dst) != 0)
    {
        printf("Nu s-a putut inchide fisierul destinatie");
        return;
    }
}
void p4()
{
    int optiune;
    citire();
    do
    {
        printf("optiune: ");
        scanf("%d", &optiune);
        getchar();
        switch (optiune)
        {
        case 1:
            adaugare();
            break;
        case 2:
            afisare();
            break;
        case 3:
            scriere();
            eliberare();
            break;
        default:
            printf("optiune invalida\n");
        }
    }
    while (optiune != 3);
}
int main(void)
{
    p3();
}
