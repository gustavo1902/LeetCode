int searchInsert(int* nums, int numsSize, int target) {
    int inicio = 0, fim = numsSize - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (nums[meio] == target) {
            return meio; 
        } else if (nums[meio] < target) {
            inicio = meio + 1; 
        } else {
            fim = meio - 1; 
        }
    }
    return inicio;
}
