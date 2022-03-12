#include <iostream>
using namespace std;

//Time :- o(n) space o(1)
void reverse(int *arr, int size){
    int start = 0, end = size - 1;
    while (start <= end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    reverse(arr, n);
    for (int i = 0; i < n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}