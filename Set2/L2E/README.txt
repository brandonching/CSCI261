First, refactor the code to place function prototypes in a separate header file named calculator_functions.h.
Then, place the corresponding function definitinos in a separate source file named calculator_functions.cpp.
Finally, modify your Makefile to build the calculator_functions.cpp source file.

Build your program.

Run the executable through the debugger.  Perform the following steps.  For each step, add the command that performs that task.

1a. Add a breakpoint inside the print_result() function.


1b. What different in how we need to specify the breakpoint compared to L2D?


2. Run the program, requesting to add 4 and 5


3a. Print the stack trace


3b. What's different in how the stack trace is formed compared to L2D?


4. Print the current stack frame


5. Print all local variables and arguments within the scope of the current stack frame


6. Move up one level in the stack frame


7. Print all local variables and arguments within the scope of the current stack frame


8. Continue the program, requesting to subtract the values


9. Print the stack trace again


10. Step through the program until we have moved out of the two lower stack frames


11. Print the stack trace again


12. Kill the program
