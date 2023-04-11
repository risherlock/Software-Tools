/**
 * @brief Command line tool for "Anno Domini" and "Bikram Sambat" calenders.
 * @author Rishav
 * @date 2023-04-11
 **/

#include <stdio.h>
#include <math.h>

const char *months_string[] =
    {"January", "February", "March", "April", "May", "June",
     "July", "August", "September", "October", "November", "December"};

unsigned long util_floor(const double x);
void display_month(const unsigned long year, const char m);
char get_days_in_month(const unsigned long year, const char m);
void display_calender(const unsigned long year, const char month, const char max_days, const char start_day);
char date_to_day(const unsigned long year, const char month, const char day);

int main()
{
  for (char i = 0; i < 12; i++)
  {
    display_month(2023, i);
    printf("\r\n");
  }
  return 0;
}

void display_calender(const unsigned long year, const char month, const char max_days, const char start_day)
{
  char space = round(0.5 * (15 - sizeof(months_string[month])));
  for (char i = 0; i < space; i++)
  {
    printf(" ");
  }

  printf("%s %lu\r\n", months_string[month], year);
  printf("Su Mo Tu We Th Fr Sa\r\n");

  char i = 0;
  for (i; i < start_day; i++)
  {
    printf("   ");
  }

  char days = 1;
  while (1)
  {
    for (char j = i; j < 7 && days <= max_days; j++)
    {
      if (days >= 10)
      {
        printf("%d ", days);
      }
      else
      {
        printf(" %d ", days);
      }
      days++;
    }
    i = 0;
    printf("\r\n");

    if (days > max_days)
    {
      break;
    }
  }
}

char date_to_day(const unsigned long year, const char month, const char day)
{
  const char q = day;
  const unsigned long J = floor(year / 100);
  const unsigned long K = year % 100;
  char m;
  if (month > 1)
  {
    m = m + 1;
  }
  else
  {
    m = m + 13;
  }

  return (q + K + -2 * J +
          util_floor(13.0f * (m + 1) / 5.0f) +
          util_floor(K / 4.0f) +
          util_floor(J / 4.0f)) %
         7;
}

void display_month(const unsigned long year, const char month)
{
  const char start_day = date_to_day(year, month, 0);
  const char max_days = get_days_in_month(year, month);
  display_calender(year, month, max_days, start_day);
}

char get_days_in_month(const unsigned long year, const char m)
{
  char output = 0;
  if (m != 1)
  {
    switch (m)
    {
    case 0:
    case 2:
    case 4:
    case 6:
    case 7:
    case 9:
    case 11:
    {
      output = 30;
      break;
    }

    case 3:
    case 5:
    case 8:
    case 10:
    {
      output = 30;
      break;
    }
    }
  }
  else
  {
    /* Check leap year */
    char leap_flag = !(year % 4) && (year % 100) || !(year % 400);
    if (!leap_flag)
    {
      output = 28;
    }
    else
    {
      output = 29;
    }
  }
  return output;
}

unsigned long util_floor(const double x)
{
  return (unsigned long)x;
}
