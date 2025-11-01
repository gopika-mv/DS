#include <stdio.h>
#include <stdlib.h>

#define SIZE 8   // Size of the universal set (can be changed)

// Function to display a set from bit string
void displaySet(int set[], int n) {
    printf("{ ");
    for (int i = 0; i < n; i++) {
        if (set[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("}\n");
}

// Union of two sets
void unionSet(int A[], int B[], int result[], int n) {
    for (int i = 0; i < n; i++) {
        result[i] = A[i] | B[i];  // Bitwise OR
    }
}

// Intersection of two sets
void intersectionSet(int A[], int B[], int result[], int n) {
    for (int i = 0; i < n; i++) {
        result[i] = A[i] & B[i];  // Bitwise AND
    }
}

// Difference of two sets (A - B)
void differenceSet(int A[], int B[], int result[], int n) {
    for (int i = 0; i < n; i++) {
        result[i] = A[i] & (~B[i]);  // A AND (NOT B)
    }
}

int main() {
    int A[SIZE] = {0}, B[SIZE] = {0};
    int result[SIZE];
    int ch,n, element;

    printf("Universal set U = {0, 1, 2, ..., %d}\n", SIZE - 1);

    // Input Set A
    printf("Enter number of elements in Set A: ");
    scanf("%d", &n);
    printf("Enter elements of Set A: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &element);
        if (element >= 0 && element < SIZE)
            A[element] = 1;
    }

    // Input Set B
    printf("Enter number of elements in Set B: ");
    scanf("%d", &n);
    printf("Enter elements of Set B: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &element);
        if (element >= 0 && element < SIZE)
            B[element] = 1;
    }
    
    printf("\nSet A = ");
    displaySet(A, SIZE);
    printf("Set B = ");
    displaySet(B, SIZE);

    while(1) {
        printf("\n---Set Operations---\n");
        printf("1.Union\n2.Intersection\n3.Difference (A-B)\n4.Difference (B-A)\n5.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch) {
            case 1:
                // Union
                unionSet(A, B, result, SIZE);
                printf("\nA ∪ B = ");
                displaySet(result, SIZE);
                break;
            case 2:
                // Intersection
                intersectionSet(A, B, result, SIZE);
                printf("A ∩ B = ");
                displaySet(result, SIZE);
                break;
            case 3:
                // Difference A - B
                differenceSet(A, B, result, SIZE);
                printf("A - B = ");
                displaySet(result, SIZE);
                break;
            case 4: 
                // Difference B - A
                differenceSet(B, A, result, SIZE);
                printf("B - A = ");
                displaySet(result, SIZE);
                break;
            case 5:
                exit(0);
            
        }
    }
    return 0;
}