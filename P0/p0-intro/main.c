/*
 * CS 261: Intro project driver
 *
 * Name: John Gilbert Paul IV
 */

#include "p0-intro.h"

#define BUFF_SIZE 1024

int main (int argc, char **argv)
{
    bool hello = true;
    bool goodbye = false;
    bool fact_bool = false;
    bool cat = false;
    bool triodd = false;
    bool uniq = false;

    int f = 0;
    int triodd_num = 0;
    int a = 0;

    char *cat_fn = "";
    char *uniq_fn = "";

    while((a = getopt(argc, argv, ":gf:c:t:u:")) != -1)
    {
        hello = false;
        switch(a)
        {
            case 'g':
                goodbye = true;
                break;
            case 'f':
                fact_bool = true;
                if(optarg != NULL)
                {
                    f = (int) strtol(optarg, NULL, 10);
                }

                break;
            case 'c':
                cat = true;
                cat_fn = optarg;
                break;
            case 't':
                triodd = true;
                triodd_num = (int) strtol(optarg, NULL, 10);
                break;
            case 'u':
                uniq = true;
                uniq_fn = optarg;
                break;
            case ':':
                printf("Invalid argument.\n");
                return EXIT_SUCCESS;
            case '?':
                printf("Invalid argument.\n");
                return EXIT_SUCCESS;
        }
    }
    if(optind < argc)
    {
        printf("Invalid argument.\n");
        return EXIT_SUCCESS;
    }
    if(goodbye)
    {
        printf("Goodbye!\n");
    }
    if(fact_bool)
    {
        int fact = factorial(f);
        printf("%d\n", fact);
    }
    if(cat)
    {
        char buffer[BUFF_SIZE];
        FILE *file = fopen(cat_fn, "r");
        if(file == NULL)
        {
            printf("Invalid file.\n");
            return EXIT_FAILURE;
        }
        while (read_line(file, buffer, BUFF_SIZE))
        {
            printf("%s", buffer);
        }
        fclose(file);
    }
    if(triodd)
    {
        for(int i = 1; i <= triodd_num; i++)
        {
            if(i % 3 == 0)
            {
                if(i % 2 != 0)
                {
                    printf("triodd\n");
                    continue;
                }
                printf("tri\n");
                continue;
            } else if(i % 2 != 0)
            {
                printf("odd\n");
                continue;
            }
            printf("%d\n", i);
        }
    }
    if(uniq)
    {
        char buffer[BUFF_SIZE];
        FILE *file = fopen(uniq_fn, "r");
        if(file == NULL)
        {
            printf("Invalid file.\n");
            return EXIT_FAILURE;
        }
        char prev_line[BUFF_SIZE] = "";
        while(read_line(file, buffer, BUFF_SIZE))
        {
            if(strcmp(buffer, prev_line) != 0)
            {
                printf("%s", buffer);
            }
            snprintf(prev_line, BUFF_SIZE, "%s", buffer);
        }
        fclose(file);
    }
    if(hello)
    {
        printf("Hello, world!\n");
    }
    return EXIT_SUCCESS;
}

