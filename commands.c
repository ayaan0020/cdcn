Command	Purpose
ipconfig	     Displays IP address
ipconfig /all	  Displays complete network details
ping google.com	  Checks internet connectivity
ping 127.0.0.1	   Tests local TCP/IP
tracert google.com	 Shows the route to a destination
nslookup google.com	  Finds DNS information
hostname	           Displays   computer name
getmac	Displays        MAC address
arp -a	Displays         IP-to-MAC mappings
netstat -ano	         Displays network connections and process IDs
route print	              Displays routing table



#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;

    printf("\n--- NETWORKING COMMANDS ---\n");
    printf("1. IP Configuration\n");
    printf("2. Ping Google\n");
    printf("3. Hostname\n");
    printf("4. Netstat\n");
    printf("5. NSLookup\n");
    printf("6. ARP Table\n");
    printf("7. Trace Route\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            system("ipconfig");
            break;

        case 2:
            system("ping -n 4 google.com");
            break;

        case 3:
            system("hostname");
            break;

        case 4:
            system("netstat -ano");
            break;

        case 5:
            system("nslookup google.com");
            break;

        case 6:
            system("arp -a");
            break;

        case 7:
            system("tracert google.com");
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}


--- NETWORKING COMMANDS ---
1. IP Configuration
2. Ping Google
3. Hostname
4. Netstat
5. NSLookup
6. ARP Table
7. Trace Route

Enter your choice: 3

YOUR-COMPUTER-NAME