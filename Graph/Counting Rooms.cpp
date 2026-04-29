#include<bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void dfs(int i, int j, int n, int m, vector<vector<char>>&rooms) {
    rooms[i][j] = '#';

    for(int k = 0; k < 4; k++) {
        int x = dx[k] + i;
        int y = dy[k] + j;

        if(x>=0 && x<n && y>=0 && y<m && rooms[x][y]=='.') {
            dfs(x, y, n, m, rooms);
        }
    }
}

int main()
{
    int n, m; cin >> n >> m;
    vector<vector<char>> rooms(n, vector<char>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> rooms[i][j];
        }
    }

    int room = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(rooms[i][j] == '.') {
                dfs(i, j, n, m, rooms);
                room++;
            }
        }
    }

    cout << room <<'\n';
}
