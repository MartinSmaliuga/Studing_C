#include <stdio.h>
#include <inttypes.h>

uint64_t descendingOrder(uint64_t n)
{
    char numbers[10];
    
    memset(numbers, 0, sizeof(numbers));

    while (n > 0) {
        numbers[n % 10]++;
        n /= 10;
    }

    n = 0;

    for (int j = 9; j > -1; j--) {
        while (numbers[j] > 0) {
            n *= 10;
            n += j;
            numbers[j]--;

        }

    }

    return n;
}

int main(void) {
    unsigned long long a = descendingOrder(0);
    printf("%llu\n", a);
    a = descendingOrder(1);
    printf("%llu\n", a);
    a = descendingOrder(15);
    printf("%llu\n", a);
    a = descendingOrder(1021);
    printf("%llu\n", a);
    a = descendingOrder(123456789);
    printf("%llu\n", a);
    a = descendingOrder(1779536843106043982);
    printf("%llu\n", a);

}