struct task{
char taskname[100];
char category[100];
char duedate[100];
char status[100];
};

void menu(){
    printf("*************************************************\n");
	printf("*\t   WELCOME TO TASK MANAGEMENT\t\t*\n");
	printf("*\t      CHOOSE YOUR OPTION\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t0.EXIT\t\t\t\t*\n");
	printf("*\t\t1.ADD NEW TASK\t\t\t*\n");
	printf("*\t\t2.VEW ALL TASK\t\t\t*\n");
	printf("*\t\t3.UPDATE TASK\t\t\t*\n");
	printf("*\t\t4.DELETE TASK\t\t\t*\n");
	printf("*************************************************\n");
}

int copy(char*dest,char*source,int num_chars){
    int count;
    for(count=1;count<=num_chars;count++)
        *dest++ = *source++;
    *dest = '\0';
    return count;
}

void addtask(){
        system("cls");
        printf("*************************************************\n");
        printf("*\t\t  ADD A NEW TASK\t\t*\n");
        printf("*************************************************\n");

        struct task add;
        int choices=0,charnum;
        char category[3][100]={"HOME","SCHOOL","WORK"};
        char status[]="INCOMPLETE";
        char a[30] = "TASKNAME";
        char b[30] = "CATEGORY";
        char c[30] = "DUEDATE";
        char d[30] = "STATUS";

        printf("Enter Taskname:");
        scanf(" %[^\n]%*c",add.taskname);

        while(choices!=3&&choices!=2&&choices!=1)
            {
                system("cls");
                fflush(stdin);
                printf("Select a category");
                printf("\n1.HOME");
                printf("\n2.SCHOOL");
                printf("\n3.WORK");
                printf("\nEnter your choice:");
                scanf("%d",&choices);



                if (choices==3||choices==2||choices==1)
                    {
                        if (choices==1||choices==3)
                            {
                                charnum = 4;
                            }
                        else
                            {
                                charnum=6;
                            }
                        copy(&add.category[0],&category[choices-1][0],charnum);
                    }

                else
                    {
                        printf("INVALID INPUT!!");
                        Sleep(1000);
                        continue;
                    }
            }

        system("cls");
        fflush(stdin);
        printf("Enter Duedate(dd/mm/yyyy:)");
        scanf(" %[^\n]%*c",add.duedate);
        system("cls");
        fflush(stdin);

        copy(&add.status[0],&status[0],sizeof(status));


        FILE*f;
        f=fopen("data.txt","a");
        if (f == NULL)
            {
                printf("Could not open file");
            }
        else
            {
                fprintf(f,"\n%s:%s:%s:%s:END",add.taskname,add.category,add.duedate,add.status);
                printf("%-15s %-15s %-15s %-15s\n",a,b,c,d);
                printf("%-15s %-15s %-15s %-15s\n",add.taskname,add.category,add.duedate,add.status);
                printf("Data saved successfully\n");
            }

        fclose(f);

    }

void viewtask(){
    system("cls");

        char no[30]= "NO";
        char a[30] = "TASKNAME";
        char b[30] = "CATEGORY";
        char c[30] = "DUEDATE";
        char d[30] = "STATUS";
        int line = 0;
        int i;
        char str[200];

        printf("%-15s %-15s %-15s %-15s %-15s\n",no,a,b,c,d);
        printf("----------------------------------------------------------------------------------");
        FILE*f;
        f=fopen("data.txt","r");
        while(!feof(f))
                {

                fgets(str,sizeof str,f);
                char*token = strtok(str,":");
                if (line!=0)
                    {
                    printf("\n");
                    printf("%-15d",line);
                    i=0;
                    while(token != NULL && i<4)
                        {
                            printf( " %-15s", token ); //printing each token
                            token = strtok(NULL, ":");
                            i++;
                        }

                    }
                line = line +1;
                }
        fclose(f);
        printf("\n\n\n\n");


}

void updatetask(){
    system("cls");
    struct task update[100];

    int no=0;
    int field=0;
    int check;
    int catchoices=0,statchoices=0,charnum;
    char category[3][100]={"HOME","SCHOOL","WORK"};
    char status[2][100]={"COMPLETE","INCOMPLETE"};

    char str[100];
    int i,x,y;

    FILE*f;
    f=fopen("data.txt","r");
    check = 0;
    while(!feof(f))
        {
            fgets(str,sizeof str,f);
            check++;
        }
    fclose(f);

    while (no>check-1 || no<1)
        {
            printf("ENTER TASK_NO:");
            scanf("%d",&no);
            if (no>check-1 || no<1)
                {
                    printf("Invalid Input\n");
                    Sleep(1000);
                }

            system("cls");
            fflush(stdin);
        }

    while (field!=1&&field!=2&&field!=3&&field!=4)
        {
            printf("1.TASKNAME");
            printf("\n2.CATEGORY");
            printf("\n3.DUEDATE");
            printf("\n4.STATUS");
            printf("\nSELECT WHICH FIELD NO YOU WANT TO CHANGE:");
            scanf("%d",&field);
            fflush(stdin);
            printf("\n");
            switch(field)
            {
            case 1:
                printf("Enter New Taskname:");
                scanf(" %[^\n]%*c",update[no].taskname);
                break;

            case 2:
                while(catchoices!=1&&catchoices!=2&&catchoices!=3)
                    {
                        system("cls");
                        fflush(stdin);
                        printf("Select a category");
                        printf("\n1.HOME");
                        printf("\n2.SCHOOL");
                        printf("\n3.WORK");
                        printf("\nEnter your choice:");
                        scanf("%d",&catchoices);
                        if (catchoices==3||catchoices==2||catchoices==1)
                            {
                                if (catchoices==1||catchoices==3)
                                    {
                                        charnum = 4;
                                    }
                                else
                                    {
                                        charnum=6;
                                    }
                                copy(&update[no].category[0],&category[catchoices-1][0],charnum);
                            }

                        else
                            {
                                printf("INVALID INPUT!!");
                                Sleep(1000);
                                continue;
                            }
                    }
                    break;

            case 3:
                printf("Enter New Duedate:");
                scanf(" %[^\n]%*c",update[no].duedate);
                break;

            case 4:
                while(statchoices!=1&&statchoices!=2)
                    {
                        system("cls");
                        fflush(stdin);
                        printf("Select a status");
                        printf("\n1.COMPLETE");
                        printf("\n2.INCOMPLETE");
                        printf("\nEnter your choice:");
                        scanf("%d",&statchoices);
                        if (statchoices==2||statchoices==1)
                            {
                                if (statchoices==1)
                                    {
                                        charnum = 8;
                                    }
                                else
                                    {
                                        charnum=10;
                                    }
                                copy(&update[no].status[0],&status[statchoices-1][0],charnum);
                            }

                        else
                            {
                                printf("INVALID INPUT!!");
                                Sleep(1000);
                                continue;
                            }
                    }
                    break;

            default:
                printf("INVALID INPUT!!");
                Sleep(1000);
                system("cls");
                fflush(stdin);
                continue;
            }
        }
    system("cls");
    fflush(stdin);


    f=fopen("data.txt","r");
    x=0;
    while(!feof(f))
        {
            fgets(str,sizeof str,f);
            char*token = strtok(str,":");
            i=1;
            while(token != NULL)
                {
                    if(!(i==field && x==no))
                        {
                            if (i==1)
                                {
                                    copy(update[x].taskname,token,30);
                                }
                            else if (i==2)
                                {
                                    copy(update[x].category,token,30);

                                }
                            else if (i==3)
                                {
                                    copy(update[x].duedate,token,30);

                                }
                            else if (i==4)
                                {
                                    copy(update[x].status,token,30);

                                }

                        }

                        token = strtok(NULL, ":");
                        i++;
                    }
            x++;
        }
    fclose(f);

    f=fopen("data.txt","w");
    fprintf(f,"taskname:category:duedate:status:END");
    y=1;
    while(y!=x)
        {
            fprintf(f,"\n%s:%s:%s:%s:END",update[y].taskname,update[y].category,update[y].duedate,update[y].status);
            y++;
        }
    fclose(f);
    printf("Data has modified\n");
}

void deletetask(){
    system("cls");
    struct task deletes[100];
    int no=0,check;
    char str[100];
    int i,x,y;
    FILE*f;
    f=fopen("data.txt","r");
    check = 0;
    while(!feof(f))
        {
            fgets(str,sizeof str,f);
            check++;
        }
    fclose(f);

    while (no>check-1 || no<1)
        {
            printf("ENTER TASK_NO:");
            scanf("%d",&no);
            if (no>check-1 || no<1)
                {
                    printf("Invalid Input\n");
                }
            Sleep(1000);
            system("cls");
            fflush(stdin);
        }

    f=fopen("data.txt","r");
    x=0;
    while(!feof(f))
        {
            fgets(str,sizeof str,f);
            char*token = strtok(str,":");
            i=1;
            while(token != NULL)
                {

                    if (i==1)
                        {
                            copy(deletes[x].taskname,token,30);
                        }
                    else if (i==2)
                        {
                            copy(deletes[x].category,token,30);

                        }
                    else if (i==3)
                        {
                            copy(deletes[x].duedate,token,30);

                        }
                    else if (i==4)
                        {
                            copy(deletes[x].status,token,30);

                        }
                    token = strtok(NULL, ":");
                    i++;
                }
            x++;
        }


    fclose(f);

    f=fopen("data.txt","w");
    fprintf(f,"taskname:category:duedate:status:END");
    y=1;
    while(y!=x)
        {
            if (y!=no)
                {
                    fprintf(f,"\n%s:%s:%s:%s:END",deletes[y].taskname,deletes[y].category,deletes[y].duedate,deletes[y].status);
                }

            y++;
        }
    fclose(f);
    printf("Task Deleted\n");
}
