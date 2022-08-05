#include <iostream>
#include <algorithm>
using namespace std;

struct segment{
    int start=-50001;
    int end=50001;
};

int cmp_condition(segment a, segment b){
    //if (a.end==b.end) return a.start > b.start;
    return a.end > b.end;//in ascending order by right ends
}

int main(){
    segment *line=new segment[131072];
    segment *answer=new segment[131072];//2^17 to speed up execution by aligning pointers
    short M; //M=[1,5000]
    cin>>M;
    int x,y,inp=0;
    //preparing input
    while(cin>>x>>y) {
        if (x==0 && y==0) break;
        else if (!(x>M || y<0)){
            line[inp].start=x;
            line[inp].end=y;
            inp++;
        }

    }
    sort(line, line+inp, cmp_condition);
    int border=0;
    int count =0;
    while(border < M)
    {
        int i = 0;
        for(; i < inp; ++i)
        {
            if(line[i].start <= border && line[i].end > border)
            {
                answer[count] = line[i];
                count++;
                border = line[i].end;    // Update boundary points
                break;
            }
        }
        if(i == inp)break;//!important!
    }


    if(border < M)
        cout << "No solution" << endl;
    else
    {
        cout << count << endl;
        for(int i = 0; i < count; ++i)
            cout << answer[i].start << " " << answer[i].end << endl;
    }
    //exit
    delete [] line;
    delete [] answer;
    return 0;
}

