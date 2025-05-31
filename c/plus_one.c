#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    
    int* result = (int*)malloc((digitsSize + 1) * sizeof(int));
    int carry = 1; 
    for (int i = digitsSize - 1; i >= 0; i--) {
        int sum = digits[i] + carry;
        result[i + 1] = sum % 10;
        carry = sum / 10;
    }
    if (carry) {
        result[0] = 1;
        *returnSize = digitsSize + 1;
        return result;
    } else {
        
        *returnSize = digitsSize;
        return result + 1;
    }
}

int main() {
    int digits[] = {9, 9, 9};
    int digitsSize = sizeof(digits) / sizeof(digits[0]);
    int returnSize;

    int* result = plusOne(digits, digitsSize, &returnSize);

    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i != returnSize - 1) {
            printf(",");
        }
    }
    printf("]\n");

    if (returnSize == digitsSize + 1) {
        free(result);
    } else {
        free(result - 1);
    }

    return 0;
}
