#include <iostream>
#include <utility>
using namespace std;

//Approach - 1
//comparision :- best = n - 1, worst = 2(n - 1)
pair<long long, long long> getMinMax(long long *a, int size){
    long long Min = a[0], Max = a[0];

    for (int i = 1; i < size; i++){
        if (a[i] < Min){
            Min = a[i];
        }
        else if (a[i] > Max){
            Max = a[i];
        }
    }
    return {Min, Max};
} 

//Approach - 2
//comparision :- t(n) = t(floor(n / 2)) + t(ceil(n / 2)) + 2;
pair<long long, long long> helper(long long a[], int l, int h){
    if (l == h){
        return {a[l], a[h]};
    }
    
    if (h == l + 1){
        int min, max;
        if (a[h] < a[l]){
            min = a[h];
            max = a[l];
        }
        else{
            min = a[l];
            max = a[h];
        }
        return {min, max};
    }
    int mid = (l + h) / 2;
    pair<long long, long long> temp1 = helper(a, l, mid);
    pair<long long, long long> temp2 = helper(a, mid + 1, h);
    
    int max, min;
    if (temp1.first < temp2.first){
        min = temp1.first;
    }
    else{
        min = temp2.first;
    }
    
    if (temp1.second > temp2.second){
        max = temp1.second;
    }
    else{
        max = temp2.second;
    }
    
    return {min, max};
}

pair<long long, long long> getMinMax2(long long a[], int n) {
    return helper(a, 0, n - 1);
}

//Approach - 3
//comparisions :- odd :- 3 * (n - 1) / 2, even :- 3 * (n - 2) / 2 + 1
pair<long long, long long> getMinMax3(long long a[], int n) {
    int min, max, i;
    
    if (n % 2 != 0){
        min = a[0];
        max = a[0];
        i = 1;
    }
    else{
        if (a[0] < a[1]){
            min = a[0];
            max = a[1];
        }
        else{
            min = a[1];
            max = a[0];
        }
        i = 2;
    }
    
    while(i <= n - 2){
        if (a[i] < a[i + 1]){
            if (a[i] < min){
                min = a[i];
            }
            if (a[i + 1] > max){
                max = a[i + 1];
            }
        }
        else{
            if (a[i + 1] < min){
                min = a[i + 1];
            }
            if (a[i] > max){
                max = a[i];
            }
        }
        i += 2;
    }
    return {min, max};
}

int main(){
    int n;
    cin >> n;
    long long *a = new long long[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    pair<long long, long long> ans = getMinMax(a, n);
    cout << ans.first << " " << ans.second << endl;
    delete []a;

    return 0;
}