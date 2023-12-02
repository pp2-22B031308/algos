#include <iostream>
using namespace std;

int getClosest(int, int, int);

int findClosest(int a[], int n, int k){
    if (k < a[0])
        return a[0];
    else if (k > a[n-1])
        return a[n-1];

    int i =0, j = n, mid = 0;
    while (i < j){
        mid = (i + j) / 2;
        if (a[mid] == k)
            return a[mid];
        if (k < a[mid]){
            if (mid > 0 && k > a[mid -1]){
                return getClosest(a[mid -1], a[mid], k);
            }
            j = mid;
        }
        else {
            if (mid < n -1  && k < a[mid + 1]){
                return getClosest(a[mid + 1], a[mid], k);
            }
            i = mid + 1;
        }    
    }
    return a[mid];    
}

int getClosest(int val1, int val2, int k){
    if (k - val1 >= val2 - k){
        return val2;
    }
    else 
        return val1;
}

int main(){
    int n, k;
    cin >> n;
    int a[n];
    for (int i = 0; i< n; i++){
        cin >> a[i];
    }
    cin >>k;
    cout << (findClosest(a,n,k));

}