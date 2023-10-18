#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include <string.h>
#include "function.h"



int main(){

    while(1)
	{
		menu();
		char choice;
        printf("ENTER YOUR CHOICE:");
        scanf(" %[^\n]c",&choice);


        switch(choice)
            {
            case '1':
                addtask();
                break;

            case '2':
                viewtask();
                break;

            case '3':
                updatetask();
                break;

            case '4':
                deletetask();
                break;

            case '0':
                printf("GoodBye");
                Sleep(1000);
                return 0;
                break;

            default:
                printf("Invalid choice!!!\n");
                Sleep(1000);
                fflush(stdin);
                system("cls");

            }
        }



return 0;
}
