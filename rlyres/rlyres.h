#ifndef RLYRES_H_INCLUDED
#define RLYRES_H_INCLUDED
struct Train
{
    char train_no[10];
    char from[10];
    char to[10];
    int fac_fare;
    int sac_fare;
};
struct Passenger
{
    char p_name[30];
    char gender;
    char address[30];
    char mob_no[11];
    int age;
    char train_no[20];
    char p_class;
    int ticket_no;
    int new_age;
};
typedef struct Train Train;
typedef struct Passenger Passenger;
int enterchoice();
int accept_ticket_no();
char* accept_mob_no();
char* accept_train_no();
void view_all_tickets(char*,int*);
void add_trains();
void view_trains();
int check_mob_no(char*);
int book_ticket(Passenger);
int* get_ticket_no(char*);
void view_ticket(int);
void view_all_bookings();
void view_bookings(char*);
int cancel_ticket(int);
int cancel_train(char*);
int check_train_no(char*);
Passenger* get_passenger_details();
int get_booked_ticket_count(char *,char);
int last_ticket_no();

#endif // RLYRES_H_INCLUDED
