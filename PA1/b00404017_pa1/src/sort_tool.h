// **************************************************************************
//  File       [sort_tool.h]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The header file for the SortTool Class]
//  Modify     [2015/03/02 Yu-Hao Ho]
// **************************************************************************

#ifndef _SORT_TOOL_H
#define _SORT_TOOL_H

#include<vector>
using namespace std;

class SortTool {
    public:
        
                    SortTool(); // constructor
        void        InsertionSort(vector<int>&); // sort data using insertion sort
        void        MergeSort(vector<int>&, int, int); // sort data using merge sort
        void        HeapSort(vector<int>&); // sort data using heap sort
    private:

        void        Merge(vector<int>&, int, int, int); // merge two sorted subvector
        void        MaxHeapify(vector<int>&, int, int); // make tree with given root be a max-heap 
                                                    //if both right and left sub-tree are max-heap
        void        BuildMaxHeap(vector<int>&); // make data become a max-heap
        void        swap(int& ,int&);
        
};

#endif
