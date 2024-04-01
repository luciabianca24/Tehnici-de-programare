#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define DIM_MAX 100
int **alocare_matrice(int m, int n)
{
    int **a = NULL;
    if((a = malloc(m * sizeof(int*))) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    for(int i = 0; i < m; i++)
    {
        if((a[i] = malloc(n * sizeof(int))) == NULL)
        {
            for(int j = i -1; j >= 0; j--)
                free(a[j]);
            free(a);
            perror(NULL);
            exit(-1);
        }
    }
    return a;
}
void eliberare(int **a, int m, int n)
{
    for(int i = 0; i < m; i++)
        free(a[i]);
    free(a);
}
void afisare1(int **a, int m, int n)
{
    for(int i = 0; i < m; i++, printf("\n"))
        for(int j = 0; j <n; j++)
            printf("%d ", a[i][j]);
}
void citire1(int **a, int m, int n)
{
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
}
void afisare2(int a[DIM_MAX][DIM_MAX], int m, int n)
{
    for(int i = 0; i < m; i++, printf("\n"))
        for(int j = 0; j <n; j++)
            printf("%d ", a[i][j]);
}
void citire2(int a[DIM_MAX][DIM_MAX], int m, int n)
{
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
}

void ex1()
{
    int m = 0, n = 0;
    scanf("%d", &m);
    scanf("%d", &n);
    int **a = NULL;
    int k = 1;
    a = alocare_matrice(m, n);
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            a[i][j] = k++;
    afisare1(a, m, n);
    eliberare(a, m, n);
}
void ex2()
{
    int n = 0, aux = 0;
    scanf("%d", &n);
    int a[DIM_MAX][DIM_MAX];
    citire2(a, n, n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < i; j++)
            aux = a[i][j], a[i][j] = a[j][i], a[j][i] = aux;
    afisare2(a, n, n);
}
void resetare(int *v, int size)
{
    for(int i = 0; i < size; i++)
        v[i] = 0;
}
void afisare_vector(int *v, int size)
{
    for(int i = 0; i < size; i++)
        printf("%d ", v[i]);
}
void ex3()
{
    int n = 0;
    int **a = NULL, *sl = NULL, *sc = NULL;
    scanf("%d", &n);
    a = alocare_matrice(n, n);
    if((sl = malloc(n * sizeof(int))) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    if((sc = malloc(n * sizeof(int))) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    resetare(sl, n);
    resetare(sc, n);
    citire1(a, n, n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            sl[i] = sl[i] + a[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            sc[i] += a[j][i];
    afisare_vector(sl, n);
    printf("\n");
    afisare_vector(sc, n);
}
void ex5()
{
    int n = 0, a[DIM_MAX][DIM_MAX];
    scanf("%d", &n);
    citire2(a, n, n);
    int mn = a[0][0], imn = 0, jmn = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i][j] < mn && a[i][j] != 0)
                mn = a[i][j], imn = i, jmn = j;
        }
    }
    printf("%d %d", imn + 1, jmn + 1);
}
void ex7()
{
    int n = 0, a[DIM_MAX][DIM_MAX];
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j)
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
    }
    afisare2(a, n, n);
}
int verif_cresc(int *v, int size)
{
    for(int i = 0; i < size - 1; i++)
        for(int j = i + 1; j < size; j++)
            if(v[i] > v[j])
                return 0;
    return 1;
}
void ex8()
{
    int m = 0, n = 4, a[DIM_MAX][DIM_MAX];
    scanf("%d", &m);
    citire2(a, m, n);
    for(int i = 0; i < m; i++)
    {
        if(verif_cresc(a[i], n) == 1)
            printf("%d ", i);
    }

}
void p1_examen()
{
    int n1 = 0, n2 = 0, ok = 0;
    scanf("%d", &n1);
    scanf("%d", &n2);
    int a1[DIM_MAX][DIM_MAX], a2[DIM_MAX][DIM_MAX], exista = 0;
    citire2(a1, n1, n1);
    citire2(a2, n2, n2);
    for(int i = 0; i < n1; i++)
    {
        for(int j = 0; j < n1; j++)
        {

            if(a1[i][j] == a2[0][0])
            {

                if(i + n2 <= n1 && j + n2 <= n1)
                {
                    ok = 1;
                    for(int k = 0; k < n2 && ok; k++)
                    {
                        for(int l = 0; l < n2 && ok; l++)
                        {
                            if(a2[k][l] != a1[i + k][j + l])
                                ok = 0;
                        }
                    }
                    if(ok == 1)
                        {
                            exista = 1;
                            printf("(%d,%d)", i, j);
                        }
                }

            }

        }
    }
    if(exista == 0)
        printf("Nu apare");
}
void citire_p2(char a[DIM_MAX][DIM_MAX], int n)
{
    int i = 0, j = 0;
    char c;
    while((c = getchar()) != NULL)
    {
        if(c != ' ' && c != '\n')
        {
            a[i][j] = c;
            j++;
            if(j == n)
            {
                i++;
                j = 0;
            }
        }
        if(i == n)
            break;
    }
}
int verif_linie_sd(char a[DIM_MAX][DIM_MAX],char *s, int i, int j)
{
    int l = strlen(s);
    for(int k = 0; k < l; k++)
    {
        if(a[i][j+k] != s[k])
            return 0;
    }
    return 1;
}
int verif_col_sj(char a[DIM_MAX][DIM_MAX],char *s, int i, int j)
{
    int l = strlen(s);
    for(int k = 0; k < l; k++)
    {
        if(a[i+k][j] != s[k])
            return 0;
    }
    return 1;
}
int verif_col_js(char a[DIM_MAX][DIM_MAX], char *s, int i, int j)
{
    int l = strlen(s);
    for(int k = 0; k < l; k++)
    {
        if(a[i-k][j] != s[k])
            return 0;
    }
    return 1;
}
int verif_linie_ds(char a[DIM_MAX][DIM_MAX],char *s, int i, int j)
{
    int l = strlen(s);
    for(int k = 0; k < l; k++)
    {
        if(a[i][j - k] != s[k])
            return 0;
    }
    return 1;
}
void p2_examen()
{
    int n = 0, ok =0;
    char s[DIM_MAX], a[DIM_MAX][DIM_MAX];
    scanf("%d", &n);
    citire_p2(a, n);
    scanf("%s", s);
    int l = strlen(s);
    for(int i = 0; i < n; i++, printf("\n"))
        for(int j = 0; j < n; j++)
            printf("%c ", a[i][j]);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i][j] == s[0])
            {
                if(j + l <= n)
                {
                    if(verif_linie_sd(a,s,i,j))
                    {
                        ok = 1;
                        printf("De la linia %d coloana %d spre dreapta\n", i, j);
                    }
                }
                if(i + l <= n)
                {
                    if(verif_col_sj(a, s, i, j))
                    {
                        ok = 1;
                        printf("De la linia %d coloana %d in jos\n", i, j);
                    }
                }
                if(i - l >= -1)
                {
                    if(verif_col_js(a, s, i, j))
                    {
                        ok = 1;
                        printf("De la linia %d coloana %d in sus\n",i, j);
                    }
                }
                if(j - l >= -1)
                {
                    if(verif_linie_ds(a, s, i, j))
                    {
                        ok = 1;
                        printf("De la linia %d coloana %d spre stanga \n", i, j);
                    }
                }
            }
        }
    }
    if(ok == 0)
        printf("Nu exista solutie");
}
int main(void)
{
    p1_examen();
}
