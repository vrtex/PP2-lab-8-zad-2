#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Task author: Anna Fabijañska
//Program author: Jakub Czaja

/*
program counts how many times given words appears in given file
won't count words starting or ending with (, ", or other special symbols          <- FIX
    (if second argument is "int" program won't count in int in main declaration in this file as it starts with ( )
both arguments provided as main() function arguments
included exceptions handling
*/

/*
expects 2 arguments:
    1: path to file
    2: word to count
returns 0 if number of provided arguments isn't equal to 2
returns -1 if file can't be opened (wrong file path or file doesn't exist)
*/

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        exit(0);
    }
    const int tab_size = sizeof(argv[1])/sizeof(char);
    char *tab = calloc(tab_size, sizeof(char));

    FILE *f;
    if((f = fopen(argv[1], "r")) == NULL)
    {
        exit(-1);
    }
    int a = 0;
    while(fscanf(f, "%s", tab) != EOF)
    {
        if(*tab == '(')     //doesn't work ¯\_(ツ)_/¯
        {
            tab = strcpy(tab, tab + 1);
        }
        if(strcmp(argv[2], tab) == 0)
        {
            ++a;
        }
    }
    printf("%d", a);
    fclose(f);
    return a;
}
