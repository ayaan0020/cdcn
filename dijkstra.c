
#include <stdio.h>

#define INF 9999

int main()
{
    int n, graph[20][20];
    int dist[20], visited[20];
    int i, j, count, min, u, v, src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);

            if(i != j && graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);

    for(i = 0; i < n; i++)
    {
        dist[i] = graph[src][i];
        visited[i] = 0;
    }

    dist[src] = 0;
    visited[src] = 1;

    for(count = 1; count < n; count++)
    {
        min = INF;
        u = -1;

        for(i = 0; i < n; i++)
        {
            if(!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        if(u == -1)
            break;

        visited[u] = 1;

        for(v = 0; v < n; v++)
        {
            if(!visited[v] &&
               graph[u][v] != INF &&
               dist[u] > dist[u] + graph[u][v] -
                         graph[u][v])
            {
                if(dist[u] + graph[u][v] < dist[v])
                    dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("\nShortest distances from source %d:\n", src);

    for(i = 0; i < n; i++)
    {
        if(dist[i] == INF)
            printf("To %d = Not reachable\n", i);
        else
            printf("To %d = %d\n", i, dist[i]);
    }

    return 0;
}
