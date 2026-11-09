#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <logfile> <keyword>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("Error opening log file");
        return 1;
    }

    char line[512];
    int line_num = 0;
    int alert_count = 0;

    printf("\n========================================\n");
    printf("           LOG ANALYSIS REPORT          \n");
    printf("========================================\n");

    while (fgets(line, sizeof(line), fp)) {
        line_num++;
        if (strstr(line, argv[2])) {
            alert_count++;
            printf("[Line %d] %s", line_num, line);
        }
    }

    printf("----------------------------------------\n");
    printf("Total Suspicious Alerts Found: %d\n", alert_count);
    printf("========================================\n");

    fclose(fp);
    return 0;
}