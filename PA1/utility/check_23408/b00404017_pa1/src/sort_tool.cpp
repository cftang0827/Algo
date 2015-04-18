// **************************************************************************
//  File       [sort_tool.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The implementation of the SortTool Class]
//  Modify     [2015/03/02 Yu-Hao Ho]
// **************************************************************************

#include "sort_tool.h"
#include<iostream>

// Constructor
SortTool::SortTool() {}

// Insertsion sort method
void SortTool::InsertionSort(vector<int>& a)
{
    int i=0;
    int key=0;
    for(int j = 1; j<a.size() ; j++)
    {
        key = a.at(j);
        i = j - 1;
        while(i > -1 && a.at(i) > key)
        {
            a.at(i+1) = a[i];
            i = i - 1;
        }
        a.at(i+1) = key;
    }
}

// Merge sort method
void SortTool::MergeSort(vector<int>& a, int p,int r)
{
    int q;
    int iter = 0;
    if(p<r)
    {
        q = (p+r)/2;

        MergeSort(a,p,q);
        MergeSort(a,q+1,r);
        Merge(a,p,q,r);
    }

}

void SortTool::Merge(vector<int>& a, int p, int q , int r)
{
    int n1 = q-p+1;
    int n2 = r-q;

    vector<int>L(n1+1) ;
    vector<int>R(n2+1) ;



    for(int i = 0; i<n1 ; i++)
    {
        L.at(i) = a.at(p+i);

    }


    for(int i = 0; i<n2; i++)
    {

        R.at(i) = a.at(q+i+1);

    }

    L.at(n1) = 2147483647;
    R.at(n2) = 2147483647;
    int i = 0;
    int j = 0;

    for (int k = p; k <= r; k++)
    {
        if (L[i] <= R[j])
        {
            a.at(k) = L.at(i);
            i = i + 1;

        }
        else
        {
            a.at(k) = R.at(j);
            j = j + 1;

        }
    }
}




// Heap sort method
void SortTool::MaxHeapify(vector<int> &a,int i,int sz)
{

    int l = 2 * i;
    int r = 2 * i + 1;
    int largest;

    if (l <= sz && a.at(l-1) > a.at(i - 1))
    {
        largest = l;
    }
    else
    {
        largest = i;
    }
    if (r <= sz && a.at(r-1) > a.at(largest-1))
    {
        largest = r;
    }
    if(largest != i)
    {
        swap(a.at(i-1),a.at(largest-1));
        MaxHeapify(a,largest,sz);
    }
}

void SortTool::BuildMaxHeap(vector<int>& a)
{
    for(int i = (a.size())/2 ; i>=1 ; i--)
    {
        MaxHeapify(a , i , a.size());
    }
}

void SortTool::HeapSort(vector<int>& a)
{
    BuildMaxHeap(a);

    for(int i = a.size()-1 ; i>=1 ; i--)
    {
        swap(a.at(0),a.at(i));
        MaxHeapify(a,1,i);
    }
}


void SortTool::swap(int& a,int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

