#include "OnegMain.h"

int main() {

    StructPtr struct_p = {};

    struct_p.name_file_input = "Oneg.txt";
    struct_p.name_file_output = "OnegResult.txt";

    ReadStrFile(&struct_p);
    ConvertBufToPtrArray(&struct_p);

    HowSort how_sort = (HowSort) 0;

    C(LBLUE);
    printf("Enter 0 if you wand to sort by left side, or 1 if you want to sort by right side:\n");
    C(WHITE);

    scanf("%d", &how_sort);

    StrSort(struct_p.ptr_str, struct_p.num_str, how_sort);

    WriteStrFile(&struct_p);

    CleanStructPtrBuf(&struct_p);

    return 0;
}
