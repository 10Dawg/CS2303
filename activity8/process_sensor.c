#include <stdio.h>
#include <stdint.h>
#include "sensor_functions.h"

int main() {
    FILE *file = fopen("input_sensor.txt", "r");
    if (!file) {
        printf("Error opening file.\n");
        return 1;
    }

    int value; 

    int count_error = 0;
    int count_wet = 0;

    int sum_temp = 0;
	int num_values = 0;

	int status_mask = 1;
	
    while (fscanf(file, "%d", &value) == 1) {
        // Extract fields using bitwise operations

        // Bit 0: status
        int status = value & status_mask; // 1 = normal, 0 = error
        if (!status) {
            count_error++;
        }
		else{
			// extract the temperature
			int temp = extract_temp(value);
			
			int is_wet = extract_wet(value);
			
			// Accumulate
			sum_temp += temp;
			num_values++;
			if (is_wet){
				count_wet++;
			}
		}
    }

    fclose(file);
	
    // Compute average
	float avg_temp = (sum_temp)/(float)num_values;
	
    // Print summary
    printf("The average temperature was %.2f C.\n", avg_temp);
    printf("The sensor was down for %d readings.\n", count_error);
	printf("The sensor was wet for %d readings.\n", count_wet);

    return 0;
}
