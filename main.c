#include <stdio.h>
#include<time.h>

void current_date()
{
    time_t current_date = time(NULL);

    char date_string[20];
    strftime(date_string, 20, " %Y-%m-%d", localtime(&current_date));   //strftime function to format the current time into a string /// The localtime function is used to convert the current_time value (in seconds) into a struct tm structure representing the local time.

    printf("\t\t%s\t\t\t", date_string);

}

void current_time()
{
    time_t s, val = 1;
    struct tm* current_time;

    s = time(NULL);

    current_time = localtime(&s);

    printf("%d:%d:%d\n",current_time->tm_hour,current_time->tm_min,current_time->tm_sec);
}
int main()
{
  printf("\t\t\t ****** CASH RECEIPT ******\n");
  printf("\t\t Address: Inhan-12 gil, Bongchondong, Naksandae\n");
  printf("\t\t Telephone: 010--------\n");

  printf("\t---------------------------------------------------------------------\n");


  current_date();      //function to print current date
  current_time();      //function to print current time
  printf("\t---------------------------------------------------------------------\n");
}

