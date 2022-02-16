Add function test:

    General: add nodes to a tree, and should be in correct position based off rules given <= to left, > to right
   
    specific: add_test(){
                  tree *leafy = new tree();
                  
                  leafy->add(10);
                  leafy->add(8);
                  leafy->add(15);
                  
                  cout<<leafy->head<<endl; //should give 10(pass)
                  cout<<leafy->head->right<<endl; //should give 15 (pass)
                  cout<<leafy->head->left<<endl; //should give 8 (pass)
                  
              };

remove function test:

    General: remove value from tree, and prevent any holes in tree
    
    Specific:          create tree:          10
                                       8          15
                                       
                                       
                          tree->remove_test(){
                          tree *leafy = new tree();
                  
                          leafy->add(10);
                          leafy->add(8);
                          leafy->add(15);
                          
                          leafy->remove(10);
                          
                          cout<<leafy->head<<endl; //should give 8(pass)
                          cout<<leafy->head->right<<endl; //should give 15 (pass)
                          cout<<leafy->head->left<<endl; //should return nullptr
                          };
                                     

Traversal function test:

     General: print out tree and make sure it prints in order.
  
     Specific: create tree                  10
                                       8          15
                                     7   9      13  16  
                                    
                                    traversal_test(){
                                    tree *leafy = new tree();
                  
                                      leafy->add(10);
                                      leafy->add(8);
                                      leafy->add(15);
                                      leafy->add(9);
                                      leafy->add(7);
                                      leafy->add(16);
                                      leafy->add(13);
                                      
                                      leafy->traversal(); //should print out - 7,8,9,10,13,15,16(pass) anything else (fail)
                                    };
                                    
                                    
