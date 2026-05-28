#include <stdio.h>

int main(int argc, const char* argv[]) {
    if (argc < 2) {
        printf("사용법: %s <파일경로>\n", argv[0]);
        return 0;
    }

    const char* filename = argv[1];
    char buffer[10] = {0, };

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("파일을 열 수 없습니다: %s\n", filename);
        return 0;
    }

    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s\n", buffer);
    } else {
        printf("파일이 비어있거나 읽기 오류가 발생했습니다.\n");
    }
    fclose(fp);

    return 0;
}
