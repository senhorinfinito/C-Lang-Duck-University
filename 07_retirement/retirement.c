 #include<stdio.h>
 #include<stdlib.h>

 struct _retire_info
 {
   int months;
   double contribution;
   double rate_of_return;
 };
typedef struct _retire_info retire_info;

double compute_balance(double balance , double rate_of_return, double contribution)
{
  return balance*(1 +rate_of_return/12)+ contribution;
}
void retirement (int startAge, double initial, retire_info working, retire_info retired)
{
  for (int i=0; i < working.months; i++) {
    printf("Age %3d month %2d you have $%.2lf\n",(startAge/12),(startAge%12),initial);
    startAge++;
    initial = compute_balance(initial, working.rate_of_return, working.contribution);

  }
  for (int j=0; j < retired.months; j++)
    {
      printf("Age %3d month %2d you have $%.2lf\n",(startAge/12),(startAge%12),initial);
      startAge++;
      initial = compute_balance(initial, retired.rate_of_return,retired.contribution);

    }
}
int main() {
  retire_info Working= {489,1000,0.045};
  retire_info Retired= {384,-4000,0.01};
  retirement(327,21345,Working,Retired);
  return EXIT_SUCCESS;
}


