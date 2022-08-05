#include <iostream>
#include <algorithm>

using namespace std;

struct segment{
    int start=1000;
    int end=-1000;
    bool view=true;
};

bool cmp_condition(segment i, segment j){
    if (i.end == j.end) return i.start < j.start;
    else return i.end < j.end;
}

int main(){
    int n=0;
    cin>>n;
    int counter=0;
    segment *arr = new segment [n];
    segment *out = new segment [n];
    for (int i = 0; i < n; i++){
        cin>>arr[i].start>>arr[i].end;
    }
    sort(arr,arr+n, cmp_condition);
    out[0]=arr[0];
    counter++;
    for (int i = 1; i < n; i++){
        if (arr[i].view) {
            if (arr[i].start < out[counter-1].end) arr[i].view = false;
                else {
                    out[counter] = arr[i];
                    counter++;
                }
            }
        }
    cout<<counter<<endl;
    for (int i=0;i<counter;i++){
        cout<<out[i].start<<" "<<out[i].end<<endl;
    }
    delete [] arr;
    delete [] out;
    return 0;
}