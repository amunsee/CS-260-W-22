Assignment 5: create one of or both an array based or linked list that can insert values in a sorted way - (will be sorting smallest to largest numbers since it is left to us to determine sorting order).

For an array based list - to sort i could iterate through the list from one end to the other checking to see if the value is smaller or higher (depending on which end i start at) than the value to be inserted, ideally starting from the end of the array so that if the value checked is higher i shift it one index to the right in the array and continue to check/shift until i reach a value that is smaller or the beginning of the array. Another option i might attempt is to implement a binary search, once the correct location is found to insert the new value I would then move from the end to that location shifting the values left and insert the value. (could be situationlly better than iterating through each index)

For a linked list - iterating through the list starting at the head and checking if the value is smaller, once a larger value is found the inserted value would point to that and the previous node would be changed to point at the new node. - unsure of how a binary sort could be implemented into the linked list but will look into some methods.

searching for an element in an array will be done using binary search or iterating one end to the other (not ideal but works), linked list search as of right now will be iterating from head to tail or until element found, will explore some other methods.


Attempt at big O analysis - Sort  ------------------------ Search

Using fast search method  - O(n) ------------------------- O(n/2) - Not entirely sure on these but this is my guess on them

Basic search method would be O(n) 



![assignment5design](https://user-images.githubusercontent.com/97048406/152081361-0fbad00c-dbcd-45be-95a0-976fd7bf206a.jpg)
