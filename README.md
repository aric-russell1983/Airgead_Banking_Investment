# Airgead_Banking_Investment
This program is designed to display and calculate accrued interest on an investment account with and without monthly deposits.

Airgead Banking Investment Program Reflection

1. Summarize the project and what problem it was solving.

The Airgead Banking Investment program was designed to show users how an investment can grow over time with and without additional monthly deposits. The program asks the user to enter an initial investment amount, monthly deposit, annual interest rate, and number of years. It then calculates the yearly ending balance and total interest earned using monthly compounding. By displaying two separate reports, the program allows users to compare how making additional monthly deposits can affect the growth of an investment. This project helped me apply C++ programming concepts to a real-world financial problem while learning how to organize a program using classes, functions, loops, and input validation.

2. What did you do particularly well?

I think I did particularly well with organizing my code and making the program's output readable. I separated the program into three files: main.cpp, investment.h, and investment.cpp. This allowed me to keep the main program separate from the investment calculations and class declaration. I also created reusable functions, such as printSpacer() and printHeader(), to make the program's output more organized. I used # characters to separate sections and center the headings, which made the reports easier to read.

Another area I did well in was implementing input validation. I created getValidInput() to check that the user entered a positive number and getValidYears() to make sure the number of years was a positive whole number. I also used nested loops to calculate interest for each month and display the results for each year. These features helped me create a program that was organized, easier to use, and capable of handling common input errors.

3. Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?

One improvement I could make is to strengthen the input validation. My current functions handle many common invalid inputs, such as letters instead of numbers and values that are zero or negative. However, I could improve them by checking for extremely large values, non-finite numbers, and values that could cause problems when converting the number of years to an integer. I could also replace the fixed cin.ignore(1000, '\n') limit with a more robust approach to clearing invalid input.

Another improvement would be to reduce repeated code in the two investment calculation functions. Both functions use similar loops to calculate monthly interest and yearly totals. I could consider creating a shared helper function to handle the common calculations while keeping the deposit behavior separate. This would make the program easier to maintain because changes to the shared calculation logic would not need to be repeated in multiple places.

I could also improve the accuracy and reliability of the program by testing more scenarios, including larger investments, longer time periods, and different interest rates. Since the program works with financial calculations, I would also need to consider how rounding is handled when displaying dollar amounts. These improvements would make the program more robust, easier to maintain, and more reliable when processing different user inputs.

4. Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?

The most challenging part of this project was implementing the monthly interest calculations correctly. I needed to understand how to convert the annual interest rate into a monthly rate and how to update the investment balance throughout the year. I used nested for loops to calculate interest for each of the 12 months and another loop to repeat the process for the number of years entered by the user. I also needed to keep track of the total interest earned during each year so that it could be displayed in the report.

Another challenge was making sure the monthly deposit was added at the correct point in the calculation. In my monthly deposit function, I calculate and add the interest before adding the deposit to the balance. This means the new deposit does not earn interest until the following month, which follows the intended calculation process for the assignment.

I overcame these challenges by breaking the calculations into smaller steps, reviewing the assignment instructions, and testing the program with sample values. I also used comments to explain what each section of code was doing. Going forward, I plan to continue using SNHU course materials, C++ documentation, compiler messages, debugging tools, and practice problems as resources. These tools will help me identify mistakes, understand unfamiliar concepts, and become more confident solving programming problems independently.

5. What skills from this project will be particularly transferable to other projects or course work?

The skills I developed in this project will be useful in future C++ assignments and other programming projects. I gained experience creating classes, using constructors, separating declarations from implementations, and writing functions that perform specific tasks. I also practiced using loops, conditional statements, variables, mathematical formulas, and input validation.

Another important skill was learning how to break a larger problem into smaller parts. For example, I separated user input, investment calculations, and output formatting into different functions or files. This approach can be applied to larger projects where different parts of a program need to work together. Testing the calculations against expected results also helped me understand the importance of verifying that a program produces correct output rather than simply compiling successfully.

These skills will be especially useful as I continue working toward my computer science degree with a concentration in software engineering because organizing, testing, and maintaining code are important parts of developing reliable software.

6. How did you make this program maintainable, readable, and adaptable?

I made the program more maintainable by separating it into main.cpp, investment.h, and investment.cpp. The header file contains the Investment class declaration, including its private member variables and public functions. The implementation file contains the constructor and the functions that calculate balances and display the yearly results. The main file handles user input, creates the investment object, and controls the order in which the reports are displayed.

I also used descriptive names for variables and functions, along with comments to explain the purpose of different sections. Functions such as getValidInput(), getValidYears(), printSpacer(), and printHeader() help keep the main function organized and allow me to reuse the same functionality instead of writing the same code repeatedly. The class structure also keeps the investment data together with the functions that use it.

This design makes the program easier to update because changes can be made to individual functions without rewriting the entire program. For example, I could change the report formatting in the header functions or modify the investment calculations in the implementation file. I could also expand the program in the future by adding new investment features or more detailed reports. Separating the program into logical sections makes it easier to understand, troubleshoot, and adapt as requirements change.
