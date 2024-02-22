 simple_shell is a unix-like shell that  displays a command prompt to indicate that it is ready to accept user input. 

This simple_shell operates in a loop, where it reads user input, evaluates the command, 
executes it (if valid), and then prints the output or any relevant messages back to the user. The loop continues until the user explicitly exits the shell.
The primary purpose of this simple_ shell is to execute commands. Users can type in command-line instructions, and the shell interprets and runs these commands. The shell looks for the requested command or executable program in the directories listed in the system's PATH environment variable.

files are  compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
this project is a requirement to complete the first sprint in the ALX SE program.
done by ELVIS MBURU and SATHA GESEY.

To start interacting with the shell your can run the following commands on the root directory
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`


