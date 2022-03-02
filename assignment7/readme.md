Simple Hashtable design:
Hash method – assign each letter a value a-z, a=0, z=25  (all letters will be made lowercase if they aren’t already to avoid issues with uppercase letters when hashing) example alex = 38 (0+4+11+23) and % by 10 resulting in 3.

The data would be stored in an array with memory for 10 elements.
-collisions will result in old data being overwritten by the new data for that value

Input function: Take word as input -> call hash function to get value associated with the word -> then insert in the array at the correct value -> word alex is inserted at array[3]
Contains function: Take a word as input -> call the hash function to get the value for the word -> check the array at correct location -> for the word alex array[3] would be check to see if the value stored there is alex -> if the words match then function prints out word is in hashtable if the word at the array index is not the same then the function prints out hashtable does not contain the word {word}
Delete function: receive word as input -> get hash value for the given word -> go to correct array index word alex = 3 go to array[3] -> if the value at array[3] = the word given (alex) delete it if not make no changes to the array -> if no changes function prints out no changes made, if the word is deleted function prints {word} was deleted from the hashtable


Smarter Hashtable design:
