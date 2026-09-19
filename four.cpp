#include <iostream>
#include <vector>
using namespace std;

long long increasing_array(vector<long long> vec){
    long long res = 0;
    for(size_t i = 1;i < vec.size();i++){
        if(vec[i] < vec[i-1]){
            res += (vec[i-1] - vec[i]);
            vec[i] = vec[i-1];
        }
    }
    return res;
}

int main(){
    int n;

    if(!(cin >> n)) return 0;

    vector<long long> vec(n);
    for(int i = 0;i < n;i++){
        cin>>vec[i];
    }
    cout << increasing_array(vec) << endl;
    return 0;
}