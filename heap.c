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


void* heap_top(Heap* pq) {
    if (pq->size == 0) return NULL;
    return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){
  if (pq->size == pq->capac) {
        pq->capac = pq->capac * 2 + 1;
        pq->heapArray = realloc(pq->heapArray, sizeof(heapElem) * pq->caac);
    }
  
}


void heap_pop(Heap* pq) {
    if (pq->size == 0) return;
    pq->size--;
    pq->heapArray[0] = pq->heapArray[pq->size];
    // Aquí debe ajustar el montículo hacia abajo.
}

Heap* createHeap() {
    Heap* newHeap = (Heap*)malloc(sizeof(Heap));
    newHeap->size = 0;
    newHeap->capac = 3;
    newHeap->heapArray = (heapElem*)malloc(sizeof(heapElem) * newHeap->capac);
    return newHeap;
}
