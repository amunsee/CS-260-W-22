Design: To create a graph data structure that has the ability to add new vertexs/nodes as well as adding new edges between them, it also needs to have a function that will figure out the shortest path between two nodes and a minimum spanning tree algorithm function.

for my graph i used adjacency lists to store all data. after completeing the assignment, and analyzing the runtimes it seems like using an adjacency matrix for storing the data would have been the better choice as we arent adding/removing tons of nodes for this project, the only advantage of the adjacency list is the ability to add to it as O(1) but all other operations are at best O(n) or slower. Possibly using a combination of the two could have some ability to be superior to just using one or the other?

I used Dijikstras algorithm for the shorest path function, and kruskals algorithm for the minimum spanning tree function.

Psuedo code tests in tests file of repo, main.cpp will create graph, add nodes and edges then print out each node and neighbors to verify added, then find shorest path between two nodes in graph and mst.




![20220315_161516](https://user-images.githubusercontent.com/97048406/158489207-70807f5f-fa70-40d8-a859-12c86481b670.jpg)
![20220315_161532](https://user-images.githubusercontent.com/97048406/158489219-82322f8a-baf3-42dc-9c53-abca1f84b555.jpg)
![20220315_161549](https://user-images.githubusercontent.com/97048406/158489225-f751540b-be81-4074-a0f8-5d5ab39d4c6c.jpg)
