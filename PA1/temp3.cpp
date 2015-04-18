// vector::begin/end
#include <iostream>
#include <vector>
#include <cmath>
#define N 100

using namespace std;

void InserSort(vector<int>& );
void Merge(vector<int>&, int ,int ,int );
void MergeSort(vector<int>& , int ,int );
void HeapSort(vector<int>& );
void MaxHeapify(vector<int>& ,int );
void BuildMaxHeap(vector<int>& );
void swap(int& ,int& );

int main ()
{
    int* temp =new int[N];
    int* temp1 =new int[N];
    int* temp2 =new int[N];
    for(int i = 0; i<N; i++)
    {
        temp[i] = rand()%N;
        temp1[i] = temp[i];
        temp2[i] = temp[i];
    }
    vector<int> myvector;
    vector<int> myvector1;
    vector<int> myvector2;
    for(int i =0; i<N ; i++)
    {
        myvector.push_back(temp[i]);
        myvector1.push_back(temp1[i]);
        myvector2.push_back(temp2[i]);
    }
    cout<<"before sort by :";
    cout<<"myvector size:"<<myvector.size()<<endl;
    for(int i=0; i<myvector.size(); i++)
    {
        cout<<myvector.at(i)<<" ";
    }
    cout<<endl;
    //cout<<"a[9]"<<myvector[9];
    MergeSort(myvector,0,myvector.size()-1);
    InserSort(myvector1);
    HeapSort(myvector2);
    cout<<"after sort by MergeSort:";
    cout<<endl;
    for(int i=0; i<myvector.size(); i++)
    {
        cout<<myvector.at(i)<<" ";
    }
    cout<<endl;
    cout<<"after sort by Insertion:";
    cout<<endl;
    for(int i=0; i<myvector1.size(); i++)
    {
        cout<<myvector1.at(i)<<" ";
    }
    cout<<endl;
    cout<<"after sort by HeapSort:";
    cout<<endl;
    for(int i=0; i<myvector2.size(); i++)
    {
        cout<<myvector2.at(i)<<" ";
    }
    cout<<endl;



    return 0;
}

void InserSort(vector<int>& a)
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

void MergeSort(vector<int>& a, int p,int r)
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

void Merge(vector<int>& a, int p, int q , int r)
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

void MaxHeapify(vector<int> &a,int i,int sz)
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

void BuildMaxHeap(vector<int>& a)
{
    for(int i = (a.size())/2 ; i>=1 ; i--)
    {
        MaxHeapify(a , i , a.size());
    }
}

void HeapSort(vector<int>& a)
{
   // vector<int> out(a.size());

    BuildMaxHeap(a);


    for(int i = a.size()-1 ; i>=1 ; i--)
    {
        swap(a.at(0),a.at(i));



        MaxHeapify(a,1,i);
    }

}


void swap(int& a,int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

