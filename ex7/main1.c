#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    int n;
    
    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透彩：");
    scanf("%d", &n);

    srand((unsigned)time(NULL));

    FILE *fp = fopen("lotto.txt", "w");
    if (fp == NULL) {
        return 1;
    }

    time_t now = time(NULL);
    char *time_str = ctime(&now);
    time_str[strcspn(time_str, "\n")] = '\0';

    fprintf(fp, "========= lotto649 =========\n");
    fprintf(fp, "= %s =\n", time_str);

    for (int i = 1; i <= 5; i++) {
        fprintf(fp, "[%d]: ", i);

        if (i <= n) {
            int lotto[7];
            
            for (int j = 0; j < 7; j++) {
                int num, duplicate;
                do {
                    duplicate = 0;
                    num = rand() % 69 + 1;
                    for (int k = 0; k < j; k++) {
                        if (lotto[k] == num) {
                            duplicate = 1;
                            break;
                        }
                    }
                } while (duplicate);
                lotto[j] = num;
            }

            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5 - j; k++) {
                    if (lotto[k] > lotto[k + 1]) {
                        int temp = lotto[k];
                        lotto[k] = lotto[k + 1];
                        lotto[k + 1] = temp;
                    }
                }
            }

            for (int j = 0; j < 7; j++) {
                fprintf(fp, "%02d", lotto[j]);
                if (j < 6) fprintf(fp, " ");
            }
            fprintf(fp, "\n");
        } else {
            fprintf(fp, "-- -- -- -- -- -- --\n");
        }
    }

    fprintf(fp, "========= csie@CGU =========\n");
    fclose(fp);

    printf("以為您購買的 %d 組樂透組合輸出至 lotto.txt\n", n);

    return 0;
}
