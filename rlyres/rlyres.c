#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"conio2.h"
#include"rlyres.h"
int enterchoice()
{
    clrscr();
    int i,choice;
    textcolor(10);
    gotoxy(48,1);
    printf("RAILWAY RESERVATION SYSTEM\n");
    for(i=1;i<=120;i++)
        printf("-");
    printf("\nSelect an option\n");
    printf("1- View Trains\n");
    printf("2- Book Ticket\n");
    printf("3- View Ticket\n");
    printf("4- Search Ticket No\n");
    printf("5- View All Booking\n");
    printf("6- View Train Bookings\n");
    printf("7- Cancel Ticket\n");
    printf("8- Cancel Train\n");
    printf("9- Quit\n");
    printf("\nEnter choice: ");
    scanf("%d",&choice);
    return choice;
}
void add_trains()
{
    FILE *fp=fopen("E:\\MyProject\\alltrains.dat","rb");
    if(fp==NULL)
    {
        Train alltrains[4]={
                {"123","BPL","GWA",2100,1500},
                {"546","BPL","NDLS",3500,2150},
                {"345","HBJ","AGR",1560,1135},
                {"896","HBJ","MUM",2800,1790},
        };
        fp=fopen("E:\\MyProject\\alltrains.dat","wb");
        fwrite(alltrains,4*sizeof(Train),1,fp);
        fclose(fp);
    }
    else
    {
        fclose(fp);
    }
}
void view_trains()
{
    int i;
    clrscr();
    printf("TRAIN NO\tFROM\tTO\tFIRST AC FAIR\tSECOND AC FAIR\n");
    for(i=1;i<=120;i++)
        printf("-");
    printf("\n\n\n");
    FILE *fp;
    fp=fopen("E:\\MyProject\\alltrains.dat","rb");
    Train alltrains[4];
    fread(alltrains,4*sizeof(Train),1,fp);
    for(i=0;i<4;i++)
    {
        printf("%s",alltrains[i].train_no);
        printf("\t\t%s",alltrains[i].from);
        printf("\t%s",alltrains[i].to);
        printf("\t%d",alltrains[i].fac_fare);
        printf("\t\t%d\n",alltrains[i].sac_fare);
    }
    fclose(fp);
    textcolor(WHITE);
    printf("\n\n\n\n\n\nPress any key to go back to the main screen");
    getch();
    clrscr();
}
int check_train_no(char* tno)
{
    FILE *fp;
    fp=fopen("E:\\MyProject\\alltrains.dat","rb");
    Train alltrains;
    while(fread(&alltrains,sizeof(Train),1,fp)==1)
    {
        if(strcmp(alltrains.train_no,tno)==0)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
Passenger* get_passenger_details()
{
    clrscr();
    gotoxy(100,1);
    textcolor(LIGHTGREEN);
    printf("Press 0 to exit");
    gotoxy(1,1);
    textcolor(10);
    static Passenger psn;
    printf("Enter passenger name: ");
    fflush(stdin);
    fgets(psn.p_name,30,stdin);
    char* pos;
    pos=strchr(psn.p_name,'\n');
    *pos='\0';
    if(strcmp(psn.p_name,"0")==0)
    {
        gotoxy(1,30);
        textcolor(LIGHTRED);
        printf("Reservation Cancelled!");
        textcolor(10);
        return NULL;
    }
    printf("Enter gender(M/F): ");
    while(1)
    {
        fflush(stdin);
        scanf("%c",&psn.gender);
        if(psn.gender=='M' || psn.gender=='F')
        {
            break;
        }
        else if(psn.gender=='0')
        {
            gotoxy(1,30);
            printf("\t\t\t\t\t\t\t\t\t\t");
            gotoxy(1,30);
            textcolor(LIGHTRED);
            printf("Reservation Cancelled.");
            textcolor(10);
            return NULL;
        }
        else
        {
            gotoxy(1,30);
            printf("\t\t\t\t\t\t\t\t\t\t");
            gotoxy(1,30);
            textcolor(LIGHTRED);
            printf("Error! Gender should be M or F(in uppercase)");
            textcolor(10);
            gotoxy(20,2);
            printf(" \b");
        }
    }
    gotoxy(1,30);
    printf("\t\t\t\t\t\t\t\t\t\t");
    gotoxy(1,3);
    printf("Enter train number: ");
    while(1)
    {
        fflush(stdin);
        fgets(psn.train_no,20,stdin);
        char* pos;
        pos=strchr(psn.train_no,'\n');
        *pos='\0';
        if(strcmp(psn.train_no,"0")==0)
        {
            gotoxy(1,30);
            printf("\t\t\t\t\t\t\t\t\t\t");
            gotoxy(1,30);
            textcolor(LIGHTRED);
            printf("Reservation Cancelled.");
            textcolor(10);
            return NULL;
        }
        if(check_train_no(psn.train_no))
        {
            break;
        }
        else
        {
            gotoxy(1,30);
            printf("\t\t\t\t\t\t\t\t\t\t");
            gotoxy(1,30);
            textcolor(LIGHTRED);
            printf("Error! Invalid Train No");
            textcolor(10);
            gotoxy(21,3);
            printf("             \b\b\b\b\b\b\b\b\b\b\b\b\b");
        }
    }
    gotoxy(1,30);
    printf("\t\t\t\t\t\t\t\t\t\t");
    gotoxy(1,4);
    printf("Enter traveling class(First AC-F,Second AC-S): ");
    while(1)
    {
        fflush(stdin);
        scanf("%c",&psn.p_class);
        if(psn.p_class=='S' || psn.p_class=='F')
        {
            break;
        }
        else if(psn.p_class=='0')
        {
            gotoxy(1,30);
            printf("\t\t\t\t\t\t\t\t\t\t");
            gotoxy(1,30);
            textcolor(LIGHTRED);
            printf("Reservation Cancelled.");
            textcolor(10);
            return NULL;
        }
        else
        {
            gotoxy(1,30);
            printf("\t\t\t\t\t\t\t\t\t\t");
            gotoxy(1,30);
            textcolor(LIGHTRED);
            printf("Error! Traveling Class should be F or S(in uppercase)");
            textcolor(10);
            gotoxy(48,4);
            printf(" \b");
        }
    }
    gotoxy(1,30);
    printf("\t\t\t\t\t\t\t\t\t\t");
    gotoxy(1,5);
    printf("Enter address: ");
    fflush(stdin);
    fgets(psn.address,30,stdin);
    pos=strchr(psn.address,'\n');
    *pos='\0';
    if(strcmp(psn.address,"0")==0)
    {
        gotoxy(1,30);
        printf("\t\t\t\t\t\t\t\t\t\t");
        gotoxy(1,30);
        textcolor(LIGHTRED);
        printf("Reservation Cancelled.");
        textcolor(10);
        return NULL;
    }
    printf("Enter age: ");
    while(1)
    {
        fflush(stdin);
        scanf("%d",&psn.new_age);
        if(psn.new_age==0)
        {
            gotoxy(1,30);
            printf("\t\t\t\t\t\t\t\t\t\t");
            gotoxy(1,30);
            textcolor(LIGHTRED);
            printf("Reservation Cancelled.");
            textcolor(10);
            return NULL;
        }
        else if(psn.new_age<0)
        {
            gotoxy(1,30);
            printf("\t\t\t\t\t\t\t\t\t\t");
            gotoxy(1,30);
            textcolor(LIGHTRED);
            printf("Error! Age should be positive");
            textcolor(10);
            gotoxy(12,6);
            printf("     \b\b\b\b\b");
        }
        else
        {
            break;
        }
    }
    gotoxy(1,30);
    printf("\t\t\t\t\t\t\t\t\t\t");
    gotoxy(1,7);
    printf("Enter Mobile No: ");
    while(1)
    {
        fflush(stdin);
        fgets(psn.mob_no,12,stdin);
        char* pos;
        pos=strchr(psn.mob_no,'\n');
        if(pos!=NULL)
        *pos='\0';
        if(strcmp(psn.mob_no,"0")==0)
        {
            gotoxy(1,30);
            printf("\t\t\t\t\t\t\t\t\t\t");
            gotoxy(1,30);
            textcolor(LIGHTRED);
            printf("Reservation Cancelled.");
            textcolor(10);
            return NULL;
        }
        if(check_mob_no(psn.mob_no))
        {
            break;
        }
        else
        {
            gotoxy(1,30);
            printf("\t\t\t\t\t\t\t\t\t\t");
            gotoxy(1,30);
            textcolor(LIGHTRED);
            printf("Error! Invalid Mobile No");
            textcolor(10);
            gotoxy(18,7);
            printf("            \b\b\b\b\b\b\b\b\b\b\b\b");
        }
    }
    gotoxy(1,30);
    printf("\t\t\t\t\t\t\t\t\t\t");
    gotoxy(1,8);
    return &psn;
}
int check_mob_no(char* mob_no)
{
    if(strlen(mob_no)!=10)
    {
        return 0;
    }
    while(*mob_no!='\0')
    {
        if(isdigit(*mob_no)==0)
        {
            return 0;
        }
        mob_no++;
    }
    return 1;
}

int get_booked_ticket_count(char* train_no ,char t_class)
{
    FILE *fp=fopen("E:\\MyProject\\allbookings.dat","rb");
    if(fp==NULL)
    {
        return 0;
    }
    Passenger pr;
    int count=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.train_no,train_no)==0 && pr.p_class==t_class)
            ++count;
    }
    fclose(fp);
    return count;
}
int last_ticket_no()
{
    FILE *fp=fopen("E:\\MyProject\\allbookings.dat","rb");
    if(fp==NULL)
    {
        return 0;
    }
    Passenger pr;
    fseek(fp,-1*sizeof(Passenger),SEEK_END);
    fread(&pr,sizeof(Passenger),1,fp);
    fclose(fp);
    return pr.ticket_no;
}
int book_ticket(Passenger p)
{
    if(get_booked_ticket_count(p.train_no,p.p_class)==30)
    {
        gotoxy(1,20);
        textcolor(LIGHTRED);
        printf("All seats full in train no %s in %c class!",p.train_no,p.p_class);
        return -1;
    }
    p.ticket_no=last_ticket_no()+1;
    FILE *fp=fopen("E:\\MyProject\\allbookings.dat","ab");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("Sorry! File cannot be opened");
        return -1;
    }
    fwrite(&p,sizeof(Passenger),1,fp);
    fclose(fp);
    return p.ticket_no;
}
int accept_ticket_no()
{
    clrscr();
    int ticket_no;
    gotoxy(100,1);
    textcolor(LIGHTGREEN);
    printf("Press 0 to exit");
    gotoxy(1,1);
    textcolor(10);
    printf("Enter ticket number: ");
    while(1)
    {
        scanf("%d",&ticket_no);
        if(ticket_no==0)
        {
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Cancelling Input..!");
            return 0;
        }
        if(ticket_no<0)
        {
            gotoxy(1,30);
            textcolor(LIGHTRED);
            printf("Error! Ticket number should be positive");
            textcolor(10);
            gotoxy(22,1);
            printf("   \b\b\b");
        }
        else
        {
            break;
        }
    }
    return ticket_no;
}
char* accept_train_no()
{
    clrscr();
    static char train_no[20];
    gotoxy(100,1);
    textcolor(LIGHTGREEN);
    printf("Press 0 to exit");
    gotoxy(1,1);
    textcolor(10);
    printf("Enter train number: ");
    while(1)
    {
        fflush(stdin);
        fgets(train_no,20,stdin);
        char* pos;
        pos=strchr(train_no,'\n');
        *pos='\0';
        if(strcmp(train_no,"0")==0)
        {
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Cancelling Input..!");
            return NULL;
        }
        if(check_train_no(train_no))
        {
            break;
        }
        else
        {
            gotoxy(1,30);
            textcolor(LIGHTRED);
            printf("Error! Invalid Train No");
            textcolor(10);
            gotoxy(21,1);
            printf("      \b\b\b\b\b\b");
        }
    }
    return train_no;
}
int cancel_train(char* train_no)
{
    FILE *fp1=fopen("E:\\MyProject\\allbookings.dat","rb");
    if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNo bookings done yet");
        return -1;
    }
    FILE *fp2=fopen("E:\\MyProject\\temp.dat","wb");
    Passenger pr;
    int found=0;
    while(fread(&pr,sizeof(pr),1,fp1)==1)
    {
        if(strcmp(pr.train_no,train_no)!=0)
        {
            fwrite(&pr,sizeof(pr),1,fp2);
        }
        else
        {
            found=1;
        }
    }
    fclose(fp1);
    fclose(fp2);
    if(found)
    {
        remove("E:\\MyProject\\allbookings.dat");
        rename("E:\\MyProject\\temp.dat","E:\\MyProject\\allbookings.dat");
    }
    else
    {
        remove("E:\\MyProject\\temp.dat");
    }
    return found;
}
void view_ticket(int tno)
{
    FILE *fp=fopen("E:\\MyProject\\allbookings.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNo bookings done yet");
        return;
    }
    Passenger pr;
    int found=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(pr.ticket_no==tno)
        {
            printf("Ticket no: %d",pr.ticket_no);
            printf("\nPassenger name: %s",pr.p_name);
            printf("\nTrain no: %s",pr.train_no);
            printf("\nGender: %c",pr.gender);
            printf("\nAddress: %s",pr.address);
            printf("\nMobile no: %s",pr.mob_no);
            printf("\nAge: %d",pr.new_age);
            printf("\nTravelling class: %c\n\n",pr.p_class);
            found=1;
            break;
        }
    }
    fclose(fp);
    if(!found)
    {
        gotoxy(1,1);
        textcolor(LIGHTRED);
        printf("No details of ticket no %d found",tno);
        textcolor(10);
    }
}
void view_all_bookings()
{
    clrscr();
    FILE *fp=fopen("E:\\MyProject\\allbookings.dat","rb");
    if(fp==NULL)
    {
        gotoxy(1,4);
        textcolor(LIGHTRED);
        printf("Error! No bookings performed yet.");
        getch();
        textcolor(10);
        return;
    }
    printf("TICKET NO");
    gotoxy(14,1);
    printf("TRAIN NO");
    gotoxy(26,1);
    printf("PASSENGER NAME");
    gotoxy(45,1);
    printf("GENDER");
    gotoxy(55,1);
    printf("ADDRESS");
    gotoxy(75,1);
    printf("MOBILE NO");
    gotoxy(90,1);
    printf("AGE");
    gotoxy(100,1);
    printf("TRAVELLING CLASS\n");
    int i;
    for(i=1;i<=120;i++)
        printf("-");
    Passenger pr;
    i=3;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        printf("%d",pr.ticket_no);
        gotoxy(14,i);
        printf("%s",pr.train_no);
        gotoxy(26,i);
        printf("%s",pr.p_name);
        gotoxy(45,i);
        printf("%c",pr.gender);
        gotoxy(55,i);
        printf("%s",pr.address);
        gotoxy(75,i);
        printf("%s",pr.mob_no);
        gotoxy(90,i);
        printf("%d",pr.new_age);
        gotoxy(100,i);
        printf("%c\n",pr.p_class);
        i++;
    }
    textcolor(WHITE);
    printf("\n\n\n\n\n\nPress any key to go back to the main screen");
    fclose(fp);
    getch();
}
void view_bookings(char* tr_no)
{
    FILE *fp=fopen("E:\\MyProject\\allbookings.dat","rb");
    if(fp==NULL)
    {
        clrscr();
        textcolor(LIGHTRED);
        printf("\nNo bookings done yet");
        textcolor(WHITE);
        printf("\n Press any key to go back to the main menu");
        getch();
        return;
    }
    gotoxy(1,1);
    printf("TICKET NO");
    gotoxy(14,1);
    printf("TRAIN NO");
    gotoxy(26,1);
    printf("PASSENGER NAME");
    gotoxy(45,1);
    printf("GENDER");
    gotoxy(55,1);
    printf("ADDRESS");
    gotoxy(75,1);
    printf("MOBILE NO");
    gotoxy(90,1);
    printf("AGE");
    gotoxy(100,1);
    printf("TRAVELLING CLASS\n");
    int i;
    for(i=1;i<=120;i++)
        printf("-");
    Passenger pr;
    int check=0;
    i=3;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.train_no,tr_no)==0)
        {
            check=1;
            printf("%d",pr.ticket_no);
            gotoxy(14,i);
            printf("%s",pr.train_no);
            gotoxy(26,i);
            printf("%s",pr.p_name);
            gotoxy(45,i);
            printf("%c",pr.gender);
            gotoxy(55,i);
            printf("%s",pr.address);
            gotoxy(75,i);
            printf("%s",pr.mob_no);
            gotoxy(90,i);
            printf("%d",pr.new_age);
            gotoxy(100,i);
            printf("%c\n",pr.p_class);
            i++;
        }
    }
    if(check==0)
    {
        int i;
        for(i=1;i<=120;i++)
        {
            gotoxy(i,1);
            printf(" \b");
            gotoxy(i,2);
            printf(" \b");
        }
        gotoxy(1,1);
        textcolor(LIGHTRED);
        printf("No details of train no %s found",tr_no);
        textcolor(10);
    }
    textcolor(WHITE);
    printf("\n\n\n\n\n\nPress any key to go back to the main screen");
    getch();
    fclose(fp);
}
void search_record(char* mob_no)
{
    FILE *fp=fopen("E:\\MyProject\\allbookings.dat","rb");
    Passenger pr;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.mob_no,mob_no)==0)
        {
            printf("\nTicket no: %d",pr.ticket_no);
            printf("\nPassenger name: %s",pr.p_name);
            printf("\nTrain no: %s",pr.train_no);
            printf("\nGender: %c",pr.gender);
            printf("\nAddress: %s",pr.address);
            printf("\nMobile no: %s",pr.mob_no);
            printf("\nAge: %d",pr.new_age);
            printf("\nTravelling class: %c",pr.p_class);
            textcolor(WHITE);
            printf("\n\n\n\n\n\nPress any key to go back to the main screen");
            getch();
            fclose(fp);
            return;
        }
    }
    fclose(fp);
    gotoxy(1,4);
    textcolor(LIGHTRED);
    printf("Error! No booking on this number");
    textcolor(10);
    getch();
}
int cancel_ticket(int ticket_no)
{
    FILE *fp1=fopen("E:\\MyProject\\allbookings.dat","rb");
    if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNo bookings done yet");
        return -1;
    }
    FILE *fp2=fopen("E:\\MyProject\\temp.dat","wb");
    Passenger pr;
    int found=0;
    while(fread(&pr,sizeof(pr),1,fp1)==1)
    {
        if(pr.ticket_no!=ticket_no)
        {
            fwrite(&pr,sizeof(pr),1,fp2);
        }
        else
        {
            found=1;
        }
    }
    fclose(fp1);
    fclose(fp2);
    if(found)
    {
        remove("E:\\MyProject\\allbookings.dat");
        rename("E:\\MyProject\\temp.dat","E:\\MyProject\\allbookings.dat");
    }
    else
    {
        remove("E:\\MyProject\\temp.dat");
    }
    return found;
}
char* accept_mob_no()
{
    static char mob_no[12];
    char *pos;
    gotoxy(100,1);
    textcolor(LIGHTGREEN);
    printf("Press 0 to exit");
    gotoxy(1,1);
    textcolor(10);
    printf("Enter mobile number: ");
    while(1)
    {
        fflush(stdin);
        fgets(mob_no,12,stdin);
        pos=strchr(mob_no,'\n');
        *pos='\0';
        if(strcmp(mob_no,"0")==0)
        {
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Cancelling Input..!");
            textcolor(10);
            return NULL;
        }
        if(check_mob_no(mob_no))
        {
            break;
        }
        else
        {
            gotoxy(1,30);
            textcolor(LIGHTRED);
            printf("Error! Invalid Mobile No");
            textcolor(10);
            gotoxy(22,1);
            printf("            \b\b\b\b\b\b\b\b\b\b\b\b");
        }
    }
    return mob_no;
}
int* get_ticket_no(char* mob_no)
{
    int count=0;
    FILE *fp=fopen("E:\\MyProject\\allbookings.dat","rb");
    if(fp==NULL)
    {
        return NULL;
    }
    Passenger pr;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.mob_no,mob_no)==0)
            ++count;
    }
    if(count==0)
    {
        fclose(fp);
        return NULL;
    }
    rewind(fp);
    int *p=(int*)malloc((count+1)*sizeof(int));
    int i=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.mob_no,mob_no)==0)
        {
            *(p+i)=pr.ticket_no;
            i++;
        }
    }
    *(p+i)=-1;
    fclose(fp);
    return p;
}
void view_all_tickets(char* mob_no,int* ticket_no)
{
    if(ticket_no==NULL)
    {
        textcolor(LIGHTRED);
        printf("Sorry! No tickets booked against mobile no %s",mob_no);
        return;
    }
    clrscr();
    printf("Following are tickets booked for mobile no %s",mob_no);
    int i;
    printf("\n\nTICKET NO\n---------");
    for(i=0;*(ticket_no+i)!=-1;i++)
        printf("\n%d",*(ticket_no+i));
}
