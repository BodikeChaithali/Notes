#include <stdio.h>

int n, m, grid[50][50], visited[50][50];

void dfs(int x, int y) {
    if(x<0 || y<0 || x>=n || y>=m || visited[x][y] || grid[x][y]==0) return;
    visited[x][y] = 1;
    dfs(x+1,y); dfs(x-1,y); dfs(x,y+1); dfs(x,y-1);
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&grid[i][j]);

    int count = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(grid[i][j] == 1 && !visited[i][j]) {
                count++;
                dfs(i,j);
            }
    printf("Islands = %d\n",count);
}
