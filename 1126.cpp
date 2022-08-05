#include <iostream>

using namespace std;

//faster than <algorithm>'s *max_element()

int maximum(int *array, int length)
{
   int max;
   max = array[0];
   for(int i=0; i<length; i++)
    {
        if(array[i]>max)
        {
            max = array[i];
        }
    }
  return max;
}


int main(){
    int M;
    cin>>M;
    int* que=new int[M];
    for (int i=0;i<M;i++){
        cin>>que[i];
    }
    while (que[M-1] != -1) {
        cout << maximum(que, M)<<endl;
        for (int i=0;i<M-1;i++)
            que[i]=que[i+1];
        cin>>que[M-1];
    }
	return 0;
}