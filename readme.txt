****************************************************
Calvin Nichols  
To Do List Program - Assignment Three
Thr 29 Nov 2012 10:13:12 PM EDT
****************************************************

    REFERENCES:
        1. http://en.wikipedia.org/wiki/AVL_tree
        2. http://anoopsmohan.blogspot.ca/2011/11/avl-tree-implementation-in-c.html
        3. http://www.cprogramming.com/tutorial/c/lesson18.html
        4. Lesson 10 AVL Tree, Judi McCuaig
        5. http://www.geeksforgeeks.org/archives/18009

   COMPILE ALL:
   - make
   - make all

   OPTIONS:
   - make clean


  todoListManager.c

    COMPILE:
    - navigate to A3 directory
    - make todoList

    RUN:
    - navigate to A3 directory
    - make run
    or
    - enter "./bin/a3 ./todo.txt"
        - may replace "./todo.txt" with your own input file.

    USAGE:
    - The program will display the list read in from the input file.
    - Underneath it will display a list of possible selections the user may choose.
        - Add
            - add allows the user to input a new todo item.
            - the first time add is selected instructions for adding will be printed:
              " Enter an activity and its priority (1-100) ex.'watch_starwars 4'
              priorities range from 1 to 100. They are also optional."
            - entries should follow the format "activity priority", a string representing the activity, followed by a space, followed by an interger ranging from 1 - 100, which is optional.
            - the entry will be added to the priority queue, the list will be printed again and the options displayed again.
        - Remove
            - remove will delete the first node of the queue.
            - the list will be printed again and the options displayed again.
        - Quit
            - program will end.


  testTree.c

    COMPILE:
    - navigate to A3 directory
    - make treeTest

    RUN:
    - make tTest
    or
    - enter "./bin/tTest"

    USAGE:
    - You will be presented with a list of options, this list is intended to help with debugging, testing and marking my program.
        - Add
            - accepts an integer to insert into the tree
            - prints the current list and displays available options
        - Remove
            - removes the smallest node from the tree
            - prints the list and displays available options
        - Print Pretty Tree
            - prints a visual representation of the tree
        - Print PreOrder
            - prints the tree in preorder
        - Print InOrder
            - prints the tree in order
        - Quit
            - quits the program


  queueTest.c

    COMPILE:
    - navigate to A3 directory
    - make queueTest

    RUN:
    - make qTest
    or
    - enter "./bin/qTest"

    USAGE:
    - You will be presented with a list of options, this list is intended to help with debugging, testing and marking my program.
        - Add
            - entries should follow the format "activity priority", a string representing the activity, followed by a space, followed by an interger ranging from 1 - 100, which is optional.
        - Remove
            - deletes the first node in the list.
            - prints the list and displays available options
        - Quit
            - quits the program

    PROGRAM EXCELLENCE:

        I believe my program is above the requirements for the following:

            - User Input, I have been working on a small input library all semester that I have used and improved upon for this assignment (inputInterface.h).
                - My menu input is simple to set up and tough to break, I could not come up with a way to break it.
                - My inputs are all taken as strings and each character is checked for an appropriate value.
                - I check for single newlines and handle appropriately.
                - As you will see in my todoListManager.c, my menu loops are simple and clear.

            - File Input, I am very happy with my solution to reading in file input and user input. I made one really strong method of reading in the file input and then had the user input in the same manner. It allows for reusable, clean code and use of libraries.

            - Commenting, file structure, general program set up, modularity, coding style.
                - I made seperate .h files for every node to improve modularity and encapsulation as much as possible.
                - I did my best to make my program function as clear as possible for the marker and anyone who may be looking at my code for the first time.
                - I made seperate header files whenever I thought necessary and did my best to appropriately assign functions to those files.

            - Usability
                - My to do list manager is clean and simple.
                - On the first call to add I present the user with instructions on how to add, and only if they make a mistake (a mistake is just entering nothing, at the moment), the instructions are presented again. This allows for the terminal to be filled with minimal clutter and presents the user with instructions only when they need them.


*****************
Known Limitations
*****************
    - No balancing after a removal from tree.
    - Comments are very limited in my testing C files.
    - Some functions (minNode, maxNode, getHeight, etc) in my balancedTree.c take in a struct treeNode when a wrapper function taking a Tree may be more appropriate but I did not include these because they are all helper functions that I included in my balancedTree.h only so I could use them in my testing C files.
    - I destroy my tree but there are still memory leaks, I did not do testing on this.

*******************************
Academic Integrity Pledge
*******************************

I have exclusive control over this submission via my password.
By including this file with my submitted files, I certify that:

1) I have read and understood the University policy on academic integrity;
2) I have completed the Computing with Integrity Tutorial on Moodle; and
3) I have achieved at least 80% in the Computing with Integrity Self Test.

I assert that this work is my own.

I have appropriately acknowledged any and all material (data, images, ideas or
words) that I have used, whether directly quoted or paraphrased.  Furthermore,
I certify that this assignment was prepared by me specifically for this course.
