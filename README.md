# College-cpp
This code is a C++ program that includes functions for generating a username and calculating a factorial, along with a menu that allows the user to choose between the two options or quit the program. 

In the main function, the program prompts the user to enter their name using the getline function to read a whole line of input. Then, the menu function is called within a do-while loop that keeps looping until the user chooses to quit.

The menu function displays the available options to the user and reads their choice using the cin function. Depending on the choice, it calls either the string_function or the number_function.

The string_function prompts the user to enter their first and last name and checks if there is a space in the input. If so, it calls the create_name function to generate a username by taking the first letter of the first name and the first two letters of the last name and concatenating them into a single string. If the input is invalid, the function displays an error message.

The number_function prompts the user to enter a positive whole number greater than 0, using a while loop to keep prompting the user until they enter a valid input. Once a valid input is entered, the function calculates the factorial of the number using a while loop, displaying the calculation process and the result.

Finally, the create_name function takes a string argument that contains the user's first and last name and returns a string that contains the first letter of the first name and the first two letters of the last name in uppercase. If the input string contains more than two words, it only uses the first two.
