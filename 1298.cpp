//This solution uses Warnsdorff's Rule
//use G++ or Clang++ as compiler, Visual C++ doesn't support "x ... y" in switch-case
#include <iostream>
#include <cstring>

using namespace std;

short N;
bool flag;
int sqr_visited[9][9];
short board[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

void dfs(int r, int c, int depth){
    if (depth < N*N) {
        for (auto &i : board) { //for every element in board
            int x = r + i[0];
            int y = c + i[1];
            if (x >= 1 && x <= N && y >= 1 && y <= N && !sqr_visited[x][y]) {
                sqr_visited[x][y] = depth + 1;
                dfs(x, y, depth + 1);
                if (!flag) {
                    sqr_visited[x][y] = 0;

                }
                else
                    break;//exit
            }
        }
    }
    else{
        flag = true;
    }
}

int main(){
    cin >> N;
    memset(sqr_visited, 0, sizeof(sqr_visited));
    switch (N) {
        case 1:
            cout<<"a1";
            break;
        case 2 ... 4:
            cout<<"IMPOSSIBLE";
            break;
        case 5 ... 8:
            flag = false;
            sqr_visited[1][1] = 1;
            dfs(1, 1, 1);
            if (flag) {
                for (int i = 1; i <= N * N; ++ i) {
                    for (int j = 1; j <= N; ++ j) {
                        for (int k = 1; k <= N; ++ k) {
                            if (sqr_visited[j][k] == i) {
                                cout << (char)(j + 'a' - 1) << k << endl;
                            }
                        }
                    }
                }
            } else {
                cout<<"IMPOSSIBLE";
            }
    }
    return 0;
}