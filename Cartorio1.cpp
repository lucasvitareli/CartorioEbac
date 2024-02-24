#include <stdio.h> 						// library for user communication
#include <stdlib.h> 					// library for memory allocation
#include <locale.h> 					// library for region-based text
#include <string.h> 					// library responsible for string handling

int register_user() 														// Function responsible for registering users in the system
{											
    char file[40];															// Creating variables/strings
    char id_number[40];
    char first_name[40];
    char last_name[40];
    char job_title[40];

    printf("Enter the ID Number to be registered: ");								// Collecting user information
    scanf("%s", id_number);															// Storing user information in a string

    strcpy(file, id_number);														// Responsible for copying the values of the strings

    FILE *file_pointer;																// Accessing files in the system, creating a file
    file_pointer = fopen(file, "w");												// Opening file with "w" (command for writing)
    fprintf(file_pointer, "%s", id_number);											// Saving the value of the Id Number variable inside the file
    fclose(file_pointer);															// Closing the file
																
    file_pointer = fopen(file, "a");										// Opening the saved file and giving the command to append  "a".
    fprintf(file_pointer, ",");												// Requesting to save information, adding a comma at the end.
    fclose(file_pointer);													// Closing the file

    printf("Enter the Name to be registered: ");
    scanf("%s", first_name);												// Clearing any character that may have been written on the line

    file_pointer = fopen(file, "a");
    fprintf(file_pointer, "%s", first_name);
    fclose(file_pointer);

    file_pointer = fopen(file, "a");
    fprintf(file_pointer, ",");
    fclose(file_pointer);

    printf("Enter the Last Name to be registered: ");
    scanf("%s", last_name);

    file_pointer = fopen(file, "a");
    fprintf(file_pointer, "%s", last_name);
    fclose(file_pointer);

    file_pointer = fopen(file, "a");
    fprintf(file_pointer, ",");
    fclose(file_pointer);

    printf("Enter the Job Title to be registered: ");
    scanf("%s", job_title);

    file_pointer = fopen(file, "a");
    fprintf(file_pointer, "%s", job_title);
    fclose(file_pointer);

    file_pointer = fopen(file, "a");
    fprintf(file_pointer, ",");
    fclose(file_pointer);

    printf("\n\nUser successfully registered!\n");							// Confirming to the user that the registration was successful

    system("pause");														// Pausing the screen so that the user does not return to the menu automatically.
    return 0;															    
}																			 // End of register_User()

int query()
{
	char id_number[40];                              									// Creating variables
	char content[200];
		
	printf("Enter the ID Number to be queried: "); 								// Asking the user to enter the desired ID Number
	scanf("%s", id_number);                         							// Storing information in the id_number variable

	
	FILE *file;                                            							 // Finding the File
	file = fopen(id_number,"r");                                  					 // Oppening the file id_number to be read, "r" (command for reading)

	if(file == NULL)                                            			   // If the information is not found in the file...	
{
	printf("\n\nID Number was not found!\n\n");               				   // Display this message to the on screen
	system("pause");
}
	while(fgets(content, 200, file) != NULL)                      				// While getting content in the file, store information; otherwise (NULL), return to the menu
{
	printf("\nThese are the user's information: \n\n");           	            // Display this information on screen, with the data found in the file
	printf("%s", content);    
	printf("\n\n");                                                             // Comando to skipp lines in the display.
	
	system("pause");                                                            // Pausing the screen so that the user does not return to the menu automatically.
} 
		
}                                                                                       // End of Query()

int deleting()
{
	char id_number[40];
	
	printf("Enter the user's ID Number to be deleted: ");
	scanf("%s", id_number);
	
	FILE *file_pointer;                                                               // Opening the file corresponding to the id_number and issuing the "r" (command for reading)
	file_pointer = fopen(id_number,"r");
	
	if (file_pointer == NULL)                                                        // In case the typed number is not found in the file..."
	{
		printf("The ID Number was not found in the system!\n");          			// This message will be displayed in the screen
		system("pause");                                                        	// Command that pauses the current screen.
		return 0;                                                              	    // Command that sends the user back to the initial screen.
	}
	
	fclose(file_pointer);                                                           // Closing the file after verifying his existance
		
	printf("Do you want to delete this user? ");                           			// Confirming the user's choice regarding deleting or not deleting this student
	printf("%s",id_number);                                                
	printf("\nType (y) for Yes or type (n) para no!\n\n");              		 // Providing character choices for the user to make their selection.
	
	getchar();                                                                  // Function to capture user input through characters.
	
	char option;                                                                  // Creating variable 'option'.
	option = getchar();                                                           // Defining that the 'option' variable will be associated with getchar (character that we will specify).
		
	if (option == 'y' || option == 'Y')                                            // If the entered character is lowercase 'y' or uppercase 'Y'.
	{
	if (remove(id_number) == 0)                                                    // delete the file 'id_number' and checks if the removal was successful.
	{
		printf("This user has been deleted!\n");                                  // If successful, Display the message on screen.
	}
		system("pause");
	}
	
	
	else if (option == 'n' || option == 'N')                                        // If the entered character is lowercase 'n' or uppercase 'N'.
	{
		printf("Return to the main Menu \n");                                   // Display this message on screen.
		system("pause");
	}
		
	else
	{
		printf("\nThis option is not valid, return to the main Menu!\n\n");                     // Message displayed if the user enters a character other than (y) or (n).
		system("pause");
	}
	}                                                                               // End of Deleting() 

	
int main ()																			// Creating the main menu 
	{
    int option=0;	                                                                // Defining variables
    int loop=1;
    char entered_password[10]="a";													// Creating a string for the password entered by the user.
    int compare;																	// Criando variavel para comparision
    
    printf("### EBAC Register System ###\n\n");
    printf("ADMIN LOGIN\n\n Please, insert your password:");						// Asking the user to enter the access password
    scanf("%s",entered_password);														// Storing the entered data in the previously created string.
    
    compare = strcmp(entered_password, "admin"); 									// Defining the variable 'compare' with the result between the string 'entered_Password' and the specified password.
       																				// If the entered value matches the password "admin", the result is "0", indicating that there is no difference in the comparison.
    
    if(compare == 0)																// Creating a condition so that if the result is "0", the menu is displayed on the screen for the user to use.
    {
    	system ("cls");																// Command to clean the screen.
	    for(loop=1;loop=1;)                                              			// Creating a loop
    	{
    	
		system("cls");                        										// Deleting the messages from the screen
		
		printf("### EBAC Register system ###\n\n");                     			// Menu start                    
    	printf("Choose the desired option from the Menu: \n\n");
		printf("\t1 - Register new user \n");
		printf("\t2 - Query user \n");
    	printf("\t3 - Delete user \n");      
    	printf("\t4 - Exit \n\n"); 
    	printf("Option:");						                 							// End of Menu
	
		scanf("%d", &option);																// Storing the user's choice according to the variable.
	
		system("cls");                     												    // Clearing messages from the screen
		
		
		switch(option)                  													// Start of the Menu selection
			{
			case 1:                    
			register_user();                   												// Calling for Register_user()
			break;	
	
			case 2:
			query();                                                                    	// Calling for Querry()
			break;
		
			case 3:
			deleting();                                                                     // Calling for Deleting()
			break;
		
			case 4:
			printf("Thank You for using the system!\n");									// Displaying a 'Thank you' message on the screen
			return 0;
			break;
			
			default:
			printf("This is not a valid option\n");               							// Displaying a 'Invalid option message' on the screen
			system("pause");
			break;
			}                                      											// End of Menu selection
		}																			 	    // End of the Loop
	}                                                										// End of 'correct password' condition
	
	else																					// Condition if the entered password is not correct
		printf("Password incorrect!");														// Display this message on screen 
	
	}                                                    									// End of main menu int main()
