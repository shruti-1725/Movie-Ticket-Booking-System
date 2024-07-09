#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


struct booking_details
{
	char movie[30];
	char movie_time[5];
	char name[25];
	int phone;
	int seat;
	int ticket_price;
	int id;
};


struct booking_details person[300] = {0};
char movie_names[][20] = {"Tiger 3", "Dunki", "Animal", "Fighter"};
char movie_timings[][2][5]= {{"1:00", "6:30"}, {"3:30", "9:00"}, {"3:30", "6:30"}, {"1:30", "9:30"}};
float movie_rating[] = {3.5, 3.5, 3.5, 3.5};
int count = 0;


void clearScreen() 
{
    printf("\033[2J\033[H");
}


void display_line()
{
    printf("\n------------------------------------------------------------------------------------------------------------------------\n\n");
}


void display_movie_details()
{
	clearScreen();
    display_line();
	printf("\t\t\t\t\t\t\tMovie Details\n");
    display_line();
	int i;
    printf("\t\t\tMovie Name\t\t\tRatings\t\t\t\t   Timings\n");
    for (i = 0; i < 4; i++)
    {
        printf("\t\t\t%s\t\t\t\t  %.1f\t\t\t\t| %s | %s |\n", movie_names[i], movie_rating[i], movie_timings[i][0], movie_timings[i][1]);
    }
}


int movie()
{
	int i;
	char movie_name[30], movie_time[5]; int movie_num;
	clearScreen();
	display_line();
	printf("\t\t\t\t\t\tWhich movie do you want to see?\n");
	display_line(); 
	for (i = 0; i < 4; i++)
	{
		printf("\t\t\t\t\t\t   %d . %s\n", i+1, movie_names[i]);	
	}
	printf("\n\t\t\t\t  Enter the name of the movie you want to watch : ");
	scanf("%[^\n]s", movie_name);
	printf("\n");
	for (i = 0; i < 4; i++)
	{
		if (strcmp(movie_name, movie_names[i]) == 0)
		{
			movie_num = i;
			break;
		}
		else if(i ==  3)
		{
			display_line();
			printf("\n\t\t\t  This movie is not available. Please enter a movie from the above displayed options!!!\n\n");
			return 4;
		}
	}
	return movie_num;
}


int movie_timing(int movie_num)
{
	int i; int movie_ti; char movie_time[5];
	display_line();
	printf("\t\t\t\t\t\t\tTimings\n");
	display_line();
	printf("\n\t\t\t\t\tThe timings available for %s are : \n", movie_names[movie_num]);
	printf("\t\t\t\t\t\t\t%s\n", movie_timings[movie_num][0]);
	printf("\t\t\t\t\t\t\t%s\n\n", movie_timings[movie_num][1]);	
	printf("\t\t\t\t\tEnter the timing you want to choose : ");
	scanf("%s", &movie_time);
	printf("\n");
	for (i = 0; i < 2; i++)
	{
		if (strcmp(movie_time, movie_timings[movie_num][i]) == 0)
		{
			movie_ti = i;
			break;
		}
		else if(i == 1)
		{
			display_line();
			printf("\n\t\t\tThis movie timing is not available. Please enter a timing from the above displayed options!!!\n\n");
			return 4;
		}
	}
	clearScreen();
	return movie_ti;
}


void ticket_booking(int array[], int m_num, int n_time)
{       
	int price;
	strcpy(person[count].movie, movie_names[m_num]);
	strcpy(person[count].movie_time, movie_timings[m_num][n_time]);
	int i, seat;
	clearScreen();
	display_line();
	printf("\n\t\t\t\t\t\t\t   SCREEN\n\n");
	printf("\n\n\t\t");
	for (i = 1; i <= 100; i++)
	{
		if (array[i] == 0)
			printf("\t%d",i);
		else 
			printf("\t*",i);
		if(i % 10 == 0)
			printf("\n\n\t\t");
		if(i == 50)
			printf("\n\t\t");
		if(i == 80)
			printf("\n\t\t");
	}
	printf("\n");
	display_line();
	printf("\t\t\t\t\tPrice for Silver seats 1-50 = %d\n", 150);
	printf("\t\t\t\t\tPrice for Gold seats 51-80 = %d\n", 170);
	printf("\t\t\t\t\tPrice for Platinum seats 81-100 = %d\n", 200);
	printf("\n\t\t\t\t\tWhich seat number do you want? ");
	scanf("%d",&seat);
	if (seat>100||seat<1)
	{
		display_line();
		printf("\t\t\t\t\tSeat number is unavailable in this theater.\n");
		printf("\t\t\t\t\tPlease re-enter seat number: ");
		scanf("%d",&seat);
	}
	if (array[seat]==1)
	{
		display_line();
		printf("\t\t\t\t\tSorry, this ticket is already booked!!!\n");
		printf("\t\t\t\t\tPlease choose another seat : ");
		scanf("%d",&seat);
	}
	else			
		array[seat]=1;
	person[count].seat=seat;
	if (seat >= 1 && seat <= 50)
	{
		price = 150;
	}
	else if (seat > 50 && seat <= 80)
	{
		price = 170;
	}
	else
	{
		price = 200;
	}
	clearScreen();
	srand(time(NULL));
	int random1 = rand()%1000;
	int random2 = rand()%1000;
	person[count].id = random1 + random2;
	display_line();
	printf("\t\t\t\t\t\tBooking Details\n");
	display_line();
	printf("Your booking ID is (you will require this ID in case you want to cancel your order!!!) : %d\n", person[count].id) ;
	printf("Please enter your name: ");
	getchar();
	scanf("%[^\n]s", &person[count].name);
	printf("Please enter your phone number: ");
	getchar();
	scanf("%u",&person[count].phone);
	clearScreen();
	display_line();
	printf("\t\t\t\t\t\tMovie Ticket Reservation\n");
	display_line();
	printf("\t\t\t\t\t\tMovie Name : %s\n", person[count].movie);
	printf("\t\t\t\t\t\tMovie Timing : %s\n", person[count].movie_time);
	printf("\t\t\t\t\t\tSeat Number : %d\n", person[count].seat);
	printf("\t\t\t\t\t\tBooking ID : %d\n", person[count].id);
	printf("\t\t\t\t\t\tTicket Price : %d\n", price);
	printf("\t\t\t\t\t\tName of Customer : %s\n", person[count].name);
}

int cancelling_ticket()
{
	clearScreen();
	char movie[20], name[20]; int id;
	display_line();
    printf("\t\t\t\t\t\tCancelling a booked ticket\n");
	display_line();
	printf("\t\t\t\tEnter the movie whose ticket you want to cancel : ");
	scanf("%[^\n]s", &movie);
	getchar();
	printf("\t\t\t\t\t\tEnter your name : ");
	scanf("%[^\n]s", &name);
	getchar();
	printf("\t\t\t\t\t\tEnter the booking ID : ");
	scanf("%d", &id);
	int i;
	for (i = 0; i < count; i++)
	{
		if (person[i].id == id && (strcmp(name, person[i].name) == 0) && (strcmp(movie, person[i].movie) == 0))
		{
			clearScreen();
			display_line();
			printf("\n\t\t\t\t\t\tTicket Cancellation\n");
			display_line();
			printf("\n");
			printf("\t\t\t\t\t\tMovie Name : %s\n", person[i].movie);
			printf("\t\t\t\t\t\tMovie Timings : %s\n", person[i].movie_time);
			printf("\t\t\t\t\t\tName : %s\n", person[i].name);
			printf("\t\t\t\t\t\tBooking ID : %d\n", id);
			person[i].id = 0;
			strcpy(person[i].name, "0");
			person[i].phone = 0;
			printf("\t\t\t\t\tTicket reservation cancelled succesfully!!!\n");
			return 0;
		}
	}
	printf("\n");
	display_line();
	printf("\n\t\t\t\tThere is no booking with ID %d with name %s for the movie %s!!!\n", id, name, movie);
	printf("\t\t\t\t\tPlease make sure to enter the CORRECT details!!!\n\n");
}


int rating()
{
	char movie[20]; int id;
	int i, j; float rating;
	clearScreen();
	display_line();
	printf("\t\t\t\t\t\t\tMovie Rating\n");
	display_line();
	printf("\n");
	printf("\t\t\t\t\tEnter the movie you want to rate : ");
	scanf("%[^\n]s", &movie);
	printf("\t\t\t\t\tEnter the Booking ID : ");
	getchar();
	scanf("%d", &id);
	for (i = 0; i < count; i++)
	{
		if (person[i].id == id && (strcmp(movie, person[i].movie) == 0))
		{
			clearScreen();
			display_line();
			printf("\t\t\t\t\t\t\tMovie Rating\n");
			display_line();
			printf("\n\t\t\t\t\t\t  Movie Name : %s\n", person[i].movie);
			printf("\t\t\t\t\t\t   Booking ID : %d\n", id);
			printf("\t\t\t\t\tEnter your rating for the movie (out of 5) : ");
			scanf("%f", &rating);
			for (j = 0; j < 4; j++)
			{
				if ((strcmp(movie, movie_names[j]) == 0))
				{
					movie_rating[j] = (movie_rating[j] + rating) / 2; 
				}	
			}
			return 0;
		}
	}
	printf("\n");
	display_line();
	printf("\n\t\t\t\t   There is no booking with ID %d for the movie %s!!!\n", id, movie);
	printf("\t\t\t\t   Please make sure to enter the CORRECT details!!!\n\n");
}


int main()
{
    int movie_selected, movie_time, i;
    int seat_movie0[2][101] = {0};
    int seat_movie1[2][101] = {0};
    int seat_movie2[2][101] = {0};
    int seat_movie3[2][101] = {0};
    int ch;
    while(1)
    {
        display_line();
        printf("\t\t\t\t\t\t\t  WELCOME\n");
		display_line();
		printf("\n");
        printf("\t\t\t\t\t\t1. Display movie details\n");
        printf("\t\t\t\t\t\t2. Book a ticket\n");
        printf("\t\t\t\t\t\t3. Cancel a booked ticket\n");
        printf("\t\t\t\t\t\t4. Rate a movie\n");
        printf("\t\t\t\t\t\t0. To Exit\n\n");
        printf("\t\t\t\t\t\tEnter your choice (1-4) : ");
        scanf("%d", &ch);
		getchar();
        display_line();
        if (ch == 1)
        {
            display_movie_details();
        }
        else if (ch == 2)
        {
			printf("\t\t\t\t\tBooking a ticket");
	   	    movie_selected = movie();
			if (movie_selected < 4)
			{
				movie_time = movie_timing(movie_selected);
			}
			if (movie_time < 4)
			{
				if (movie_selected == 0)
				{
					ticket_booking(seat_movie0[movie_time],movie_selected, movie_time);
				}
				else if (movie_selected == 1)
				{
					ticket_booking(seat_movie1[movie_time],movie_selected, movie_time);
				}
				else if (movie_selected == 2)
				{
					ticket_booking(seat_movie2[movie_time],movie_selected, movie_time);
				}
				else if (movie_selected == 3)
				{
					ticket_booking(seat_movie3[movie_time],movie_selected, movie_time);
				}
            	count++;
			}
        }
        else if (ch == 3)
        {
			cancelling_ticket();
        }
		else if (ch == 4)
		{
			rating();
		}
		else if (ch == 0)
		{
			break;
		}
		else
		{
			printf("Please enter a VALID choice!!!");
		}	
    }
    return 0;
}