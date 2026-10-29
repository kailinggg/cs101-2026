#include <stdio.h>
int mulit(int i, int j){
    if (j==1){
        printf("%d*%d=%d\n",i,j,i*j);
        return 0;
    }else{
        mulit(i,j-1);
        printf("%d*%d=%d\n",i,j,i*j);
    }
}

int main()
{
    mulit(1,9);

    return 0;
}
