tests in psuedo code:

add node function:
-------------------

  create new graph
  add_node("1", 5);
  add_node("2", 3);
  add_node("3", 7);
  
  print graph - should print out nodes "1", "2", "3"
  

add edge function:
-------------------

  create new graph
  add_node("1", 5);
  add_node("2", 3);
  add_node("3", 7);
  
  
  (start node, end node, weight of edge)
  add_edge("1", "2", 3);
  add_edge("3", "2", 5);
  
  print graph - should print out nodes "1" (3)-> "2" , "2" ->, "3" (5)-> "2"
  

shortest path function:
------------------------









min spanning tree function:
---------------------------

                  purple --3--yellow
                  /               \   
                1                  9
               /                    \
graph:     blue--2----brown----7---black 
                \
                  3
                  \
                    green
                  
                  
                  
add above graph and edges/weights

output for mst function should be: 


            purple--3--yellow
          /
        1
      /
     Blue--2---brown--7---black
      \
       3
        \
        green
