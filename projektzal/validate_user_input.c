/*Oliwia Rogowska*/
#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>
#include "header.h"

int validate_user_input(int *init_density, int *row_amount, int *column_amount, int *step_amount, int *delay, int argc, char *argv[])
{
    int c;
    int option_index = 0;
    /*user can provide long and short options*/
    static struct option long_options[] =
        {
            {"help", no_argument, NULL, 'h'},
            {"tryout", no_argument, NULL, 't'},
            {"columns", required_argument, NULL, 'c'},
            {"rows", required_argument, NULL, 'r'},
            {"steps", required_argument, NULL, 's'},
            {"delay", required_argument, NULL, 'd'},
            {"init", required_argument, NULL, 'i'},
            {NULL, 0, NULL, 0}};

    /*loop breaks after checking all provided arguments*/
    while ((c = getopt_long(argc, argv, "i:thc:r:s:d:", long_options, &option_index)) != -1)
    {
        switch (c)
        {
        case 'i':
                        if ((sscanf(optarg, "%i", init_density)) != 1)
            {
                printf("The value of initial density should be an integer. Exiting...\n");
                return 0;
            };
            if (*init_density < 0 || *init_density > 100)
            {
                printf("Value of initial density must be in range <0,100>. Exiting...\n");
                return 0;
            }
            break;

        case 't':
            *delay = 1;
            *row_amount = 20;
            *column_amount = 40;
            *step_amount = 100;
            return 1;

        case 'c':
            if ((sscanf(optarg, "%i", column_amount)) != 1)
            {
                printf("The value of columns should be an integer. Exiting...\n");
                return 0;
            };
            if (*column_amount < 1)
            {
                printf("Value of columns must be positive. Exiting...\n");
                return 0;
            }
            /*the selected limit prevents waiting too long for the display of the future board*/
            if (*column_amount > BOARD_SIDE_MAX)
            {
                printf("Value of columns must be under 10000. Exiting...\n");
                return 0;
            }
            break;

        case 'r':
            if ((sscanf(optarg, "%i", row_amount)) != 1)
            {
                printf("The value of row should be an integer. Exiting...\n");
                return 0;
            };
            if (*row_amount < 1)
            {
                printf("Value or row must be positive. Exiting...\n");
                return 0;
            }
            /*the selected limit prevents waiting too long for the display of the future board*/
            if (*row_amount > BOARD_SIDE_MAX)
            {
                printf("Value of row must be under 10000. Exiting...\n");
                return 0;
            }
            break;

        case 's':
            if ((sscanf(optarg, "%i", step_amount)) != 1)
            {
                printf("The value of steps should be an integer. Exiting...\n");
                return 0;
            };
            if (*step_amount < 1)
            {
                printf("Value of steps must be positive. Exiting...\n");
                return 0;
            }
            break;

        case 'd':
            if ((sscanf(optarg, "%i", delay)) != 1)
            {
                printf("The value of delay should be an integer. Exiting...\n");
                return 0;
            };
            if (*delay < 0)
            {
                printf("Value of delay must be greater than zero. Exiting...\n");
                return 0;
            }
            break;

        case 'h':
            printf("usage:  life --columns --rows --steps [--delay]\n"
                   "or\n"
                   "\tlife --tryout\n"

                   "Symulator game of 'Life' based on 23/3 John Conway rule with pseudo-random initial conditions.\n"

                   "Mandatory arguments to long options are mandatory for short options too.\n"

                   "\t-c, --columns=n\n"
                   "\t\tcolumn size of board as positive value in range <1-10000>\n"

                   "\t-d, --delay=n\n"
                   "\t\tdelay in seconds between printing current board (default 1 sec)\n"

                   "\t-h, --help\n"
                   "\t\tdisplay this help and exit\n"

                   "\t-r, --rows=n\n"
                   "\t\trows size of board as positive value in range <1-10000>\n"

                   "\t-s, --steps=n\n"
                   "\t\tnumber of simulation steps, positive natural number\n"

                   "\t-i --init=n\n"
                   "\t\tinitial density of living cell on board in percent (default 50),\n"
                   "\t\tlivng cell location on board is generated randomly\n"

                   "\t-t, --tryout\n"
                   "\t\trun demo with predifined value for arguments: -c 40 -r 20 -s 100 -d 1\n"
                   "\t\tother arguments are ignored\n");
            return 0;

        case '?':
            printf("Unknown option %c\n", optopt);
            return 0;

        case ':':
            printf("Missing option for %c\n", optopt);
            return 0;

        default:
            printf("?? getopt returned character code 0%o ??\n", c);
            return 0;
        }
    }

    if (*row_amount == -1 || *column_amount == -1 || *step_amount == -1)
    {
        printf("Required arguments are missing, please check --help if needed.\n");
        return 0;
    }
    return 1;
}
