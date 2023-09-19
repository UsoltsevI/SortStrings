#ifndef ONEGREAD_H_INCLUDED
#define ONEGREAD_H_INCLUDED

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "Color.h"

struct StructPtr {
    size_t num_elem;
    char *buf;
    char * *ptr_str;
    size_t num_str;
    const char *name_file_input;
    const char *name_file_output;
};

void ReadStrFile(StructPtr *struct_p);
int ReadStrFromFileToBuf(StructPtr *struct_p, FILE *ReadableFile);
void ConvertBufToPtrArray(StructPtr *struct_p);
void WriteStrFile(StructPtr *struct_p);
void CleanStructPtrBuf(StructPtr *struct_p);

#endif // ONEGREAD_H_INCLUDED
