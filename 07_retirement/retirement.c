#include <stdio.h>
#include <stdlib.h>

struct _retire_info {
  int months;
  double contribution;
  double  rate_of_return;
};
typedef struct _retire_info retire_info;


double compute_balance(double balance, double rate, double contribution){
  return balance*(1+rate/12)+contribution;
}

void retirement (int startAge,   //in months
		 double initial, //initial savings in dollars
		 retire_info working, //info about working
		 retire_info retired){//info about being retired


  for (int i=0; working.months <i; i++){
    printf("Age %3d month %2d you have $%.2lf\n", (startAge/12), (startAge%12), (initial));
    startAge++;
    initial = compute_balance(initial, working.rate_of_return, working.contribution);
  }
  for (int i=0; retired.months <i; i++){
    printf("Age %3d month %2d you have $%.2lf\n", (startAge/12), (startAge%12), (initial));
    startAge++;
    initial = compute_balance(initial, retired.rate_of_return, retired.contribution);
  }
  return ;
}

int main () {
  retire_info working;
  working.months=489;
  working.contribution=1000;
  working.rate_of_return=0.045/12;
  retire_info retired;

  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01 / 12.0;
  retirement(327, 21345.0, working, retired);
  return EXIT_SUCCESS;
}

