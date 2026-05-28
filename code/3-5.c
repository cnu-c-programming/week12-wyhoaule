#include <stdio.h>

int main(int argc, const char* argv[]) {
    const char* filename = "numbers.txt";

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }

    int sum = 0;
    int num;
    char invalid_buf[256];

    while (1) {
        int res = fscanf(fp, "%d", &num);
        
        if (res == 1) {
            sum += num;
        } else if (res == 0) {
            if (fscanf(fp, "%255s", invalid_buf) != EOF) {
                fprintf(stderr, "invalid input %s\n", invalid_buf);
            }
        } else {
            break;
        }
    }

    printf("sum: %d\n", sum);
    fclose(fp);
    return 0;
}
