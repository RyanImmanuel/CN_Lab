

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int compute(int a, int m, int n)
{   
    return fmod(pow(a,m),n);
}

int main()
{   int p,g,x,y,R1,R2,keyA,keyB;
    printf("Enter p & g : ");
    scanf("%d%d",&p,&g);  
     
    printf("enter x : ");
    scanf("%d",&x);
    printf("Xa=%d\n",x);       
    
    R1 = compute(g, x, p);
    printf("Ya=%d\n",R1);   
    
    printf("enter y : ");
    scanf("%d",&y);       
    printf("Xb=%d\n",y);   
   
    
    R2 = compute(g, y, p);
    printf("Yb=%d\n",R2);   


    keyA = compute(R2, x, p);
    keyB = compute(R1, y, p);
    printf("A's secret key is %d\nB's secret key is %d\n", keyA, keyB);
}
