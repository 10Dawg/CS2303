/* simple_opt.c
* Trivial program to show the usage of getopt()
* Requires the use of option flags and arguments
*
* Command line arguments: 
* -a: requires an argument
* -b: no argument
* -X: no argument
*
* Author: Jennifer Mortensen
* Modified: 7/16/26
*/
#include <getopt.h>
#include <stdio.h> 

int main(int argc, char *argv[]){
  
	int opt;
	// loop over all command line arguments. getopt will return -1 when finished 
	while ((opt = getopt(argc, argv, "-a:bX")) != -1) {
		switch (opt){
			case 'a':
				printf("Option a was provided\n");
				printf("The option argument is %s\n", optarg);
				break;
			case 'b':
				printf("Option b was provided\n");
				break;
			case 'X':
				printf("Option X was provided\n");
				break;
			case 1:
				printf("Non-option arg:%s\n", optarg);
		}
	}
	printf("The next command line argument is\n");
	printf("%s\n", argv[optind]);

	return 0;
}