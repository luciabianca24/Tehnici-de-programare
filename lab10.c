#include <stdio.h>
#include<string.h>
#include <stdlib.h>
int cmmdc(int a, int b)
{
    if(b == 0)
        return a;
    else
        return cmmdc(b, a%b);
}
int sum_cif(int n)
{
    if(n == 0)
        return 0;
    else
        return n%10 + sum_cif(n/10);
}
int cif_max(int n)
{
    if (n < 10)
        return n;
    else
    {
        int c = n % 10;
        int mx = cif_max(n / 10);
        if(c > mx)
            return c;
        else
            return mx;
    }
}
int fibo(int n)
{
    if(n == 0 || n == 1)
        return 1;
    else
        return fibo(n-1) + fibo(n-2);
}
char *sir_fibo(char *s1, char *s2, int n)
{
    if(n == 1)
        return s1;
    else{
        if(n == 2)
            return s2;
        else{
            char *s = NULL;
            s = malloc((strlen(s1)+strlen(s2)+1) * sizeof(char));
            strcpy(s, s1);
            strcat(s, s2);
            return sir_fibo(s2,s,n-1);}
    }

}
float suma(int x, float mx, int n, float ant)
{
    float curent = ant * x/n;
    if(curent <= mx)
        return 1;
    else
        return curent + suma(x, mx, n+1, curent);
}

int binarySearch(int *v, int st, int dr, int x)
{
    if (st > dr)
    {
        return -1;
    }
    else
    {
        int m = (st + dr) / 2;
        if (v[m] == x)
            return m;
        else
        {
            if (v[m] < x)
                return binarySearch(v, mij + 1, dr, x);
            else
                return binarySearch(v, st, mij - 1, x);
        }
    }
}
int main()
{
    //printf("%d",cmmdc(10,15));
    //printf("%d", sum_cif(3578));
    //printf("%d", fibo(6));
    //printf("%s", sir_fibo("ana", "mere", 4));
    printf("%f", suma(2,0.0001,1,1));
    return 0;
}
