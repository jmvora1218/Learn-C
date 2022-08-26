// C program to Open a File,
// Write in it, And Close the File

# include <stdio.h>
# include <string.h>

int main( )
{

	// Declare the file pointer
	FILE *pointer ;
	
	// Get the data to be written in file
	char dataToBeWritten[50] ;

    // Open the existing file GfgTest.c using fopen()
	// in write mode using "w" attribute
	pointer = fopen("jayv.c", "r") ;
	
	// Check if this filePointer is null
	// which maybe if the file does not exist
	if ( pointer == NULL )
	{
		printf( " failed to open." ) ;
	}
	else
	{
		printf("The file is now opened.\n") ;
		
		// Write the dataToBeWritten into the file
		//if ( strlen ( dataToBeWritten ) > 0 )
		//{
			
			// writing in the file using fputs()
			 while( fgets ( dataToBeWritten, 50, pointer ) != NULL )
        {
            // Print the dataToBeRead
            printf( "%s" , dataToBeWritten ) ;
        }
         
		
		// Closing the file using fclose()
		fclose(pointer) ;
		
		printf("Data read successfully not written in file \n");
		printf("The file is now closed.\n") ;
	}
	return 0;	
}
