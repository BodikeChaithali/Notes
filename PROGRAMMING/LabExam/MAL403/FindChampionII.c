int findChampion(int n, int** edges, int edgesSize, int* edgesColSize) {
    int indegree[n];
    for(int i=0;i<n;i++) indegree[i]=0;

    for(int i=0;i<edgesSize;i++) {
        int from = edges[i][0];
        int to = edges[i][1];
        indegree[to]++;
    }

    int champ = -1;
    for(int i=0;i<n;i++) {
        if(indegree[i] == 0) {
            if(champ != -1)
                return -1;
            champ = i;
        }
    }
    return champ;
}
