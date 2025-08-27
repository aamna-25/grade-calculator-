// Aamna G
//Simple Grade Calculator!
// February 19th 2024 (Final Version)
// A university student's go-to platform.
// Terminal based

#include <stdio.h>
#include <string.h>


// A macro constant that defines all of the letter grades at most Universities
#define LETTER_GRADES 12

typedef struct {
    /*
     This is a structure that groups the information of the grading scale per
     different classes.
     */
    char gradeName[3]; // A+, A, A-
    double minPercentage; // What is the minimum required to achieve this letter grade in percentage.
    double gpa;
} GradeScale;

char* getLetterGrade (double average, GradeScale scale[], int count) {
    /*
     This is a function that calculates which letter grade the average
     will fall into.
     */
    for (int i = 0; i < count; i++) {
        if (average >= scale[i].minPercentage) {
            return scale[i].gradeName;
        }
    }
    return "F";
}


int main() {
    int numGrades;
    
    // Allow user to enter the grading information as per the school the go to
    
    do {
        printf("Please enter the number of grade categories (e.g. 3 for A+, A, A-): ");
        scanf("%d", &numGrades);

        if (numGrades <= 0 || numGrades > LETTER_GRADES) { // Error checking
            printf("Invalid number of grade categories. Please try again.\n");
        }
    } while (numGrades <= 0 || numGrades > LETTER_GRADES);

    GradeScale scale[LETTER_GRADES]; // Stores information about the grading scale
    
    printf("\nDefine the grading scale for your class below from highest to lowest\n");
    for (int i = 0; i < numGrades; i++ ) {
        printf("Enter the grade name (e.g. A): ");
        scanf("%s", scale[i].gradeName);
        
        printf("Enter minimum percentage for %s: ", scale[i].gradeName);
        scanf("%lf", &scale[i].minPercentage);
    }
    
    int numClasses;
    do {
            printf("Enter the number of classes: ");
            scanf("%d", &numClasses);

            if (numClasses <= 0) {
                printf("Invalid number of classes. Must be at least 1.\n");
            }
        } while (numClasses <= 0);

    
    double classAverages[numClasses];
    // A two-dimension array that holds the class number and the grade that corresponds to that class
    char classGrades[numClasses][3];
    
    
    for (int c = 0; c < numClasses; c++) {
        printf("\nClass %d ~ \n", c+1);
        
        // How many assignments/exams there are
        int n;
        do {
            printf("Enter the number of grade components (e.g. assignments, exams): ");
            scanf("%d", &n);

            if (n <= 0) {
                printf("Invalid number of components. Please try again. \n");
            }
        } while (n <= 0);
        
        double weightedSum = 0.0, totalWeight = 0.0;
        for (int i = 0; i < n; i++) {
            double grade, weight;
            printf("\nComponent %d: \n", i+1);
            printf("Enter grade (0-100%%): ");
            scanf("%lf", &grade);
            printf("Enter weight (e.g. 20 for a 20%% weight): ");
            scanf("%lf", &weight);
            totalWeight += weight; // Sum the total weight
            weightedSum += grade * weight; // Grade multiplied by the weight
            
        }
        
        double weightedAvg = weightedSum / totalWeight; // The grade in percentage
        char* letter = getLetterGrade(weightedAvg, scale, numGrades); // What that grade is in terms of the scale
        
        classAverages[c] = weightedAvg; // For the summary report hold the grade in an array.
        strcpy(classGrades[c], letter); // Copy the letter grade into the class number

        printf("\nClass %d Average: %.2f%%\n", c + 1, weightedAvg);
        printf("Class %d Final Letter Grade: %s\n", c + 1, letter);
        
    }
    
    printf("\nSummary of All Classes ~ \n");
        for (int c = 0; c < numClasses; c++) {
            printf("Class %d: %.2f%% (%s)\n", c + 1, classAverages[c], classGrades[c]);
        }
    
   
}


