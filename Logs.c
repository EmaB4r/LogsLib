#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "Logs.h"


static char*  filepath = NULL;

char* file_add_txt(char*file_name){
    int name_len=strlen(file_name);
    if(!isalpha(_LOGS_FILENAME_[0])){
        printf("invalid file name %s", file_name);
        exit(1);
    }
    if(name_len<4){
        return strcat(file_name, ".txt");
    }
    if( file_name[name_len-4]!='.' ||
        file_name[name_len-3]!='t' ||
        file_name[name_len-2]!='x' ||
        file_name[name_len-1]!='t' 
        ) return strcat(file_name, ".txt");
    return file_name;
}



char* make_filepath(){
    char* path = calloc(strlen(_LOGS_DIR_) + strlen(_LOGS_FILENAME_)+5, sizeof(char));
    path=strcat(path, _LOGS_DIR_);
    path=strcat(path, _LOGS_FILENAME_);
    path=file_add_txt(path);
    return path;
}



char* addNL(char* string){
    char * NL_string;
    NL_string=calloc(strlen(string)+1, sizeof(char));
    NL_string=strcat(NL_string, string);
    NL_string=strcat(NL_string, "\n");
    return NL_string;
}



void Log_start(){
    filepath = make_filepath();
    FILE * logs_file = fopen(filepath, "w");
    fclose(logs_file);
}


void Log(char* format, ...){
    if (filepath==NULL){
        Log_start();
    }
    FILE * logs_file = fopen(filepath, "a");
    va_list args;
    va_start(args, format);
    format=addNL(format);
    vfprintf(logs_file, format, args);
    va_end(args);
    fclose(logs_file);
}