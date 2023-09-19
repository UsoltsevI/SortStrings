#include "ReadStrings.h"

void ReadStrFile(StructPtr *struct_p) {

    FILE *ReadableFile = fopen(struct_p->name_file_input, "r");

    C(YELLOW);
    printf("The file input process has started...\n");
    C(WHITE);

    ReadStrFromFileToBuf(struct_p, ReadableFile);

    fclose(ReadableFile);

    C(GREEN);
    printf("The file has successfully read!\n");
    C(WHITE);
}

int ReadStrFromFileToBuf(StructPtr *struct_p, FILE *ReadableFile) {

    struct_p->num_str = 1;
    struct_p->num_elem = 256;
    struct_p->buf = (char *) calloc(struct_p->num_elem + 1, sizeof(char));

    if (struct_p->buf == NULL)
        return -1;

    int check = 0;
    size_t elem_num = 0;

    while (check != EOF) {

        struct_p->buf[elem_num] = (char) check;

        if (check == '\n')
            (struct_p->num_str)++;

        check = fgetc(ReadableFile);

        elem_num++;


        if (elem_num >= struct_p->num_elem - 1) {

            struct_p->num_elem = struct_p->num_elem * 2;
            struct_p->buf = (char *) realloc(struct_p->buf, (struct_p->num_elem + 1) * sizeof(char));
        }

        if (elem_num > struct_p->num_elem)
            return -1;
    }

    return 0;
}

void ConvertBufToPtrArray(StructPtr *struct_p) {

    struct_p->ptr_str = (char **) calloc(struct_p->num_str + 1, sizeof(char *));

    struct_p->ptr_str[0] = (char *) (struct_p->buf + 1);

    size_t str_num = 1;
    size_t elem_num = 0;
    size_t len_str = 0;

    while (elem_num < struct_p->num_elem) {

        if (struct_p->buf[elem_num] == '\n') {

            struct_p->buf[elem_num] = '\0';

            if (len_str > 5) {

                if (elem_num == struct_p->num_elem)
                    struct_p->buf[elem_num + 1] = '\0';

                struct_p->ptr_str[str_num] = (char *) (struct_p->buf + elem_num + 1);
                str_num++;
            }

            len_str = 0;
        }

        elem_num++;
        len_str++;
    }

    struct_p->num_str = str_num;
    free(struct_p->ptr_str[str_num + 1]);
}

void WriteStrFile(StructPtr *struct_p) {

    C(YELLOW);
    printf("The file output process has started...\n");
    C(WHITE);

    FILE *OutputFile;
    OutputFile = fopen(struct_p->name_file_output, "w");

    for (size_t i = 0; i < struct_p->num_str - 1; i++) //add it to FixArray
        fprintf(OutputFile, "%s\n", struct_p->ptr_str[i]);

    fclose(OutputFile);

    C(GREEN);
    printf("The data the data was successfully output to the file named %s\n", struct_p->name_file_output);
    C(WHITE);
}

void CleanStructPtrBuf(StructPtr *struct_p) {

    for (size_t i = 0; i < struct_p->num_str; i++)
        free(struct_p->ptr_str[i]);

    free(struct_p->ptr_str);
    free(&struct_p->ptr_str);

    struct_p->buf = NULL;
    struct_p->num_elem = 0;
    struct_p->num_str = 0;
    struct_p->ptr_str = NULL;
}

