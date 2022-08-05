#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct segment{
    int num;
    int start=10001;
    int end=-10001;
};

bool compare(segment a, segment b){
    if (a.start == b.start)
        return a.end < b.end;
    return a.start < b.start;
}

int main(){
    int N;
    int count=0;
    segment arr[500];
    vector <int> tmpR(500);
    vector <int> tmpL(500);
    //input
    cin >> N;
    for (int i = 0; i < N; i++){
        arr[i].num = i+1;
        cin >> arr[i].start >> arr[i].end;
    }
    sort(arr, arr + N, compare);

    for (int i = 0; i < N; i++){
        //binsearch
        int left = 0, maxR = arr[i].end, right = count, middle;
        while(left <= right )
        {
            middle = (left + right) / 2;
            if(tmpR[middle] > maxR)
                left = middle + 1;
            else
                right = middle - 1;
        }
        tmpR[left] = maxR;
        tmpL[i] = left;
        count = max(count, left);
    }

    //output
    cout << count+1 << endl;
    for(int i = N - 1; i >= 0; i--){
        if(tmpL[i] == count && arr[i].end != -10001){
            cout << arr[i].num << ' ';
            count--;
        }
    }
    return 0;
}