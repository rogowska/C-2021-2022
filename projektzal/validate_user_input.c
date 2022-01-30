/*Oliwia Rogowska*/
#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "header.h"

int validate_user_input(char *input_file, char *output_file, int *borning_rule, int *surviving_rule, int *init_density, int *row_amount, int *column_amount, int *step_max, int *step_min, int *delay, int *boundary_condition, int argc, char *argv[])
{
    char result_range[30];
    int c;
    int option_index = 0;
    /*user can provide long and short options*/
    static struct option long_options[] =
        {
            {"help", no_argument, NULL, 'h'},
            {"tryout", no_argument, NULL, 't'},
            {"rows", required_argument, NULL, 'r'},
            {"columns", required_argument, NULL, 'c'},
            {"result-range", required_argument, NULL, 'z'},
            {"delay", required_argument, NULL, 'd'},
            {"init-population", required_argument, NULL, 'p'},
            {"input-file", required_argument, NULL, 'i'},
            {"output-file", required_argument, NULL, 'o'},
            {"borning-rule", required_argument, NULL, 'b'},
            {"surviving-rule", required_argument, NULL, 's'},
            {"boundary-condition", required_argument, NULL, 'w'},
            {NULL, 0, NULL, 0}};

    /*loop breaks after checking all provided arguments*/
    while ((c = getopt_long(argc, argv, "p:thr:c:z:d:i:o:b:s:w:", long_options, &option_index)) != -1)
    {
        switch (c)
        {
        case 'w':
            if ((sscanf(optarg, "%i", boundary_condition)) != 1)
            {
                printf("The value of boundary condition should be an integer.  Exiting...\n");
                return 0;
            }
            if (*boundary_condition != 1 && *boundary_condition != 2)
            {
                printf("Boundary condition value should be 1 or 2. Exiting...\n");
                return 0;
            }
            break;

        case 'i':
            if ((sscanf(optarg, "%s", input_file)) != 1)
            {
                printf("The path to file with initial data not provided. Exiting...\n");
                return 0;
            }
            break;

        case 'o':
            if ((sscanf(optarg, "%s", output_file)) != 1)
            {
                printf("The path to output file not provided. Exiting...\n");
                return 0;
            }
            break;

        case 'b':
            if ((sscanf(optarg, "%i", borning_rule)) != 1)
            {
                printf("The value of borning rule should be an integer.  Exiting...\n");
                return 0;
            }
            if (borning_rule < 0)
            {
                printf("Value of borning rule must be positive. Exiting...\n");
            }
            break;

        case 's':
            if ((sscanf(optarg, "%i", surviving_rule)) != 1)
            {
                printf("The value of surviving rule should be an integer.  Exiting...\n");
                return 0;
            }
            if (surviving_rule < 0)
            {
                printf("Value of surviving rule must be positive. Exiting...\n");
            }
            break;

        case 'p':
            if ((sscanf(optarg, "%i", init_density)) != 1)
            {
                printf("The value of initial population density should be an integer. Exiting...\n");
                return 0;
            };
            if (*init_density < 0 || *init_density > 100)
            {
                printf("Value of initial population density must be in range <0,100>. Exiting...\n");
                return 0;
            }
            break;

        case 't':
            *boundary_condition = 1;
            *delay = 1;
            *row_amount = 20;
            *column_amount = 40;
            *step_max = 100;
            *step_min = 0;
            *borning_rule = 3;
            *surviving_rule = 23;
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

        case 'z':

            if ((sscanf(optarg, "%s", result_range)) != 1)
            {
                printf("The value of steps should be a string. Exiting...\n");
                return 0;
            };
            char *step_min_str;
            char *step_max_str;
            char *endptr;

            step_min_str = strtok(result_range, ":");
            step_max_str = strtok(NULL, ":");

            if (step_min_str == NULL || step_max_str == NULL)
            {
                printf("please provide steps range as integer\n");
                return 0;
            }
            *step_min = strtod(step_min_str, &endptr);
            if (*endptr != 0)
            {
                printf("please provide starting step as an integer\n");
                return 0;
            }
            *step_max = strtod(step_max_str, &endptr);
            if (*endptr != 0)
            {
                printf("please provide ending step as an integer\n");
                return 0;
            }
            if (*step_max < 0 || *step_min < 0)
            {
                printf("step range should contain positive value\n");
                return 0;
            }
            if (*step_min > *step_max)
            {
                printf("incorrect step range format: \nthe first number (beggining) should not be greater than the second number (ending step)\n");
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
            printf("usage:\n"
                   " \tlife --columns=n --rows=n --result-range=i:j [options]\n"
                   "or\n"
                   "\tlife --input-file=path to input file --result-range=i:j [options]\n"
                   "or\n"
                   "\tlife --tryout\n\n"

                   "Symulator game of 'Life' originally based on 23/3 John Conway rule able to run with pseudo-random initial conditions or input file.\n"

                   "Mandatory arguments to long options are mandatory for short options too.\n"

                   "\tOPTIONS:\n"

                   "\t-t, --tryout\n"
                   "\t\trun demo with predifined value for arguments: -w 1 -b 3 -s 23 -c 40 -r 20 -r 0:100 -d 1\n"
                   "\t\tother arguments are ignored\n"

                   "\t-i, --input-file=path to input file\n"
                   "\t\tfile in csv format with inital board state, expected values: 1 for live cell, 0 for dead\n"
                   "\t\twhen used, following arguments are ignored: --columns, --rows, --init-population\n"

                   "\t-o, --output-file=path to output file\n"
                   "\t\tfile where simulation results will be saved in csv format\n"
                   "\t\tfollowing boards will be seperated by population and iteration counters,\n"
                   "\t\tthe simulation will still be displayed on the console as well\n"

                   "\t-c, --columns=n\n"
                   "\t\tcolumn size of board as positive value in range <1-10000>,\n"
                   "\t\targument ignored when --input-file is used\n"

                   "\t-r, --rows=n\n"
                   "\t\trows size of board as positive value in range <1-10000>,\n"
                   "\t\targument ignored when --input-file is used\n"

                   "\t-z, --result-range=i:j\n"
                   "\t\tsimulation steps range which will be displayed or saved to file\n"
                   "\t\texpected format i:j, where i<=j, both integer, for example 0:100\n"

                   "\t-w, --boundary-condition=n\n"
                   "\t\targument define behaviour of cells on board boundary, possible value 1 or 2 (default 1)\n"
                   "\t\tfor --boundary-condition set as 1 opposite edges are 'joined'\n"
                   "\t\tfor --boundary-condition set as 2 board keep boundaries\n"

                   "\t-b, --borning-rule=n\n"
                   "\t\tborning conditions for cells set as integer number where each digit define one rule,\n"
                   "\t\tfor example 14 - 1 or 4 living neighbours will generate new life (default 3)\n"

                   "\t-s, --surviving-rule=n\n"
                   "\t\tsurviving conditions for cells set as integer number where each digit define one rule,\n"
                   "\t\tfor example 23 - 2 or 3 living neighbours will keep cell alive (default 23)\n"

                   "\t-p --init-population=n\n"
                   "\t\tinitial population of living cell on board in percent (default 50),\n"
                   "\t\tlivng cell location on board is generated randomly,\n"
                   "\t\targument ignored when --input-file is used\n"

                   "\t-d, --delay=n\n"
                   "\t\tdelay in seconds between printing current board (default 1 sec)\n"

                   "\t-h, --help\n"
                   "\t\tdisplay this help and exit\n"

            );
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

    if ((*row_amount == -1) && (*column_amount == -1) && (*step_max == -1) && (strcmp(input_file, "") == 0))
    {

        printf("life usage:\n"
               " \tlife --columns=n --rows=n --result-range=i:j [options]\n"
               "or\n"
               "\tlife --input-file=path to input file --result-range=i:j [options]\n"
               "or\n"
               "\tlife --tryout\nplease check --help if needed.\n");

        return 0;
    }

    if ((*row_amount == -1 || *column_amount == -1 || *step_max == -1) && (strcmp(input_file, "") == 0))
    {
        char missing_argument[300] = "";
        if (*row_amount == -1)
        {
            strcat(missing_argument, " --rows=n (or -r n), number of rows on board\n");
        }
        if (*column_amount == -1)
        {
            strcat(missing_argument, " --columns=n (or -c n), number of columns on board\n");
        }
        if (*step_max == -1)
        {
            strcat(missing_argument, " --result-range=i:j (or -z i:j), result range\n");
        }
        else{
            if ((*row_amount == -1) && (*column_amount == -1)){
                printf("life usage:\n"
               " \tlife --columns=n --rows=n --result-range=i:j [options]\n"
               "or\n"
               "\tlife --input-file=path to input file --result-range=i:j [options]\n"
               "or\n"
               "\tlife --tryout\nplease check --help if needed.\n");
               return 0;
            }
        }

        printf("%s\n%s%s", "Required argument(s) missing:", missing_argument, "please check --help if needed.\n");

        return 0;
    }

    if ((strcmp(input_file, "") != 0) && (*step_max == -1))
    {
        printf("Result range is required for input file\nusage: life --input-file=path to input file --result-range=i:j [options]\n");
        return 0;
    }
    return 1;
}
