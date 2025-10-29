# Vector Calculator Update 3 for GIT

**This program is a upgrade to our Lab 5 and have added the function to read and save the vectors you make in the lab to a .csv file. When you open the program it will prompt you with the list of commands you can do. Then, you can follow the commands to make vectors.**

**To build the program you would need to make the files using 'make' and to clear them you need to use 'make clean'. You can also use gcc -o "what you want to name it" main.c Vector.c**

**Here is some of ways you can run the program. if the name is Lab7, you can use ./Lab7 to run it normally or you can use ./Lab7 -h which will show the functions you can input within the program before you to start the program.**


# Here are some of the list of commands that you can input in the program
    a = 1 2 3  | Create vector a with values (1, 2, 3)
    list       | List all stored vectors
    clear      | Clear all vectors
    a + b      | Add vectors a and b (prints result) and creates a vector
    a - b      | Subtract vector b from a (prints result) and creates a vector
    a * 3 or 3 * a | Multiply vector a by scalar 3 (prints result) and creates a vector
    a . b      | Compute dot product of a and b and prints result
    a x b      | Compute cross product of a and b (prints result) and creates a vector
    c = a + b  | Store result of a + b into new vector c
    c = a - b  | Subtracts vectors a and b (prints result) and create vector c
    c = a * b  | multiplies vectors a and b (prints result) and create vector c
    c = a . b  | Uses vectors a and b (prints result) of the dot product and create vector c
    c = a x b  | Uses vectors a and b (prints result) of the cross product and create vector c
    a | Display single vectors current values
    help       | Show this help menu
    quit       | Exit the program
    save       | Save the vectors to a file
    load       | load vectors from a file to the list

  
# Short description of the dynamic memory:
 The program first starts up by creating a base capacity of vectors you can input to the program, but the once you reach the limit the program will reallocate it self in order to give you more space to make new vectors. After you have finished with the program, the function clearVectors will happen after the command interface function to free up any memory that the program has made and exit smoothly.