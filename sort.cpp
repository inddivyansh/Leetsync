#include <bits/stdc++.h>
using namespace std;

void selsort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int s=i;
        for(int j=i+1; j<n; j++){
            if(arr[s]>arr[j]){
                s=j;
            }
        }
        swap(arr[s],arr[i]);
    }
}

void bubsort(int arr[], int n){
    for(int i=0; i<n; i++){
        bool swapped=false;

        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(!swapped){
            break;
        }      
    }
}

void insort(int arr[], int n){
    for(int i=0; i<n; i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    //Selction Sort
    //selsort(arr,n); 
  
    //Bubble Sort
    //bubsort(arr,n);
  
    //Insertion Sort
    insort(arr,n);

    for (int i:arr) cout << i << " ";

    return 0;
}
