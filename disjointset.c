#include <stdio.h>

#define MAX 100

int parent[MAX];   
int rankArr[MAX]; 
void makeSet(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;    
        rankArr[i] = 0; 
    }
}
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}
void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX == rootY) {
        printf("Elements %d and %d are already in the same set.\n", x, y);
        return;
    }

    if (rankArr[rootX] < rankArr[rootY]) {
        parent[rootX] = rootY;
    } else if (rankArr[rootX] > rankArr[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootY] = rootX;
        rankArr[rootX]++;
    }

    printf("Union of %d and %d done.\n", x, y);
}
void displayParents(int n) {
    printf("Element : Parent\n");
    for (int i = 1; i <= n; i++) {
        printf("%d : %d\n", i, find(i));
    }
}

int main() {
    int n, choice, x, y;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    makeSet(n);

    while (1) {
        printf("\nDisjoint Set Operations:\n");
        printf("1. Union\n");
        printf("2. Find\n");
        printf("3. Display Element:Parent\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two elements to union: ");
                scanf("%d %d", &x, &y);
                unionSets(x, y);
                break;

            case 2:
                printf("Enter element to find its set representative: ");
                scanf("%d", &x);
                printf("Representative of %d is %d\n", x, find(x));
                break;

            case 3:
                displayParents(n);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
