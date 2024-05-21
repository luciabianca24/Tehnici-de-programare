#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
float *allocVec(int n,...)
{
    va_list va;
    va_start(va,n);
    float *f = NULL;
    if((f = malloc(n*sizeof(float)))== NULL)
       {
           va_end(va);
           return NULL;
       }
    for(int i = 0; i < n; i++)
        f[i] = va_arg(va,double);
    va_end(va);
    return f;

}
void p2()
{
    float *f = NULL;
    f = allocVec(3, 7.2, -1.0, 0.0);
    for(int i = 0; i <3 ;i++)
        printf("%f ", f[i]);
}
void absN(int n, ...)
{
    va_list va;
    float *ptr;
    va_start(va, n);
    for (int i = 0; i < n; i++)
    {
        ptr = va_arg(va, float *);
        *ptr = fabs(*ptr);
    }
    va_end(va);
}

void p3(void)
{
    float x = -12.3, y = 4.5;
    absN(2, &x, &y);
    printf("%f %f\n", x, y);
}
int crescator(int n, char tip,...){
    va_list va;
    va_start(va,n);
    int xa,x;
    float ya,y;
    if(tip == 'd')
    {
        xa = va_arg(va,int);
        for(int i = 1; i < n; i++)
        {
            x = va_arg(va,int);
            if(xa > x)
                return 0;
            xa = x;
        }
    }
    else
    {
        if(tip == 'f')
        {
            ya = va_arg(va,float);
            for(int i = 1; i < n; i++)
            {
                y = va_arg(va,float);
                if(ya > y)
                    return 0;
                ya = y;
            }
        }
    }
    va_end(va);
    return 1;
}
void p4()
{
       printf("%d\n", crescator(3, 'd', -1, -5, 9));
}
void input(const char *fmt,...)
{
    int *p1 = NULL;
    float *p2 = NULL;
    char *p3 = NULL;
    va_list va;
    va_start(va,fmt);
    int n = strlen(fmt);
    for(int i = 1; i < n; i++)
    {
        if(fmt[i-1] == '%')
        {
            if(fmt[i] == 'd')
            {
                p1 = va_arg(va, int *);
                scanf("%d", p1);
            }
            if(fmt[i] == 'f')
            {
                p2 = va_arg(va, float *);
                scanf("%f", p2);
            }
            if(fmt[i] == 'c')
            {
                p3 = va_arg(va, char *);
                scanf("%c", p3);
            }
        }
    }
    va_end(va);
    }
void p5()
{
    int n;
    char ch;
    input("n=%cch=%dh",&ch,&n);
    printf("%d %c", n, ch);
}
char *concat(int n,...)
{
    va_list va;
    va_start(va,n);
    int l = 0;
    char *s = NULL, *ns = NULL;
    for(int i = 0; i < n; i++)
    {
        s = va_arg(va, char *);
        l = l + strlen(s);
        if((ns = realloc(ns,(l + 2)*sizeof(char)))==NULL)
        {
            va_end(va);
            return NULL;
        }
        strcat(ns, s);
        strcat(ns, " ");
    }
    va_end(va);
    return ns;
}

void p6()
{
    char *string = concat(3, "Ion", "si", "Ana");
    printf("%s\n", string);
    free(string);
}
void sortare(int n,...)
{
    va_list va;
    va_start(va,n);
    int *v = NULL, aux = 0;
    if((v = malloc(n*sizeof(int))) == NULL)
        return;
    for(int i = 0; i < n; i++)
    {
        v[i] = *(va_arg(va, int *));
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(v[i] > v[j])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
    va_start(va,n);
    for(int i = 0; i < n; i++)
    {
       *(va_arg(va, int *)) = v[i];
    }
    free(v);
    va_end(va);
}
void p8()
{
    int x = 5, y = 3, z = 8;
    sortare(3, &x, &y, &z);
    printf("%d %d %d\n", x, y, z);
}
void p9(int argc, char **argv)
{
    if(argc != 4)
        return NULL;
    int a = atof(argv[1]), b = atof(argv[2]), c = atof(argv[3]);
    printf("%d", a+b+c);
}
int main(int argc,char **argv)
{
    p9(argc,argv);
}
