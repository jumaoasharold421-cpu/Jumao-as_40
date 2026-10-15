#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[100];
    int grades[3];
    int absences;
    int total = 0;
    int all_at_least_85 = 1;
    int all_at_least_75 = 1;
    double average;

    printf("Enter student's name: ");
    if (fgets(name, sizeof(name), stdin) == NULL) {
        fprintf(stderr, "Error reading student's name.\n");
        return 1;
    }
    name[strcspn(name, "\n")] = '\0';

    for (int i = 0; i < 3; i++) {
        printf("Enter grade for subject %d: ", i + 1);
        if (scanf("%d", &grades[i]) != 1) {
            fprintf(stderr, "Invalid grade.\n");
            return 1;
        }
        total += grades[i];

        if (grades[i] < 85) {
            all_at_least_85 = 0;
        }
        if (grades[i] < 75) {
            all_at_least_75 = 0;
        }
    }

    printf("Enter number of absences: ");
    if (scanf("%d", &absences) != 1 || absences < 0) {
        fprintf(stderr, "Invalid number of absences.\n");
        return 1;
    }

    average = total / 3.0;
    printf("\nStudent: %s\n", name);
    printf("Average: %.2f\n", average);

    if (average >= 90.0 && all_at_least_85 && absences <= 2) {
        printf("Status: With Honors\n");
    } else if (all_at_least_75) {
        printf("Status: Passed\n");
    } else {
        printf("Status: Failed\n");
    }

    return 0;
}