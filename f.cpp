#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> v;
    for(int i=0; i<n; i++){
        int x; cin >> x; 
        v.push_back(x);
    }
    int x,y; cin >> x >> y;
    v.insert(v.begin()+y, x);
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
}