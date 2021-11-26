//IT_A_35_Vedant_Oza
//9.Implementation of any one Graph Traversal Technique for real-world application.
#include <stdio.h>
#include <stdlib.h>
// ADJACENCY MATRIX
int source, V, E, time, visited[20], G[20][20];
void DFS(int i)
{
    int j;
    visited[i] = 1;
    printf(" %d->", i + 1);
    for (j = 0; j < V; j++)
    {
        if (G[i][j] == 1 && visited[j] == 0)
            DFS(j);
    }
}
// Main function
int main()
{
    int i, j, v1, v2;
    printf("\t\t\tGraphs\n");
    printf("Enter the no of edges:");
    scanf("%d", &E);
    printf("Enter the no of vertices:");
    scanf("%d", &V);
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
            G[i][j] = 0;
    }
    /* creating edges :P */
    for (i = 0; i < E; i++)
    {
        printf("Enter the edges (format: V1 V2) : ");
        scanf("%d%d", &v1, &v2);
        G[v1 - 1][v2 - 1] = 1;
    }
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
            printf(" %d ", G[i][j]);
        printf("\n");
    }
    printf("Enter the source: ");
    scanf("%d", &source);
    DFS(source - 1);
    return 0;
}

// // DFS algorithm in C
// #include <stdio.h>
// #include <stdlib.h>
// struct node
// {
//     int vertex;
//     struct node *next;
// };
// struct node *createNode(int v);
// struct Graph
// {
//     int numVertices;
//     int *visited;
//     // We need int** to store a two dimensional array.
//     // Similary, we need struct node** to store an array of Linked lists
//     struct node **adjLists;
// };
// // DFS algo
// void DFS(struct Graph *graph, int vertex)
// {
//     struct node *adjList = graph->adjLists[vertex];
//     struct node *temp = adjList;
//     graph->visited[vertex] = 1;
//     printf("Visited %d \n", vertex);
//     while (temp != NULL)
//     {
//         int connectedVertex = temp->vertex;
//         if (graph->visited[connectedVertex] == 0)
//         {
//             DFS(graph, connectedVertex);
//         }
//         temp = temp->next;
//     }
// }
// // Create a node
// struct node *createNode(int v)
// {
//     struct node *newNode = malloc(sizeof(struct node));
//     newNode->vertex = v;
//     newNode->next = NULL;
//     return newNode;
// }
// // Create graph
// struct Graph *createGraph(int vertices)
// {
//     struct Graph *graph = malloc(sizeof(struct Graph));
//     graph->numVertices = vertices;
//     graph->adjLists = malloc(vertices * sizeof(struct node *));
//     graph->visited = malloc(vertices * sizeof(int));
//     int i;
//     for (i = 0; i < vertices; i++)
//     {
//         graph->adjLists[i] = NULL;
//         graph->visited[i] = 0;
//     }
//     return graph;
// }
// // Add edge
// void addEdge(struct Graph *graph, int src, int dest)
// {
//     // Add edge from src to dest
//     struct node *newNode = createNode(dest);
//     newNode->next = graph->adjLists[src];
//     graph->adjLists[src] = newNode;
//     // Add edge from dest to src
//     newNode = createNode(src);
//     newNode->next = graph->adjLists[dest];
//     graph->adjLists[dest] = newNode;
// }
// // Print the graph
// void printGraph(struct Graph *graph)
// {
//     int v;
//     for (v = 0; v < graph->numVertices; v++)
//     {
//         struct node *temp = graph->adjLists[v];
//         printf("\n Adjacency list of vertex %d\n ", v);
//         while (temp)
//         {
//             printf("%d -> ", temp->vertex);
//             temp = temp->next;
//         }
//         printf("\n");
//     }
// }
// int main()
// {
//     struct Graph *graph = createGraph(4);
//     addEdge(graph, 0, 1);
//     addEdge(graph, 0, 2);
//     addEdge(graph, 1, 2);
//     addEdge(graph, 2, 3);
//     printGraph(graph);
//     DFS(graph, 2);
//     return 0;
// }
// // BFS algorithm in C
// #include <stdio.h>
// #include <stdlib.h>
// #define SIZE 40
// struct queue
// {
//     int items[SIZE];
//     int front;
//     int rear;
// };
// struct queue *createQueue();
// void enqueue(struct queue *q, int);
// int dequeue(struct queue *q);
// void display(struct queue *q);
// int isEmpty(struct queue *q);
// void printQueue(struct queue *q);
// struct node
// {
//     int vertex;
//     struct node *next;
// };
// struct node *createNode(int);
// struct Graph
// {
//     int numVertices;
//     struct node **adjLists;
//     int *visited;
// };
// // BFS algorithm
// void bfs(struct Graph *graph, int startVertex)
// {
//     struct queue *q = createQueue();
//     graph->visited[startVertex] = 1;
//     enqueue(q, startVertex);
//     while (!isEmpty(q))
//     {
//         printQueue(q);
//         int currentVertex = dequeue(q);
//         printf("Visited %d\n", currentVertex);
//         struct node *temp = graph->adjLists[currentVertex];
//         while (temp)
//         {
//             int adjVertex = temp->vertex;
//             if (graph->visited[adjVertex] == 0)
//             {
//                 graph->visited[adjVertex] = 1;
//                 enqueue(q, adjVertex);
//             }
//             temp = temp->next;
//         }
//     }
// }
// // Creating a node
// struct node *createNode(int v)
// {
//     struct node *newNode = malloc(sizeof(struct node));
//     newNode->vertex = v;
//     newNode->next = NULL;
//     return newNode;
// }
// // Creating a graph
// struct Graph *createGraph(int vertices)
// {
//     struct Graph *graph = malloc(sizeof(struct Graph));
//     graph->numVertices = vertices;
//     graph->adjLists = malloc(vertices * sizeof(struct node *));
//     graph->visited = malloc(vertices * sizeof(int));
//     int i;
//     for (i = 0; i < vertices; i++)
//     {
//         graph->adjLists[i] = NULL;
//         graph->visited[i] = 0;
//     }
//     return graph;
// }
// // Add edge
// void addEdge(struct Graph *graph, int src, int dest)
// {
//     // Add edge from src to dest
//     struct node *newNode = createNode(dest);
//     newNode->next = graph->adjLists[src];
//     graph->adjLists[src] = newNode;
//     // Add edge from dest to src
//     newNode = createNode(src);
//     newNode->next = graph->adjLists[dest];
//     graph->adjLists[dest] = newNode;
// }
// // Create a queue
// struct queue *createQueue()
// {
//     struct queue *q = malloc(sizeof(struct queue));
//     q->front = -1;
//     q->rear = -1;
//     return q;
// }
// // Check if the queue is empty
// int isEmpty(struct queue *q)
// {
//     if (q->rear == -1)
//         return 1;
//     else
//         return 0;
// }
// // Adding elements into queue
// void enqueue(struct queue *q, int value)
// {
//     if (q->rear == SIZE - 1)
//         printf("\nQueue is Full!!");
//     else
//     {
//         if (q->front == -1)
//             q->front = 0;
//         q->rear++;
//         q->items[q->rear] = value;
//     }
// }
// // Removing elements from queue
// int dequeue(struct queue *q)
// {
//     int item;
//     if (isEmpty(q))
//     {
//         printf("Queue is empty");
//         item = -1;
//     }
//     else
//     {
//         item = q->items[q->front];
//         q->front++;
//         if (q->front > q->rear)
//         {
//             printf("Resetting queue ");
//             q->front = q->rear = -1;
//         }
//     }
//     return item;
// }
// // Print the queue
// void printQueue(struct queue *q)
// {
//     int i = q->front;
//     if (isEmpty(q))
//     {
//         printf("Queue is empty");
//     }
//     else
//     {
//         printf("\nQueue contains \n");
//         for (i = q->front; i < q->rear + 1; i++)
//         {
//             printf("%d ", q->items[i]);
//         }
//     }
// }
// int main()
// {
//     struct Graph *graph = createGraph(6);
//     addEdge(graph, 0, 1);
//     addEdge(graph, 0, 2);
//     addEdge(graph, 1, 2);
//     addEdge(graph, 1, 4);
//     addEdge(graph, 1, 3);
//     addEdge(graph, 2, 4);
//     addEdge(graph, 3, 4);
//     bfs(graph, 0);
//     return 0;
// }
// //SYIT_A_08_Chauhan Abdurrahman Altaf
// //9.Implementation of any one Graph Traversal Technique for real-world application.
// #include <stdio.h>
// #include <stdlib.h>
// struct Node
// {
//     int data;
//     struct Node *next;
// } *front = NULL, *rear = NULL;
// void enqueue(int x)
// {
//     struct Node *t;
//     t = (struct Node *)malloc(sizeof(struct Node));
//     if (t == NULL)
//         printf("Queue is FUll\n");
//     else
//     {
//         t->data = x;
//         t->next = NULL;
//         if (front == NULL)
//             front = rear = t;
//         else
//         {
//             rear->next = t;
//             rear = t;
//         }
//     }
// }
// int dequeue()
// {
//     int x = -1;
//     struct Node *t;
//     if (front == NULL)
//         printf("Queue is Empty\n");
//     else
//     {
//         x = front->data;
//         t = front;
//         front = front->next;
//         free(t);
//     }
//     return x;
// }
// int isEmpty()
// {
//     return front == NULL;
// }
// void BFS(int G[][7], int start, int n)
// {
//     int i = start, j;
//     int visited[7] = {0};
//     printf("%d ", i);
//     visited[i] = 1;
//     enqueue(i);
//     while (!isEmpty())
//     {
//         i = dequeue();
//         for (j = 1; j < n; j++)
//         {
//             if (G[i][j] == 1 && visited[j] == 0)
//             {
//                 printf("%d ", j);
//                 visited[j] = 1;
//                 enqueue(j);
//             }
//         }
//     }
// }
// void DFS(int G[][7], int start, int n)
// {
//     static int visited[7] = {0};
//     int j;
//     if (visited[start] == 0)
//     {
//         printf("%d ", start);
//         visited[start] = 1;
//         for (j = 1; j < n; j++)
//         {
//             if (G[start][j] == 1 && visited[j] == 0)
//                 DFS(G, j, n);
//         }
//     }
// }
// int main()
// {
//     int G[7][7] = {{0, 0, 0, 0, 0, 0, 0},
//                    {0, 0, 1, 1, 0, 0, 0},
//                    {0, 1, 0, 0, 1, 0, 0},
//                    {0, 1, 0, 0, 1, 0, 0},
//                    {0, 0, 1, 1, 0, 1, 1},
//                    {0, 0, 0, 0, 1, 0, 0},
//                    {0, 0, 0, 0, 1, 0, 0}};
//     DFS(G, 4, 7);
//     printf("\n");
//     BFS(G, 4, 7);
//     return 0;
// }