#include <stdio.h>
#include <string.h>
#include "conversion.h"

/*
 * Reads all unit conversions from the conversion file.
 * The file is read only once.
 */
int read_conversions(const char *FILENAME, Conversion conversions[], int max_conversions)
{
    FILE *file = fopen(FILENAME, "r");
    int count = 0;
    int expected;

    if (file == NULL) {
        return -1;
    }

    if (fscanf(file, "NUM_CONVERSIONS %d", &expected) != 1) {
        fclose(file);
        return -1;
    }

    while (count < max_conversions &&
           fscanf(file, "%lf %49s %lf %49s",
                  &conversions[count].value1,
                  conversions[count].unit1,
                  &conversions[count].value2,
                  conversions[count].unit2) == 4) {
        count++;
    }

    fclose(file);
    return count;
}

/*
 * Reads all equivalent unit names from the same-names file.
 * The file is read only once.
 */
int read_names(const char *FILENAME, UnitName names[], int max_names)
{
    FILE *file = fopen(FILENAME, "r");
    int count = 0;
    int expected;

    if (file == NULL) {
        return -1;
    }

    if (fscanf(file, "NUM_NAMES %d", &expected) != 1) {
        fclose(file);
        return -1;
    }

    while (count < max_names &&
           fscanf(file, "%49s %49s %49s",
                  names[count].singular,
                  names[count].plural,
                  names[count].abbreviation) == 3) {
        count++;
    }

    fclose(file);
    return count;
}

/*
 * Converts a plural name or abbreviation to its singular unit name.
 */
const char *FIND_SINGULAR(const char *UNIT, UnitName names[], int count)
{
    int i;

    for (i = 0; i < count; i++) {
        if (strcmp(UNIT, names[i].singular) == 0 ||
            strcmp(UNIT, names[i].plural) == 0 ||
            strcmp(UNIT, names[i].abbreviation) == 0) {
            return names[i].singular;
        }
    }

    return NULL;
}

/*
 * Finds a direct conversion in either direction.
 */
int find_conversion(const char *UNIT1, const char *UNIT2,
                    Conversion conversions[], int count, double *factor)
{
    int i;

    for (i = 0; i < count; i++) {
        if (strcmp(UNIT1, conversions[i].unit1) == 0 &&
            strcmp(UNIT2, conversions[i].unit2) == 0) {
            *factor = conversions[i].value2 / conversions[i].value1;
            return 1;
        }

        if (strcmp(UNIT1, conversions[i].unit2) == 0 &&
            strcmp(UNIT2, conversions[i].unit1) == 0) {
            *factor = conversions[i].value1 / conversions[i].value2;
            return 1;
        }
    }

    return 0;
}

/* Applies a conversion factor to a value. */
double convert_value(double value, double factor)
{
    return value * factor;
}

/*
 * Prints a result using fixed notation for normal values and
 * scientific notation for values >= 1000 or < 0.01.
 */
void print_result(double result, double input, const char *INPUT_UNIT,
                  const char *OUTPUT_UNIT)
{
    if (result >= 1000.0 || result < 0.01) {
        printf("There are %.2e %s in %.2f %s.\n",
               result, OUTPUT_UNIT, input, INPUT_UNIT);
    } else {
        printf("There are %.2f %s in %.2f %s.\n",
               result, OUTPUT_UNIT, input, INPUT_UNIT);
    }
}
