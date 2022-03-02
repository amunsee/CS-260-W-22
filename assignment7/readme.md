Simple Hashtable design:
Hash method – assign each letter a value a-z, a=0, z=25  (all letters will be made lowercase if they aren’t already to avoid issues with uppercase letters when hashing) example alex = 38 (0+4+11+23) and % by 10 resulting in 3.

The data would be stored in an array with memory for 10 elements.
-collisions will result in old data being overwritten by the new data for that value

Input function: Take word as input -> call hash function to get value associated with the word -> then insert in the array at the correct value -> word alex is inserted at array[3]
Contains function: Take a word as input -> call the hash function to get the value for the word -> check the array at correct location -> for the word alex array[3] would be check to see if the value stored there is alex -> if the words match then function prints out word is in hashtable if the word at the array index is not the same then the function prints out hashtable does not contain the word {word}
Delete function: receive word as input -> get hash value for the given word -> go to correct array index word alex = 3 go to array[3] -> if the value at array[3] = the word given (alex) delete it if not make no changes to the array -> if no changes function prints out no changes made, if the word is deleted function prints {word} was deleted from the hashtable

.
.

Smarter Hashtable design: (smarter in the fact it doesnt delete data to overwrite it, and holds more data)

Will use chaining inside of the array to prevent collisions and handle more data. 

Hash method – assign each letter a value a-z, a=0, z=25  (all letters will be made lowercase if they aren’t already to avoid issues with uppercase letters when hashing) example alex = 38 (0+4+11+23) and % by 10 resulting in 3.

Insert function:
To figure out what chain the data will go into I will use the same method as the simple hashtable, (Hash method – assign each letter a value a-z, a=0, z=25  (all letters will be made lowercase if they aren’t already to avoid issues with uppercase letters when hashing) example alex = 38 (0+4+11+23) and % by 10 resulting in 3.) but after the array index is selected the full value will be added to the linked list (chain) in the array index. So the word alex would have a value of 38, 38 % 10 would = 3, resulting in the value Alex being added to the tail of the linked list in array[3].

contains function:
To check if a word is in the hashtable, it will be hashed to get the value same as the simpler hastable then the correct array index selected, once the correct index is selected the linked list will be iterated through until the value is found or nullptr is reached at the end of the list. if the word alex is given the linked list in array[3] would be iterated through until nullptr or the value alex is found, if found the function would print {word} is in the hashtable, if nullptr is reached function will print out {word} is not in the hashtable.

delete function: Hash the value, find correct array index, travel down list until value is found or nullptr at end reached, if nullptr nothing is changed as value is not in the list, if the value is found delete the node and have previous node point to what the node being deleted was pointing to.
