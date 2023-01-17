#include<stdio.h>
int min(int a, int b){
    if(a<=b)
        return a;
    else 
        return b;
}

int main(){
    int v,src,i,j;
    
    printf("enter the no of vertices: ");
    scanf("%d",&v);
    
    int cost[v][v],dist[v],visited[v];
    
    printf("enter matrix: ");
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
        scanf("%d",&cost[i][j]);
        }
     }
         printf("enter the source:");
    scanf("%d",&src);
    
    dist[src]=0;
    
    for(i=1;i<v;i++)
        dist[i]=999;
    
    for(i=0;i<v;i++){
        visited[i]=0;
    }
    
    for(int c=0;c<v;c++){
        int u=-1;
        for(i=0;i<v;i++){
            if(visited[i]==0 && (u==-1||dist[i]<dist[u])){
                u=i;
            }
        }
        visited[u]=1;
        
        for(i=0;i<v;i++){
            if(cost[u][i]!=0 && visited[i]==0){
                dist[i]=min(dist[i],dist[u]+cost[u][i]);
            }
        }
    }
    
    printf("the shortest distances is: ");
    for(i=0;i<v;i++){
        printf("%d to %d->%d, ",src,i,dist[i]);
    }
}
