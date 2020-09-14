
//Page Number: 8 
//Euclid's Algorithm for GCD: if u>v, then g(u,v) = g(u-v, v) 
#include<stdio.h>
int gcd(int u, int v)
{
    int t;
    while(u > 0){
        if(u<v){t = u; u = v; v = t;}
        u = u-v;
    }
    return v;
}
int main()
{
    int x, y;
    //while (scanf("%d %d", &x, &y) != EOF)
    x  = 25; y = 45;
    if(x>0 && y>0)
        printf("x: %d y: %d gcd: %d\n", x, y, gcd(x,y));
}