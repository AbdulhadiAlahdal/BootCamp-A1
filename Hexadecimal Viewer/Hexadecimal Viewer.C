#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void dump_hex(FILE *fp) {
    unsigned char buf[16];
    size_t n;
    unsigned long addr = 0;

    while ((n = fread(buf, 1, sizeof(buf), fp)) > 0) {
        printf("%08lX: ", addr);

        for (int i = 0; i < 16; i++) {
            if (i < n) {
                printf("%02X ", buf[i]);
            } else {
                printf("   ");
            }
        }

        printf(" |");

        for (int i = 0; i < n; i++) {
            if (buf[i] >= 32 && buf[i] <= 126) {
                printf("%c", buf[i]);
            } else {
                printf(".");
            }
        }
        printf("|\n");

        addr += n;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    dump_hex(fp);
    
    fclose(fp);
    return 0;
}
