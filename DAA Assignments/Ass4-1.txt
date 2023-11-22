import java.util.*;
import java.lang.*;
import java.io.*;
  
class dijkstra_algo {
    //Function to find the vertex with minimum distance   
    static final int n = 6;//size of graph
    
    int min_dist(int distance[], Boolean visited[])
    {
        
        int min = Integer.MAX_VALUE, min_index = -1;
  
        for (int v = 0; v < n; v++)
            if (visited[v] == false && distance[v] <= min) {
                min = distance[v];
                min_index = v;
            }
  
        return min_index;
    }
  
    //Function to print the constructed distance array
    void printSolution(int distance[], int n)
    {
        System.out.println("Vertex      Distance from Source");
        for (int i = 0; i < n; i++)
            System.out.println(((char)(i+65)) + " \t\t \t" + distance[i]);
    }
  
    // Function that implements Dijkstra's algorithm
    
    void dijkstra(int graph[][], int source)
    {
        int distance[] = new int[n]; // The output array
  
        
        Boolean visited[] = new Boolean[n];
  
        // Initialize all distances as INFINITE and stpSet[] as false
        for (int i = 0; i < n; i++) {
            distance[i] = Integer.MAX_VALUE;//initializing infinity
            visited[i] = false;
        }
  
        // Distance of source vertex from itself is always 0
        distance[source] = 0;
  
        // Find shortest path for all vertices
        for (int count = 0; count < n - 1; count++) {
            // Pick the minimum distance vertex from unvisited vertices
            int u = min_dist(distance, visited);
  
            // Mark the picked vertex as visited
            visited[u] = true;
  
            // Updating dist value of the adjacent vertices of the
            // picked vertex.
            for (int v = 0; v < n; v++)
  
                //relaxing all the neighbouring vertices
                if (!visited[v] && graph[u][v] != 0 && 
                   distance[u] != Integer.MAX_VALUE && distance[u] + graph[u][v] < distance[v])
                    distance[v] = distance[u] + graph[u][v];
        }
  
        // print the constructed distance array
        printSolution(distance, n);
    }
  
    // Driver method
    public static void main(String[] args)
    {
        
        int graph[][] = new int[][] { {0,4,5,0,0,0},
                                      {4,0,11,9,7,0},
                                      {5,11,0,0,3,0},
                                      {0,9,0,0,13,2},
                                      {0,7,3,13,0,6},
                                      {0,0,0,2,6,0}};
        dijkstra_algo t = new dijkstra_algo();
        int src=0;
        t.dijkstra(graph, src);
    }
}

