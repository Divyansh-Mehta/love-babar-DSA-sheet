#include <iostream>
using namespace std;

//In this approach order of elements is not important. Time: O(n) Space: O(1)
void rearrange1(int *arr, int n) {
    int i = 0, j = n - 1;
    while (i <= j) {
        if (arr[i] > 0 && arr[j] > 0) {
            j--;
        }
        else if (arr[i] < 0 && arr[j] < 0) {
            i++;
        }
        else if (arr[i] > 0 && arr[j] < 0) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
        else {
            i++;
            j--;
        }
    }
}

//Using Dutch National Flag algorithm (Order is not given importance). Time:- O(n) Space:- O(1)
void rearrange2(int *arr, int n) {
    int i = 0, j = n - 1;
    while (i <= j){
        if (arr[i] > 0){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j--;
        }
        else{
            i++;
        }
    }
}

//Modified insertion sort (taking order into consideration). Time:- O(n^2) Space:- O(1)
void Rearrange3(int *arr, int n) {
    int j = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] < 0){
            int temp = arr[i];
            int k = i - 1;
            while (k >= j){
                arr[k + 1] = arr[k];
                k--;
            }
            arr[j++] = temp; 
        }
    }
}

int main() {
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++){
	    cin >> arr[i];
	}
	rearrange2(arr, n);
	for (int i = 0; i < n; i++){
	    cout << arr[i] << " ";
	}
	return 0;
}