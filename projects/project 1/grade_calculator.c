#include <stdio.h>
#include <stdbool.h>

int ConvertScore(float score);
void printSummary(float cmpPoints, int projectVals[3]);
float subtractMinZero(float a, float b);


    
int main(void){
    float total, projectTotal, projectScore, cmp;
    int projectVals[3] = {0, 0, 0}; //Converted scores, {ME, RN, NG}
    bool validInput = false; //Is the most recent input valid?

    // Welcome message and instructions
    puts("Welcome to the grade calculator.");
    printf("Enter your total course points (as reported on Canvas)\nand your score on each project and I'll calculate your grade.\n");
    puts("How many total points have you earned?");

    // Input validation for total points
    while (!validInput) {
        if (scanf("%f", &total) != 1){
            printf("Error reading score.\nTry again\n");
        }
        if(total < 0 || total > 1000) {
            printf("Points range from 0 to 1000.\nTry again.\n");
            while (getchar() != '\n'); // Clear the input buffer
        } else {
            validInput = true;
        }
    }

    // Input validation for project scores
    puts("Enter your project scores.");
    for(int i = 1; i < 6; i++){
        printf("P%d: ", i);
        validInput = false;
        while (!validInput) {
            if (scanf("%f", &projectScore) != 1) {
                printf("Error reading score.\nTry again\n");
                while (getchar() != '\n'); // Clear the input buffer
            } else if (projectScore < 0 || projectScore > 100) {
                printf("Points range from 0 to 100.\nTry again.\n");
                while (getchar() != '\n'); // Clear the input buffer
            } else {
                validInput = true;
            }
        }
        projectTotal += projectScore;
        // Convert the project score and update the corresponding count
        switch(ConvertScore(projectScore)){
            case 0:
                projectVals[0]++;
                projectVals[1]++;
                break;
            case 1:
                projectVals[1]++;
                break;
            case 2:
                projectVals[2]++;
                break;
        }
    }
    // Calculate CMP
    cmp = subtractMinZero(total, projectTotal);

    puts("\nSummary");
    printf("CMP points: %.2f\n", cmp);
    printf("Projects at ME: %d\n", projectVals[0]);
    printf("Projects at RN: %d\n\n", projectVals[1]);

    printSummary(cmp, projectVals);
}

int ConvertScore(float score){
    if(score >= 85){
        return 0; // ME
    } else if(score >= 35){
        return 1; // RN
    } else {
        return 2; // NG
    }
}

float subtractMinZero(float a, float b){
    float result = a - b;
    return (result < 0) ? 0 : result;
}

void printSummary(float cmpPoints, int projectVals[3]){
    if(cmpPoints >= 450 && projectVals[0] >= 4 && projectVals[1] >= 5){
        printf("You have earned an A.\n");
    } else if(cmpPoints >= 400 && projectVals[0] >= 3 && projectVals[1] >= 4){
        printf("You have earned a B.\n");
    } else if(cmpPoints >= 350 && projectVals[0] >= 2 && projectVals[1] >= 4){
        printf("You have earned a C.\n");
    } else {
        printf("You have not earned enough points to assign a grade.\nThis is expected at the start of the term.\n");
    }
    printf("\n");

    puts("The table below lists the additional work needed to earn each letter grade.");
    puts("Note: ME projects also count as RN projects.");
    printf("\n");
    printf("Grade  CMP points    ME    RN\n");
    printf("%5s  %10.2f  %4.0f  %4.0f\n", "A", subtractMinZero(450, cmpPoints), subtractMinZero(4, projectVals[0]), subtractMinZero(5, projectVals[1]));
    printf("%5s  %10.2f  %4.0f  %4.0f\n", "B", subtractMinZero(400, cmpPoints), subtractMinZero(3, projectVals[0]), subtractMinZero(4, projectVals[1]));
    printf("%5s  %10.2f  %4.0f  %4.0f\n", "C", subtractMinZero(350, cmpPoints), subtractMinZero(2, projectVals[0]), subtractMinZero(4, projectVals[1]));
}