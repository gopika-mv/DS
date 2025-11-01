#include <stdio.h>

int main() {
    int a[10], b[10], c[20];
    int n1, n2, i, j, k, temp;
    printf("Enter size of first array: ");
    scanf("%d", &n1);
    printf("Enter elements: ");
    for(i=0; i<n1; i++)
        scanf("%d", &a[i]);
    printf("Enter size of second array: ");
    scanf("%d", &n2);
    printf("Enter elements: ");
    for(i=0; i<n2; i++)
        scanf("%d", &b[i]);
    for(i=0; i<n1-1; i++) {
        for(j=0; j<n1-i-1; j++) {
            if(a[j] > a[j+1]) {
                temp=a[j]; a[j]=a[j+1]; a[j+1]=temp;
            }
        }
    }
    for(i=0; i<n2-1; i++) {
        for(j=0; j<n2-i-1; j++) {
            if(b[j] > b[j+1]) {
                temp=b[j]; b[j]=b[j+1]; b[j+1]=temp;
            }
        }
    }
    i=0; j=0; k=0;
    while(i<n1 && j<n2) {
        if(a[i] < b[j]) c[k++] = a[i++];
        else c[k++] = b[j++];
    }
    while(i<n1) c[k++] = a[i++];
    while(j<n2) c[k++] = b[j++];
    printf("Merged Sorted Array: ");
    for(i=0; i<k; i++)
        printf("%d ", c[i]);

    return 0;
}
