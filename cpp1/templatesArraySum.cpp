#include <iostream>

template<class summable>
summable get_sum(summable data[], int size) {
    summable sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum;
}

/* int get_sum(int data[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum;
} */

int main() {
    double nums[] = {1.1, 2.0, 3.0, 4.0, 5.0};
    int size = sizeof(nums) / sizeof(int);
    double sum = get_sum(nums, size);

    std::cout << sum;
    return 0;
}
