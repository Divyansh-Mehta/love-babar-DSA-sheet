#include <iostream>
#include<queue>
using namespace std;

// time :- o(n long(k)) if k << n then O(n), space :- o(k)
int kthSmallest(int *arr, int n, int k){
    priority_queue<int> Max;
    for (int i = 0; i < k; i++){
        Max.push(arr[i]);
    }

    for (int i = k; i < n; i++){
        if (Max.top() > arr[i]){
            Max.pop();
            Max.push(arr[i]);
        }
    }
    return Max.top();
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;

    cout << kthSmallest(arr, n, k) << endl;

    return 0;
}
