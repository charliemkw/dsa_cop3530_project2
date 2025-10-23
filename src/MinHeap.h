#pragma once

#include <vector>
#include <iostream>
using namespace std;

struct Item {
    double distance;
};

class MinHeap {
private:
    vector<Item> heap;
    int parent(int i) {return(i-1)/2;}
    int leftChild(int i){ return 2* i +1; }
    int rightChild(int i){ return 2*i+2;}
    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    void insert(Item item);
    Item extractMin();
    void buildHeap( vector<Item>& items);
    vector<Item> getTopK(int k);
    int size() const {return heap.size(); }
    bool isEmpty() const {return heap.empty();}
    void printHeap();

};