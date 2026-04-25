#include <stdio.h>

#include <stdlib.h>

#include <limits.h>

#define MAX 100

// FRACTIONAL KNAPSACK

void fractionalKnapsack()
{

    int n;

    printf("Enter number of items: ");

    scanf("%d", &n);

    float weight[n], profit[n], ratio[n];

    for (int i = 0; i < n; i++)
    {

        printf("Enter profit and weight for item %d: ", i + 1);

        scanf("%f %f", &profit[i], &weight[i]);

        ratio[i] = profit[i] / weight[i];
    }

    float capacity;

    printf("Enter capacity of knapsack: ");

    scanf("%f", &capacity);

    // Sorting items by ratio (descending)

    for (int i = 0; i < n - 1; i++)
    {

        for (int j = i + 1; j < n; j++)
        {

            if (ratio[i] < ratio[j])
            {

                float temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;

                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;
            }
        }
    }

    float totalProfit = 0;

    for (int i = 0; i < n; i++)
    {

        if (weight[i] <= capacity)
        {

            capacity -= weight[i];

            totalProfit += profit[i];
        }
        else
        {

            totalProfit += profit[i] * (capacity / weight[i]);

            break;
        }
    }

    printf("Maximum profit = %.2f\n", totalProfit);
}

// JOB SEQUENCING WITH DEADLINE

typedef struct
{

    int id;

    int deadline;

    int profit;

} Job;

void jobSequencing()
{

    int n;

    printf("Enter number of jobs: ");

    scanf("%d", &n);

    Job jobs[n];

    for (int i = 0; i < n; i++)
    {

        jobs[i].id = i + 1;

        printf("Enter deadline and profit for job %d: ", i + 1);

        scanf("%d %d", &jobs[i].deadline, &jobs[i].profit);
    }

    // Sorting jobs by profit (descending)

    for (int i = 0; i < n - 1; i++)
    {

        for (int j = i + 1; j < n; j++)
        {

            if (jobs[i].profit < jobs[j].profit)
            {

                Job temp = jobs[i];

                jobs[i] = jobs[j];

                jobs[j] = temp;
            }
        }
    }

    int maxDeadline = 0;

    for (int i = 0; i < n; i++)
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;

    int slot[maxDeadline];

    for (int i = 0; i < maxDeadline; i++)
        slot[i] = -1;

    int totalProfit = 0;

    for (int i = 0; i < n; i++)
    {

        for (int j = jobs[i].deadline - 1; j >= 0; j--)
        {

            if (slot[j] == -1)
            {

                slot[j] = jobs[i].id;

                totalProfit += jobs[i].profit;

                break;
            }
        }
    }

    printf("Job sequence: ");

    for (int i = 0; i < maxDeadline; i++)

        if (slot[i] != -1)
            printf("J%d ", slot[i]);

    printf("\nTotal profit: %d\n", totalProfit);
}
// KRUSKAL'S ALGORITHM

typedef struct
{

    int u, v, weight;

} Edge;

int findParent(int parent[], int i)
{

    while (parent[i] != i)
        i = parent[i];

    return i;
}

void kruskal()
{

    int n, e;

    printf("Enter number of vertices and edges: ");

    scanf("%d %d", &n, &e);

    Edge edges[e];

    for (int i = 0; i < e; i++)
    {

        printf("Enter u v weight for edge %d: ", i + 1);

        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    // Sort edges by weight

    for (int i = 0; i < e - 1; i++)
    {

        for (int j = i + 1; j < e; j++)
        {

            if (edges[i].weight > edges[j].weight)
            {

                Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }

    int parent[n + 1];

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    printf("Edges in MST:\n");

    int count = 0, totalWeight = 0;

    for (int i = 0; i < e && count < n - 1; i++)
    {

        int u = edges[i].u;

        int v = edges[i].v;

        int setU = findParent(parent, u);

        int setV = findParent(parent, v);

        if (setU != setV)
        {

            printf("%d - %d = %d\n", u, v, edges[i].weight);

            totalWeight += edges[i].weight;

            parent[setU] = setV;

            count++;
        }
    }

    printf("Total weight of MST: %d\n", totalWeight);
}

// PRIM'S ALGORITHM

void prim()
{

    int n;

    printf("Enter number of vertices: ");

    scanf("%d", &n);

    int graph[n][n];

    printf("Enter adjacency matrix (0 if no edge):\n");

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {

            scanf("%d", &graph[i][j]);
        }
    }

    int selected[n];

    for (int i = 0; i < n; i++)
        selected[i] = 0;

    selected[0] = 1;

    printf("Edges in MST:\n");

    int totalWeight = 0;

    for (int edges = 0; edges < n - 1; edges++)
    {

        int min = INT_MAX, x = -1, y = -1;

        for (int i = 0; i < n; i++)
        {

            if (selected[i])
            {

                for (int j = 0; j < n; j++)
                {

                    if (!selected[j] && graph[i][j])
                    {

                        if (graph[i][j] < min)
                        {

                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        printf("%d - %d = %d\n", x, y, min);

        totalWeight += min;

        selected[y] = 1;
    }

    printf("Total weight of MST: %d\n", totalWeight);
}

// DIJKSTRA'S ALGORITHM

void dijkstra()
{

    int n;

    printf("Enter number of vertices: ");

    scanf("%d", &n);

    int graph[n][n];

    printf("Enter adjacency matrix (0 if no edge):\n");

    for (int i = 0; i < n; i++)

        for (int j = 0; j < n; j++)

            scanf("%d", &graph[i][j]);

    int src;

    printf("Enter source vertex (0 to %d): ", n - 1);

    scanf("%d", &src);

    int dist[n], visited[n];

    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++)
    {

        int min = INT_MAX, u = -1;

        for (int i = 0; i < n; i++)

            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }

        visited[u] = 1;

        for (int v = 0; v < n; v++)
        {

            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&

                dist[u] + graph[u][v] < dist[v])

                dist[v] = dist[u] + graph[u][v];
        }
    }

    printf("Vertex \t Distance from Source\n");

    for (int i = 0; i < n; i++)

        printf("%d \t %d\n", i, dist[i]);
}

// MAIN MENU

int main()
{

    int choice;

    do
    {

        printf("\n--- Algorithm Menu ---\n");

        printf("1. Fractional Knapsack\n");

        printf("2. Job Sequencing with Deadline\n");

        printf("3. Kruskal's Algorithm\n");

        printf("4. Prim's Algorithm\n");

        printf("5. Dijkstra's Algorithm\n");

        printf("0. Exit\n");

        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            fractionalKnapsack();
            break;

        case 2:
            jobSequencing();
            break;

        case 3:
            kruskal();
            break;

        case 4:
            prim();
            break;

        case 5:
            dijkstra();
            break;

        case 0:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice! Try again.\n");
        }

    } while (choice != 0);

    return 0;
}
