#include <iostream>
using namespace std;

struct segment{
    int start=0;
    int end=0;
};

int main(){
    int n,m,maximum=0;
    cin>>n;
    //lines
    segment *line = new segment[131072]; //max number of lines is 100 000, to make program faster I used 2^17 elements, this will align the pointer
										//(usage of new segment[n] - runtime error 19)
    for (int i=1; i<=n; i++){
        cin>>line[i].start>>line[i].end;
        if (line[i].end>maximum) maximum=line[i].end;
    }

    //queries
    cin>>m;
    int query;
    int j=1;
    for (int i = 0; i<m; i++){
        cin>>query;
        if (query > maximum || query < line[1].start) cout << -1 <<endl;
        else{
            while (query>=line[j].start){
                j++;
                if (j>n) break;
            }
            while (query>line[j-1].end){
                j--;
            }
            cout<<j-1<<endl;
        }
    }
    //exit
    delete [] line;
    return 0;
}