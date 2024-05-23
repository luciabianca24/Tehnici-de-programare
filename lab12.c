#include <stdio.h>
#include <stdlib.h>
int v[100], a[100];
int verif1(int k, int cnt)
{
    if(v[1] == 0)
        return 0;
    for(int i = 1; i <= k; i++)
        {
            if(v[i] == 1)
                cnt--;
            if(cnt < 0)
                return 0;
        }
    return 1;
}
void afisare(int k)
{
    for(int i = 1; i <= k; i++)
        printf("%d ", v[i]);
    printf("\n");
}
void bkt1(int k, int n, int cnt)
{
    for(int i = 0; i <= 9; i++)
    {
        v[k] = i;
        if(verif1(k, cnt))
        {
            if(k == n)
                afisare(k);
            else
                bkt1(k+1, n, cnt);
        }
    }
}
void ex1()
{

    int n, k;
    scanf("%d %d", &n, &k);
    bkt1(1,n,k);
}
int verif2(int k)
{
    for(int i = 1; i < k; i++)
        if(v[i] == v[k])
            return 0;
    for(int i = 1; i <= k/2; i++)
        if(v[i] < v[i+1])
            return 0;
    for(int i = k/2 + 1; i < k; i++)
        if(v[i] > v[i+1])
        return 0;
    return 1;
}
void bkt2(int k, int n)
{
    for(int i = 1; i <= n; i++)
    {
        v[k] = i;
        if(verif2(k))
        {
            if(k == n)
                afisare(k);
            else
                bkt2(k+1, n);
        }
    }
}
void ex2()
{

    int n, k;
    scanf("%d", &n);
    bkt2(1,n);
}
int mx = 0;
int maxim(int n)
{
    int nr = 0;
    for(int i = 1; i <= n; i++)
        nr = nr * 10 + v[i];
    if(nr > mx)
        mx = nr;
}
int verif3(int k)
{
    for(int i = 1; i < k; i++)
        if(v[i] == v[k])
            return 0;
    return 1;
}
void bkt3(int k, int cif, int n)
{
    for(int i = 1; i <= cif; i++)
    {
        v[k] = a[i];
        if(verif2(k))
        {
            if(k == n)
                maxim(k);
            else
                bkt3(k+1,cif, n);
        }
    }
}
void ex3()
{
    int n, nr,k, cif = 0, inv = 0;
    scanf("%d %d", &nr, &k);
    while(nr)
    {
        inv = inv * 10 + nr%10;
        nr/=10;
    }
    nr = inv;
    while(nr)
    {
        cif++;
        a[cif] = nr%10;
        nr/=10;

    }
    n = cif - k;
    bkt3(1,cif,n);
    printf("%d", mx);
}
void afisare4()
{
    for(int i = 1; i <= 3; i++)
    {
        if(v[i] == 1)
            printf("%s ", "alb");
        if(v[i] == 2)
            printf("%s ", "galben");
        if(v[i] == 3)
            printf("%s ", "rosu");
        if(v[i] == 4)
            printf("%s ", "verde");
        if(v[i] == 5)
            printf("%s ", "albastru");
        if(v[i] == 6)
            printf("%s ", "negru");
    }
    printf("\n");
}
int verif4(int k)
{
    for(int i = 1; i < k; i++)
        {
            if(v[i] == v[k])
                return 0;
        }
    if(k == 2)
   {
     if(v[2] != 2 && v[2] != 4)
         return 0;
   }
    return 1;
}
void bkt4(int k)
{
    for(int i = 1; i <= 6; i++)
    {
        v[k] = i;
        if(verif4(k))
        {
            if(k == 3)
                afisare4();
            else
                bkt4(k+1);
        }
    }
}
void ex4()
{
    bkt4(1);
}
int verif5(int k)
{
    for(int i = 1; i < k; i++)
        {
            if(v[i] == v[k])
                return 0;
        }
    return 1;
}
int solutie(int k, int s)
{
    int suma = 0;
    for(int i = 1; i <= k; i++)
        suma += v[i];
    if(suma <= s)
        return 1;
    return 0;
}
void bkt5(int k, int s, int n)
{
    for(int i = 1; i <= n; i++)
    {
        v[k] = a[i];
        if(verif5(k))
        {
            if(solutie(k, s))
                afisare(k);
            bkt5(k+1, s, n);
        }
    }
}
void ex5()
{
    int n, s;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d ", &a[i]);
    scanf("%d", &s);
    bkt5(1,s,n);
}
void afisare6(int n)
{
    for(int i = 1; i <= n; i++)
    {
        if(v[i] == 1)
            printf("%s", "casa");
        if(v[i] == 2)
            printf("%s", "bloc");
        if(v[i] == 3)
            printf("%s", "gradina");
        if(v[i] == 4)
            printf("%s", "atelier");
    }
    printf("\n");
}
int verif6(int k)
{
    for(int i = 1; i < k; i++)
    {
        if(v[i] == 1 && v[i + 1] != 2)
            return 0;
        if(v[i] == 2 && (v[i + 1] != 1 || v[i + 1] != 3))
            return 0;
        if(v[i] == 3 &&(v[i + 1] != 1 || v[i + 1] != 4))
            return 0;
        if(v[i] == 4 && v[i + 1] != 3)
            return 0;
    }
    return 1;
}
void bkt6(int k, int n)
{
    for(int i = 1; i <= n; i++)
    {
        v[k] = a[i];
        if(verif6(k))
        {
            if(k == n)
                afisare6(k);
            else
                bkt6(k+1, n);
        }
    }
}
void ex6()
{
    //1-case 2-blocuri 3-gradini 4-ateliere
    int c,b,g,at, n;
    scanf("%d %d %d %d", &c,&b,&g,&at);
    for(int i = 1; i <= c; i++)
        a[++n] = 1;
    for(int i = 1; i <= b; i++)
        a[++n] = 2;
    for(int i = 1; i <= g; i++)
        a[++n] = 3;
    for(int i = 1; i <= at; i++)
        a[++n] = 4;
    bkt6(1,n);
}
int solutie8(int k, int s)
{
    int suma = 0;
    for(int i = 1; i <= k; i++)
        suma += v[i];
    if(s == suma)
        return 1;
    return 0;
}
int verif8(int k)
{
    for(int i = 1; i < k; i++)
        if(v[i] >= v[i + 1])
        return 0;
    return 1;
}
void bkt8(int k, int s, int n)
{
    for(int i = 1; i <= s; i++)
    {
        v[k] = i;
        if(verif8(k))
        {
            if(k == n && solutie8(k, s))
                afisare(k);
            bkt8(k+1, s, n);
        }
    }
}
void ex8()
{
    int d,n;
    scanf("%d %d", &d, &n);
    bkt8(1, d, n);
}
int main()
{
    ex8();
    return 0;
}
