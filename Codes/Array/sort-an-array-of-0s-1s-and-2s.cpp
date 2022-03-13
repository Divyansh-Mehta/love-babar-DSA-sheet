#include <iostream>
using namespace std;

void sort012(int a[], int n){
    int k = 0, i = 0, j = n - 1;
    while (i <= j){
        if (a[i] == 0){
            a[i++] = a[k];
            a[k++] = 0;
        }
        else if (a[i] == 2){
            a[i] = a[j];
            a[j--] = 2;
        }
        else if (a[i] == 1){
            i++;
        }
    }
}

int main(){
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort012(a, n);

    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}