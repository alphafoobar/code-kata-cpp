#include "binary_search.h"

int calculateMid(int offset, int length, int remaining) {
    int mid = remaining / 2;
    return static_cast<int>(fminl(length - 1 - offset, mid));
}

int chop(int key, int array[], int offset, int length) {
    const int remaining = length - offset;

    if (remaining == 0) {
        return -1;
    }
    if (remaining == 1) {
        return array[offset] == key ? offset : -1;
    }

    int midPoint = calculateMid(offset, length, remaining);

    int point = offset + midPoint;
    if (array[point] == key) {
        return point;
    }
    if (array[point] > key) {
        return chop(key, array, offset, point);
    }
    return chop(key, array, point, length);
}

int chop(int key, int array[], int length) {
    return chop(key, array, 0, length);
}
