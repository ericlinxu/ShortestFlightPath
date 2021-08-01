# Final Project

## [Project Goal](https://docs.google.com/document/d/1KqPFCLv-Ce-Irtz-sAP0E7RfaINJ9PoY7Hfacv8kVYM/edit)

The primary aim of this project is to identify the shortest route between two given airport destinations by using Dijkstra's and Landmark Algorithms. If there exists a *direct* route between the two airport destinations, Dijkstra's algorithm will be used. If a direct route does not exist, the shortest route accounting layover flights will be identified using the Landmark algorithm.

## Datasets and Traversals

This project will use the [OpenFlights](https://openflights.org/data.html/) dataset. The unique IATA identifier code will be used thoughout the project when referring to airports. Our project uses BFS when traversing the tree.

## Running The Program
### Dijkstra's Algorithm

To run Dijkstra's algorithm, open `main.cpp` and scroll down to the `outputs` vector. It will look similar to this:

```
vector<Vertex> output = Dijkstra(g, "ORD", "LAX"); 
```
Here, you can insert any two IATA codes of your choosing. In your terminal, run `make` followed by `./finalproj`. If everything goes smoothly, nothing will happen (in the terminal)!

Next, locate the `outputs` folder in the workspace and navigate to `dijkstraOutput.txt`. Here, you will see a list of airports by IATA code. This sorted list is the shortest path between the two airports listed.

### Landmark Algorithm

To run Landmark algorithm, once again open `main.cpp` and scroll down to the `destinations` vector.

```
vector<Vertex> destinations;
```
Underneath, you can insert any number of destinations by adding to the `destinations` vector. For example, if you wanted to add ORD, you may try:
```
destinations.push_back("ORD");
```
You may add as many destinations as you would like. 

Next, locate the `landmark` vector. This is where your traversal will begin. For instance, if you wanted to see how to visit all of the destinations from ORD, you may try:
```
vector<Vertex> landmark = Landmark(g,"ORD", destinations);
```
You are now set up to run the landmark algorithm. Once again, in your terminal, run `make` followed by `./finalproj`. If everything goes smoothly, nothing will happen (in the terminal)!

Now, locate the `outputs` folder in the workspace and navigate to `landmarkOutput.txt`. Here is the list of the shortest path between your source and all of your destination airports.

### BFS

This is just an algorithm to run for fun. Running this will create all the nodes that are contained within the traversal tree.

There is nothing you need to do on your end, other than having already ran `./finalproj`. To check your magnificent list, just navigate to the `outputs` folder in the workspace and click on `bfsOutput.txt`. Voila.

**Note:** To make your own tests, navigate to `tests.cpp` and create your own tests. To run tests, go into your terminal, type `make test` followed by `./test`.
