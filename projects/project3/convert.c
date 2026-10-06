#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "conversion.h"

static void usage(const char *PROGRAM)
{
    printf("Usage:\n");
    printf("  %s unit.txt same.txt\n", PROGRAM);
    printf("  %s -c unit.txt -s same.txt\n", PROGRAM);
    printf("  %s -s same.txt -c unit.txt\n", PROGRAM);
    printf("  %s -covert unit.txt -same same.txt\n", PROGRAM);
    printf("  %s --same same.txt --convert unit.txt\n", PROGRAM);
}

static int parse_arguments(int argc, char *argv[],
                           char **conversion_file, char **names_file)
{
    int option;
    int option_index = 0;
    int i;

    static struct option long_options[] = {
        {"convert", required_argument, 0, 'c'},
        {"same", required_argument, 0, 's'},
        {0, 0, 0, 0}
    };

    *conversion_file = NULL;
    *names_file = NULL;

    /* No-flag form: ./convert unit.txt same.txt */
    if (argc == 3 && argv[1][0] != '-') {
        *conversion_file = argv[1];
        *names_file = argv[2];
        return 1;
    }

    /*
     * The assignment also specifies the exact aliases -convert and -same.
     * Check those before getopt(), because getopt() interprets a single
     * dash followed by several letters as a group of short options.
     */
    for (i = 1; i < argc; i++) {
        if ((strcmp(argv[i], "-convert") == 0) && i + 1 < argc) {
            *conversion_file = argv[++i];
        } else if ((strcmp(argv[i], "-same") == 0) && i + 1 < argc) {
            *names_file = argv[++i];
        }
    }

    if (*conversion_file != NULL && *names_file != NULL) {
        return 1;
    }

    /* Standard short flags and GNU long flags. */
    optind = 1;

    while ((option = getopt_long(argc, argv, "c:s:",
                                 long_options, &option_index)) != -1) {
        switch (option) {
            case 'c':
                *conversion_file = optarg;
                break;

            case 's':
                *names_file = optarg;
                break;

            default:
                return 0;
        }
    }

    return (*conversion_file != NULL && *names_file != NULL);
}

int main(int argc, char *argv[])
{
    Conversion conversions[MAX_CONVERSIONS];
    UnitName names[MAX_NAMES];

    char *conversion_file;
    char *names_file;

    int conversion_count;
    int name_count;

    double input_value;
    double factor;
    double result;

    char input_unit[MAX_UNIT_LENGTH];
    char desired_unit[MAX_UNIT_LENGTH];

    const char *INPUT_SINGULAR;
    const char *DESIRED_SINGULAR;

    if (!parse_arguments(argc, argv, &conversion_file, &names_file)) {
        usage(argv[0]);
        return 1;
    }

    conversion_count = read_conversions(
        conversion_file, conversions, MAX_CONVERSIONS);

    if (conversion_count < 0) {
        fprintf(stderr, "Could not read conversion file.\n");
        return 1;
    }

    name_count = read_names(names_file, names, MAX_NAMES);

    if (name_count < 0) {
        fprintf(stderr, "Could not read same-names file.\n");
        return 1;
    }

    printf("Enter your desired conversion (-1 to end)\n");

    while (input_value != -1) {

        printf("Enter the first value: ");

        if (scanf("%lf", &input_value) != 1) {
            fprintf(stderr, "Invalid value.\n");
            return 1;
        }

        if (input_value == -1) {
            return 0;
        }

        if (scanf("%49s", input_unit) != 1) {
            fprintf(stderr, "Invalid unit.\n");
            return 1;
        }

        printf("Enter the desired units: ");

        if (scanf("%49s", desired_unit) != 1) {
            fprintf(stderr, "Invalid unit.\n");
            return 1;
        }

        INPUT_SINGULAR = FIND_SINGULAR(input_unit, names, name_count);
        DESIRED_SINGULAR = FIND_SINGULAR(desired_unit, names, name_count);

        if (INPUT_SINGULAR == NULL || DESIRED_SINGULAR == NULL ||
            !find_conversion(INPUT_SINGULAR, DESIRED_SINGULAR,
                             conversions, conversion_count, &factor)) {
            printf("This is not a valid conversion.\n");
        }

        else{
            result = convert_value(input_value, factor);

            print_result(result, input_value, input_unit, desired_unit);
            puts("");
        }
    }

    return 0;
}
