#include<stdio.h>
#include<stdlib.h>
#include"conio2.h"
#include"rlyres.h"
int main()
{
    add_trains();
    int choice;
    Passenger *ptr;
    int result;
    int tckt_no;
    char* mob_no;
    char* tno;
    int* ticket_no;
    while(1)
    {
        choice=enterchoice();
        if(choice==9)
        {
            exit(0);
        }
        else
        {
            switch(choice)
            {
            case 1:
                {
                    view_trains();
                    break;
                }
            case 2:
                {
                    clrscr();
                    ptr=get_passenger_details();
                    if(ptr!=NULL)
                    {
                        tckt_no=book_ticket(*ptr);
                        if(tckt_no==-1)
                        {
                            printf("\nBooking Failed");
                            textcolor(10);
                        }
                        else
                        {
                            gotoxy(1,20);
                            textcolor(LIGHTGREEN);
                            clrscr();
                            printf("Ticket successfully booked\n");
                            printf("Ticket no: %d",tckt_no);
                            textcolor(WHITE);
                            printf("\n\n\n\n\n\n\Press any key to go back to the main screen");
                            textcolor(10);
                        }
                    }
                    getch();
                    break;
                }
            case 3:
                {
                    tckt_no=accept_ticket_no();
                    if(tckt_no!=0)
                    {
                        clrscr();
                        view_ticket(tckt_no);
                    }
                    textcolor(WHITE);
                    printf("\n\n\n\n\nPress any key to go back to the main screen");
                    getch();
                    break;
                }
            case 4:
                {
                    clrscr();
                    mob_no=accept_mob_no();
                    if(mob_no!=NULL)
                    {
                        clrscr();
                        ticket_no=get_ticket_no(mob_no);
                        view_all_tickets(mob_no,ticket_no);
                    }
                    textcolor(WHITE);
                    printf("\n\n\n\n\nPress any key to go back to the main screen");
                    getch();
                    break;
                }
            case 5:
                {
                    view_all_bookings();
                    break;
                }
            case 6:
                {
                    tno=accept_train_no();
                    if(tno==NULL)
                    {
                        textcolor(WHITE);
                        printf("\n\n\n\n\nPress any key to go back to the main menu");
                        getch();
                    }
                    else
                    {
                        clrscr();
                        view_bookings(tno);
                    }
                    break;
                }
            case 7:
                {
                    clrscr();
                    tckt_no=accept_ticket_no();
                    if(tckt_no!=0)
                    {
                        result=cancel_ticket(tckt_no);
                        clrscr();
                        if(result==0)
                        {
                            textcolor(LIGHTRED);
                            printf("Sorry!No tickets booked against ticket no %d",tckt_no);
                        }
                        else if(result==1)
                        {
                            textcolor(LIGHTGREEN);
                            printf("Ticket no %d successfully cancelled!",tckt_no);
                        }
                    }
                    if(tckt_no==0)
                        printf("\n\n\n");
                    textcolor(WHITE);
                    printf("\n\nPress any key to go back to the main screen");
                    getch();
                    break;
                }
            case 8:
                {
                    clrscr();
                    tno=accept_train_no();
                    if(tno!=NULL)
                    {
                        result=cancel_train(tno);
                        clrscr();
                        if(result==0)
                        {
                            textcolor(LIGHTRED);
                            printf("Sorry!No tickets booked on train no %s",tno);
                        }
                        else if(result==1)
                        {
                            textcolor(LIGHTGREEN);
                            printf("Train no %s successfully cancelled!",tno);
                        }
                    }
                    if(tno==NULL)
                        printf("\n\n\n");
                    textcolor(WHITE);
                    printf("\n\nPress any key to go back to the main screen");
                    getch();
                    break;
                }
            default:
                {
                    textcolor(LIGHTRED);
                    printf("\n\nWrong Choice!Try Again");
                    getch();
                    clrscr();
                    break;
                }
            }
        }
    }
    return 0;
}
