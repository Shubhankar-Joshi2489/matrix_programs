# include <stdio.h>
int main()
{ int n,a=1,b=0,sum=0;
     printf("enter no till you want fibbo sequenece");
  scanf("%d",&n);

    if(n>1) printf("0,");
    if(n>2) printf("1");
    while(n-2>0)
    { 
        sum=a+b;
        printf(", %d",sum);
        b=a;
        a=sum;
        n=n-1;
    }
   return 0; 
}
