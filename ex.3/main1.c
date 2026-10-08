#include <stdio.h>

int main()
{
   int n = 6;
   int a = n;
   for (int i=1;i<=n;i++){
        for(int j=a;j>0;j--){
            printf(" ");
            
        } 
        for(int p=i;p>0;p--){
            printf("%d ",i);
        }
        printf("\n");
        a--;
   }

    return 0;
}
