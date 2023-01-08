#include <iostream>
#include <string>


using namespace std;

// Do not initialize.
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

// Do initialize.
int res;
int visit[26] = {0,};
char map[20][20];
int ch[20][20];

// User-defined Function.
int dfs(int x, int y, int r, int c);


int main(){
    int T = 0;
    cin >> T;
    
    int row, col;

    for (int t = 0; t < T; t++) {
        // Initialize.
        res = 0;
        for (int k = 0; k < 26; k++)
            visit[k] = 0;
        
        // Get 2d-Array Input.
        cin >> row >> col;
        for (int i = 0; i < row; i++) {
            string line;
            cin >> line;
            for (int j = 0; j < col; j++)
                map[i][j] = line[j];
        }
        
        // Call Function.
        visit[map[0][0] - 'A'] += 1;
        dfs(0, 0, row, col);

        // Output.
        cout << '#' << t+1 << ' ' << res << endl;
    }
}


int dfs(int x, int y, int r, int c){

    // Update.
    int tmp = 0;
    for (int k = 0; k < 26; k++)
        tmp += visit[k];
    if (tmp > res)
        res = tmp;
    
    // DFS algorithm.
    int xx, yy;
    for (int i = 0; i < 4; i++){
        xx = x + dx[i];
        yy = y + dy[i];
        if (0 > xx || xx >= r || 0 > yy || yy >= c)
            continue;  // Invalid (x,y) postion.
        
        if (visit[map[xx][yy] - 'A'] == 0){
            visit[map[xx][yy] - 'A'] += 1;
            dfs(xx, yy, r, c);
            visit[map[xx][yy] - 'A'] -= 1;
        }   
    }
}