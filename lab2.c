#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define DIM_MAX 100
typedef struct
{
  char nume[DIM_MAX];
  int nota;
}Pt;
int cmp1(const void *elem1, const void *elem2)
{
  const Pt *p1 = (const Pt*)elem1;
  const Pt *p2 = (const Pt*)elem2;
  if(p1->nota > p2->nota)
    return -1;
  if(p1->nota == p2->nota)
    {
      if(p1->nume < p2->nume)
	return -1;
      return 1;
    }
  if(p1->nota < p2->nota)
    return 1;
  return 0;
}
void ex1()
{
  Pt elev[DIM_MAX];
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    {
      scanf("%d", &elev[i].nota);
      fgets(elev[i].nume, DIM_MAX, stdin);
      int lcuv = strlen(elev[i].nume);
      elev[i].nume[lcuv - 1] = 0;
    }
  qsort(elev, n, sizeof(Pt), cmp1);
  for(int i = 0; i < n; i++)
  printf("%s %d\n", elev[i].nume, elev[i].nota);
}
int par(int x)
{
  if(x % 2 == 0)
    return 1;
  else
    return 0;
}
void stergere(int *v, int *n, int (*cond)(int))
{
  int nr = *n;
  for(int i = 0; i < nr; i++)
    {
      if(cond(v[i]) == 0)
	{
	  for(int j = i; j < nr; j++)
	    v[j] = v[j + 1];
	  nr--;
	  i--;
	}
    }
  *n = nr;

}
void ex2()
{
   int n = 0, v[DIM_MAX];
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  stergere(v, &n, par);
  for(int i = 0; i < n; i++)
    printf("%d ", v[i]);
}
int cmp3(const void *elem1, const void *elem2)
{
  const int *e1 = (const int *)elem1;
  const int *e2 = (const int *)elem2;
  if(*e1 < *e2)
    return -1;
  if(*e1 > *e2)
    return 1;
  return 0;
}
void ex3()
{
  int n;
  scanf("%d", &n);
  int v[DIM_MAX];
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  qsort(v,n,sizeof(int),cmp3);
  for(int i = 0; i < n; i++)
    printf("%d", v[i]);

}
void tabelare(double a, double b, int n, double(*f)(double))
{
    int p = (b - a)/n;
    for(double i =a; i <=b; i +=p)
        printf("f(%f)=%f\n",i,f(i));
}
void examen_1(double a, double b, int p, double(*f)(double))
{
    for(double i = a; i <= b; i += p)
        printf("f(%f) = %f\n", i, f(i));
}
double f1(double x)
{
     return x + 10;
}
double f2(double x)
{
    return 2*x*x-1;
}
double f3(double x)
{
    return (x*x*x+4)/(x*x+5);
}
void apel_examen1()
{
    examen_1(2, 4, 1, f1);
    examen_1(2, 4, 1, f2);
    examen_1(2, 4, 1, f2);
}
double fabs(double x)
{
    if(x < 0)
        return -x;
    else
        return x;
}
int lungime_sir(char *s)
{
    return strlen(s);
}

int nr_vocale(char *s)
{
    int k = 0, l = strlen(s);
    for (int i = 0; i < l; i++)
        if (strchr("AEIOUaeiou", s[i]))
            k++;
    return k;
}

int nr_lit_mari(char *s)
{
    int k = 0;
    int l = strlen(s);
    for (int i = 0; i < l; i++)
        if (isupper(s[i]))
            k++;
    return k;
}

int dif_ASCII(char *s)
{
    int l = strlen(s);
    return s[0] - s[l - 1];
}

void p6(int argc, char **argv)
{
    FILE *fis = NULL;
    if ((fis = fopen("CUVINTE.TXT", "w")) == NULL)
    {
        printf("Nu se poate de schide fisierul");
        return;
    }

    int (*functii[])(char *) = {lungime_sir, nr_vocale, nr_lit_mari, dif_ASCII};

    for (int i = 1; i < argc; i++)
    {
        printf("Cuvantul %s are %d litere, %d vocale, %d litere mari si diferenta dintre primul si ultimul caracter este %d\n", argv[i], functii[0](argv[i]), functii[1](argv[i]), functii[2](argv[i]), functii[3](argv[i]));
        fprintf(fis, "Cuvantul %s are %d litere, %d vocale, %d litere mari si diferenta dintre primul si ultimul caracter este %d\n", argv[i], functii[0](argv[i]), functii[1](argv[i]), functii[2](argv[i]), functii[3](argv[i]));
    }

    if (fclose(fis) != 0)
    {
        printf("Nu se poate inchidefisierul");
        return;
    }
}
int main(void)
{
  //apel_examen1();
  //tabelare(-10, 10,20,fabs);
}
