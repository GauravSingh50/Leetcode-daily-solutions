// 02-02-2024

static const int lookup[] = {
    12,         23,         34,     45,     56,     67,     78,     89, 
    123,        234,        345,    456,    567,    678,    789,
    1234,       2345,       3456,   4567,   5678,   6789,
    12345,      23456,      34567,  45678,  56789,
    123456,     234567,     345678, 456789,
    1234567,    2345678,    3456789,
    12345678,   23456789,
    123456789
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sequentialDigits(int low, int high, int* returnSize) {

    /*
     * Input:
     *  low,
     *  high
     */

    int *ans = malloc(sizeof(lookup));

    *returnSize = 0;

    for (int i = 0; i < (sizeof(lookup) / sizeof(int)); i++) {
        if (lookup[i] >= low && lookup[i] <= high) {
            ans[*returnSize] = lookup[i];
            *returnSize = *returnSize + 1;
        }
    }

    if (*returnSize == 0) {
        free(ans);
        ans = NULL;
    }

    /*
     * Output:
     *  *returnSize
     *  Return a sorted list of all the integers in the range [low, high] 
     *  inclusive that have sequential digits.
     */

    return ans;
}
