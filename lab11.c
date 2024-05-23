#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int x,y;
}Pt;
int cmpDist(const void *elem1, const void *elem2)
{
    int d1, d2;
    const Pt *p1 = (const Pt*)elem1;
    const Pt *p2 = (const Pt*)elem2;
    d1 = p1->x*p1->x+ p1->y*p1->y;
    d2 = p2->x*p2->x+ p2->y*p2->y;
    if(d1 < d2)
        return -1;
    if(d1 > d2)
        return 1;
    return 0;
}
void ex1()
{
    int n;
    Pt *p;
    scanf("%d", &n);
    if((p = malloc(n * sizeof(Pt))) == NULL)
        return NULL;
    for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &p[i].x, &p[i].y);
        }
    qsort(p, n, sizeof(Pt), cmpDist);
    for(int i = 0; i < n; i++)
    {
        printf("%d %d\n", p[i].x, p[i].y);
    }
}
int G = 667400000000;
int forta(float m1, float m2, float d)
{
    float F = 0;
    F = G*m1*m2/(d*d);
    return F;
}
void ex2()
{
    int n = 0;
    float ma = 0, mb = 0, m = 0, d = 0;
    float pas, Fa = 0, Fb = 0;
    scanf("%d %f %f %f %f", &n, &ma, &mb, &m, &d);
    pas = d/n;
    for(int i = 0; i <= n; i++)
    {
        Fa = forta(ma, m, pas * i);
        Fb = forta(mb, m, d - pas * i);
        printf("%f %f\n",Fa, Fb);
    }

}
typedef struct
{
    int valoare;
    char nume[16];
}Jucator;
int cmpJucator(const void *elem1, const void *elem2)
{
    const Jucator *j1 = (const Jucator*)elem1;
    const Jucator *j2 = (const Jucator*)elem2;
    if(j1->valoare > j2->valoare)
        return 1;
    if(j1->valoare < j2->valoare)
        return -1;
    return 0;
}
void ex4()
{
    Jucator *j = NULL;
    int n = 0, grupa = 1, m =0, k = 0;
    scanf("%d %d", &n, &m);
    if((j = malloc(n * sizeof(Jucator))) == NULL)
        return NULL;
    for(int i = 0; i < n; i++)
        scanf("%d %s", &j[i].valoare, &j[i].nume);
    qsort(j,n,sizeof(Jucator),cmpJucator);
    for(int i = n - 1; i >=0; i--)
    {
        if((grupa - 1) % m == 0)
            {
                grupa = 1;
            }
        printf("%d %s %d\n", grupa, j[i].nume, j[i].valoare);
        grupa ++;
    }
}
void scriere_cifra(int c)
{
    if(c == 1)
        printf("%s","unu");
    if(c == 2)
        printf("%s","doi");
    if(c == 3)
        printf("%s","trei");
    if(c == 4)
        printf("%s","patru");
    if(c == 5)
        printf("%s","cinci");
    if(c == 6)
        printf("%s","sase");
    if(c == 7)
        printf("%s","sapte");
    if(c == 8)
        printf("%s","opt");
    if(c == 9)
        printf("%s","noua");
    if(c == 0)
        printf("%s","zero");
}
void scriere_10(c)
{
    if(c == 11)
        printf("%s","unsprezece");
    if(c == 12)
        printf("%s","doisprezece");
    if(c == 13)
        printf("%s","treisprezece");
    if(c == 14)
        printf("%s","paisprezece");
    if(c == 15)
        printf("%s","cincisprezece");
    if(c == 16)
        printf("%s","saisprezece");
    if(c == 17)
        printf("%s","saptesprezece");
    if(c == 18)
        printf("%s","optsprezece");
    if(c == 19)
        printf("%s","nouasprezece");
    if(c == 10)
        printf("%s","zece");
}
void scriere_nr_2_cif(int n)
{
    if(10 <= n && n <= 19)
        scriere_10(n);
    if(20 <= n && n <= 90)
    {
        if(n/10 == 2)
            printf("doua");
        else
            scriere_cifra(n/10);
        printf("zeci ");
        if(n % 10 != 0)
        {
            printf("si ");
            scriere_cifra(n%10);
        }
    }
}
void ex5()
{
    int n;
    scanf("%d", &n);
    if(n < 10)
    scriere_cifra(n);
    if(n >= 10 && n <= 90)
        scriere_nr_2_cif(n);
    if(n >= 100)
    {
        if(n / 100 == 1)
            printf("o suta ");
        else
        {
            if(n / 100 == 2)
                printf("doua");
            if(n/ 100 > 2)
                scriere_cifra(n/100);
            printf(" sute ");
        }
        if(n % 100 >= 10 && n % 100 <= 99)
            scriere_nr_2_cif(n % 100);
        if(n % 100 < 10)
            scriere_cifra(n%100);
    }

}
int main()
{
    ex5();
    return 0;
}
