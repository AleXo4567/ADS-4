// Copyright 2021 NNTU-CS
#include "alg.h"

int countPairs1(int *arr, int len, int value) {
    int result = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                ++result;
                while (j + 1 < len && arr[j] == arr[j + 1]) {
                    ++j;
                }
            }
        }
        while (i + 1 < len && arr[i] == arr[i + 1]) {
            ++i;
        }
    }
    return result;
}

int countPairs2(int *arr, int len, int value) {
    int counter = 0;
    for (int i = 0; i < len; ++i) {
        int need = value - arr[i];
        int low = i + 1;
        int high = len - 1;
        int position = -1;

        while (low <= high) {
            int middle = (low + high) / 2;
            if (arr[middle] == need) {
                position = middle;
                break;
            } else if (arr[middle] < need) {
                low = middle + 1;
            } else {
                high = middle - 1;
            }
        }

        if (position != -1) {
            ++counter;
            while (i + 1 < len && arr[i] == arr[i + 1]) {
                ++i;
            }
        }
    }
    return counter;
}

int countPairs3(int *arr, int len, int value) {
    int pairs = 0;
    int left = 0;
    int right = len - 1;

    while (left < right) {
        int current = arr[left] + arr[right];
        if (current == value) {
            ++pairs;
            int leftValue = arr[left];
            while (left < right && arr[left] == leftValue) {
                ++left;
            }
            int rightValue = arr[right];
            while (left <= right && arr[right] == rightValue) {
                --right;
            }
        } else if (current < value) {
            ++left;
        } else {
            --right;
        }
    }
    return pairs;
}
