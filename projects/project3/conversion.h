#ifndef CONVERSION_H
#define CONVERSION_H

#define MAX_CONVERSIONS 100
#define MAX_NAMES 100
#define MAX_UNIT_LENGTH 50

typedef struct {
    double value1;
    char unit1[MAX_UNIT_LENGTH];
    double value2;
    char unit2[MAX_UNIT_LENGTH];
} Conversion;

typedef struct {
    char singular[MAX_UNIT_LENGTH];
    char plural[MAX_UNIT_LENGTH];
    char abbreviation[MAX_UNIT_LENGTH];
} UnitName;

int read_conversions(const char *FILENAME, Conversion conversions[], int max_conversions);
int read_names(const char *FILENAME, UnitName names[], int max_names);
const char *FIND_SINGULAR(const char *UNIT, UnitName names[], int count);
int find_conversion(const char *UNIT1, const char *UNIT2,
                    Conversion conversions[], int count, double *factor);
double convert_value(double value, double factor);
void print_result(double result, double input, const char *INPUT_UNIT,
                  const char *OUTPUT_UNIT);

#endif
