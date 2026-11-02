/*
 * CS 261: Main driver
 *
 * Name: 
 */

#include "p1-check.h"

/*
 * helper function for printing help text
 */
void usage (char **argv)
{
    printf("Usage: %s <option(s)> mini-elf-file\n", argv[0]);
    printf(" Options are:\n");
    printf("  -h      Display usage\n");
    printf("  -H      Show the Mini-ELF header\n");
}

int main (int argc, char **argv)
{
    int a = 0;
    bool print_header = false;
    while((a = getopt(argc, argv, "hH")) != -1)
    {
        switch(a)
        {
            case 'h':
                usage(argv);
                return EXIT_SUCCESS;
                break;
            case 'H':
                print_header = true;
                break;
            default:
                usage(argv);
                return EXIT_FAILURE;
                break;
        }
    }
    if(argc - 1 > optind || optind >= argc)
    {
        usage(argv);
        return EXIT_FAILURE;
    }
    elf_hdr_t e;
    FILE *f = fopen(argv[optind], "rb");
    if(f)
    {
        if(!read_header(f, &e))
        {
            printf("Failed to read file\n");
            return EXIT_FAILURE;
        }
        fclose(f);
        if(print_header)
        {
            dump_header(&e);
        }
    } else
    {
        printf("Failed to read file\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

