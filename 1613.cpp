#include <iostream>
#include <algorithm>
using namespace std;

struct database{
    int number;
    int value;
};

bool cmp_condition(database i, database j){
    if (i.value == j.value)
        return i.number < j.number;
    else return (i.value < j.value);
}

int main() {
    int n = 0; //number of cities
    int q = 0;//number of queries;
    int l,r,x,mid,lb,rb;
    cin>>n;
    database *data = new database [n];
    for (int i=0; i<n; i++){
        cin>>data[i].value;
        data[i].number=i+1;
    }
    sort(data,data+n, cmp_condition);//sorting bubble was too slow so I used sort()
    //Queries
    cin>>q;
    while(q--) {
        cin>>l>>r>>x;
        lb=0;
        rb=n;
        bool stop=false;
        while (lb<=rb && stop==false){
            mid=(rb+lb)/2;
            if (data[mid].value==x && data[mid].number>=l && data[mid].number<=r) {
                cout<<1;
                stop=true;
            }
            else if (data[mid].value > x || data[mid].value == x && data[mid].number > r)
                rb=mid-1;
            else if (data[mid].value < x || data[mid].value == x && data[mid].number < l)
                lb=mid+1;
        }
        if (stop==false) cout<<0;
    }
    delete [] data;
    return 0;
}