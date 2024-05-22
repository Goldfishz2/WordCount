#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_LINE_LENGTH 1024

int count_characters(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        count++;
    }

    fclose(file);
    return count;
}

int count_words(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int count = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        char *token = strtok(line, " ,");
        while (token != NULL) {
            count++;
            token = strtok(NULL, " ,");
        }
    }

    fclose(file);
    return count;
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    char parameter[3];

    printf("��������Ʋ�����-c �� -w����");
    scanf("%s", parameter);

    printf("�������ļ���ַ��");
    scanf("%s", filename);

    if (strcmp(parameter, "-c") == 0) {
        int count = count_characters(filename);
        printf("�ַ�����%d\n", count);
    } else if (strcmp(parameter, "-w") == 0) {
        int count = count_words(filename);
        printf("��������%d\n", count);
    } else {
        printf("Invalid parameter.\n");
    }

    return 0;
}

