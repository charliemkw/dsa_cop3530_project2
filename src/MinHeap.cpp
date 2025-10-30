#include "MinHeap.h"


//cite: https://www.geeksforgeeks.org/dsa/introduction-to-min-heap-data-structure/
//cite: https://opendsa-server.cs.vt.edu/ODSA/Books/Everything/html/Heaps.html

void MinHeap::heapifyUp(int index){
    while (index > 0) {
        int parentIndex = parent(index);
        if (heap[index].distance < heap[parentIndex].distance){
            Location temp = heap[index];
            heap[index] = heap[parentIndex];
            heap[parentIndex] = temp;
            index = parentIndex;
        }
        else{
            break;
        }
    }
}
void MinHeap::heapifyDown(int index){
    int size = heap.size();
    while (leftChild(index)< size){
        int smallestIndex = index;
        int leftIndex = leftChild(index);
        int rightIndex = rightChild(index);

        if (leftIndex < size && heap[leftIndex]. distance < heap[smallestIndex].distance){
            smallestIndex = leftIndex;
        }
        if (rightIndex < size && heap[rightIndex]. distance < heap[smallestIndex].distance){
            smallestIndex = rightIndex;
        }
        if (smallestIndex != index){
            Location temp = heap[index];
            heap[index] = heap[smallestIndex];
            heap[smallestIndex] = temp;
            index = smallestIndex;
        }
        else{
            break;
        }
    }

}
void MinHeap::insert(Location loc){
    cout << "DEBUG: Inserting " << loc.distance;
    heap.push_back(loc);
    heapifyUp(heap.size()-1);
    cout << "DEBUG: Insert dome";

}
Location MinHeap::extractMin(){
    if (heap.empty()) {
        cout << "ERROR: Cannot extract from empty heap" << endl;
        Location dummy("", "", 0, "", "", 0, "", 0, "", 0, "", "", "", "", "", "", 0.0, 0.0);
        dummy.distance = -1.0;
        return dummy;
    }
    Location minItem = heap[0];
    heap[0] = heap[heap.size()-1];
    heap.pop_back();

    if (!heap.empty()){
        heapifyDown(0);

    }
    return minItem;
}

void MinHeap::buildHeap( vector<Location>& items){
    heap = items;
    for (int i = heap.size()/ 2 -1 ; i>= 0; i--){
        heapifyDown(i);
    }
}
vector<Location> MinHeap::getTopK(int k){
    vector<Location> results;
    MinHeap tempHeap;
    tempHeap.heap = this-> heap;

    for (int i = 0; i < k &&! tempHeap.isEmpty(); i++){
        results.push_back(tempHeap.extractMin());

    }
    return results;
}
