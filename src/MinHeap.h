#pragma once

#include <vector>
#include <iostream>
#include "Location.h"
using namespace std;



class MinHeap {
private:
    vector<Location> heap;
    int parent(int i) {return(i-1)/2;}
    int leftChild(int i){ return 2* i +1; }
    int rightChild(int i){ return 2*i+2;}
    void heapifyUp(int index);
    void heapifyDown(int index);


public:
    void insert(Location loc);
    Location extractMin();
    void buildHeap( vector<Location>& locs);
    vector<Location> getTopK(int k);
    int size() const {return heap.size(); }
    bool isEmpty() const {return heap.empty();}
    void printHeap();

};