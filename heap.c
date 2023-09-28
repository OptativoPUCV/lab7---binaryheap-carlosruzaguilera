#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


// Declaraciones de funciones
void heapify_up(Heap* pq, int index);
//void heapify_down(Heap* pq, int index);

void* heap_top(Heap* pq) {
    if (pq->size == 0) return NULL;
    return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int p) {
    if (pq->size == pq->capac) {
        pq->capac = pq->capac * 2 + 1;
        pq->heapArray = realloc(pq->heapArray, sizeof(heapElem) * pq->capac);
    }
    pq->heapArray[pq->size].data = data;
    pq->heapArray[pq->size].priority = p;
    pq->size++;
    heapify_up(pq, pq->size - 1);
}




Heap* createHeap() {
    Heap* newHeap = (Heap*)malloc(sizeof(Heap));
    newHeap->size = 0;
    newHeap->capac = 3;
    newHeap->heapArray = (heapElem*)malloc(sizeof(heapElem) * newHeap->capac);
    return newHeap;
}



void heapify_up(Heap* pq, int index) {
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (pq->heapArray[index].priority > pq->heapArray[parentIndex].priority) {
            heapElem temp = pq->heapArray[index];
            pq->heapArray[index] = pq->heapArray[parentIndex];
            pq->heapArray[parentIndex] = temp;
            index = parentIndex;
        } else {
            break;
        }
    }
}

