/*
DNSresolver
Created in 31/08/2023
By Rayan Araujo
Version 1.0
*/

#include <stdio.h>     // Needed for input/output operations
#include <stdlib.h>    // Manages dynamic memory allocation
#include <netdb.h>     // Hostname resolution
#include <arpa/inet.h> // Functions for ip binary form conversion
#include <string.h>    // String managing

// Handle argument count and storage.
int main(int argc, char *argv[])
{
	if(argc !=2)
	{
		fprintf(stderr,"\"Usage: %s www.google.com\"", argv[0]);
		return 1;
	}

	char hostname[100]; /* Creates a buffer to store the hostname string.*/
	
	struct hostent *host_info; /* An instance of the hostent structure in which gethostbyname 
	 organizes the addresses's found information. */

	// Use gethostbyname to get the IP address of the hostname
	host_info = gethostbyname(argv[1]);
	
	// Error handler
	if (host_info == NULL)
	{
		herror("Couldn't resolve hostname");
		printf("\n\"Usage: %s www.google.com\"", argv[0]);
		return 1;
	}

	// Print result from the struct hostent
	printf ("\nHostname: %s\n", host_info->h_name);
	printf ("IP address: %s\n", inet_ntoa(*(struct in_addr *)host_info->h_addr));
	/*inet_ntoa(converts binary form to human legible strings)*/
}
