//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
            data[size] = idx;           // Place index at the end
            upheap(size, weightArr);    // Fix the heap by moving up
            size++;                     // Increment heap size
        }



    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        if (size == 0) return -1;

        int minIdx = data[0];             // Save  smallest index
        data[0] = data[size - 1];         // Replace root
        size--;                           // Reduce the size of heap
        downheap(0, weightArr);

        return minIdx;                   // Return index of node that has the smallest weight
        }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        while (pos > 0) {
            int parent = (pos - 1) / 2;
            if (weightArr[data[pos]] < weightArr[data[parent]]) {
                swap(data[pos], data[parent]);
                pos = parent;
            } else {
                break;
            }
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        while (true) {
            int left = 2 * pos + 1;
            int right = 2 * pos + 2;
            int smallest = pos;

            if (left < size && weightArr[data[left]] < weightArr[data[smallest]])
                smallest = left;

            if (right < size && weightArr[data[right]] < weightArr[data[smallest]])
                smallest = right;

            if (smallest == pos) break;

            swap(data[pos], data[smallest]);
            pos = smallest;
        }
    }
};

#endif