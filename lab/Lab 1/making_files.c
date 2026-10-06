#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	if (argc < 2){
		puts("Missing command line arguments");
		puts("./runLab input_file.txt");
		return 0;
	}
	FILE* f1 = fopen(argv[1], "r");
	int x;
	fscanf(f1, "%d", &x);
	fclose(f1);
	char cwd[200];
	if (getcwd(cwd, sizeof(cwd)) == NULL) {
		perror("getcwd() error");
		return 1;
	} 
	else {

		for (int i = 0; i < x; i++){
			char myStr[20] = "out_";
			char numS[5];
			sprintf(numS, "%d",i+1 );
			strcat(myStr, numS);
			strcat(myStr, ".txt");
			FILE* o1 = fopen(myStr, "w");
			if (i == 0){
				fprintf(o1, "Current directory: %s\n", cwd);
			}
			else{
				fprintf(o1, "Example text\n");
			}
			fclose(o1);
		}
	}
	return 0;
}