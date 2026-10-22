#include <stdio.h>

int main() {
    FILE *fp;

    
    int a[] = {0, 1, 2};
    char b[] = "ABC";
    float c[] = {1.1, 1.2, 1.3};

    
    int r_a[3];
    char r_b[4]; 
    float r_c[3];

    fp = fopen("a.bin", "wb");
    if (fp == NULL) {
        printf("檔案開啟失敗！\n");
        return 1;
    }

    fwrite(a, sizeof(int), 3, fp);
    fwrite(b, sizeof(char), 4, fp);
    fwrite(c, sizeof(float), 3, fp);

    fclose(fp);

    
    fp = fopen("a.bin", "rb");
    if (fp == NULL) {
        printf("檔案開啟失敗！\n");
        return 1;
    }

    fread(r_a, sizeof(int), 3, fp);
    fread(r_b, sizeof(char), 4, fp);
    fread(r_c, sizeof(float), 3, fp);

    fclose(fp);

    
    for (int i = 0; i < 3; i++) {
        printf("%d ", r_a[i]);
    }
    printf("\n");

   
    printf("%s\n", r_b);

    
    for (int i = 0; i < 3; i++) {
        printf("%.6f ", r_c[i]);
    }
    printf("\n");

    return 0;
}
