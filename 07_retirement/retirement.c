 #include<stdio.h>
 #include<stdlib.h>

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

double compute_balance(double initial, double rate_of_return, double contribution)
{
  double balance = (initial*(1 +rate_of_return)) + contribution;
  return balance;
}

//For this problem, you will be writing a "retirement savings" calculator.
//We'll remove the effects of inflation by keeping everything in
//"today's dollars" and using a "Rate of return" that is in terms of
//"more than inflation."

//1. Create a file called "retirement.c".  Include the usual header
// files (stdlib.h and stdio.h) at the top.

//2. We're going to model both savings (while working) and expenditure
// (while retired).  It turns out that both of these require the
//same basic information, so we will make a struct to represent that.
// Declare a struct _retire_info which has three fields:
//  (1) an int called "months" for the number of months it is applicable to,
//(2) a double called "contribution" for how many dollars
//    are contributed (or spent if negative) from the account per month
//(3) a double called "rate_of_return" for the rate of returns
//  (which we will assume to be "after inflation").

//    After you have declared this struct, use typedef to make "retire_info"
//  another name for this struct.



// 3. Write the function


void retirement (int startAge, double initial,retire_info working, retire_info retired)

{
  int stage=startAge;
  int y_age= stage/12;
  double amt=initial;
  int m_age= stage%12;
  //in months //initial savings in dollars//info about working//info about being retired
  for (int i; working.months>i; ++i) {
    printf("Age %3d month %2d you have $%.2lf\n",y_age, m_age,amt);



    initial = compute_balance(initial, working.rate_of_return,working.contribution);

    stage++;
    y_age= stage / 12;
    m_age = stage % 12;

  }
  for (int j; retired.months > j; j++) {
    printf ("Age %3d month %2d you have $%.2lf\n",y_age, m_age,amt);


    initial = compute_balance(initial, retired.rate_of_return,retired.contribution);

    stage++;
    y_age= stage / 12;
    m_age = stage % 12;

  }
  return ;
}
int main() {
  retire_info working;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045 / 12.0;

  retire_info retired;
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01 / 12.0;

  retirement(327, 21345, working, retired);

  return 0;
}


// This function should perform two tasks (which are similar---look
//for a chance to abstract something out into a function!).

//First, it should compute your retirement account balance each
//month while you are working.  To do this, you need to calculate
//t/he account balance increase from returns (balance * rate of return),
//and add that to the current balance.  You then need to add the
//monthly contribution to the balance.
//For example, if you have $1,000 in the account, earn a 0.5% rate of
//return per month, and contribute $100 per month, you would
//cmopute 1000 * 0.005 = $5 in interest earned.  You would then
//add this plus the monthly contribution to the balance to end up
//with $1105 in the account at the end of the month.

//At the start of each month (before the balance chan//ges), you should
//print out the current balance with the following format:
//"Age %3d month %2d you have $%.2lf\n"
//The first two format conversions are the savers age in years and months.
//The third format conversion is the account balance
//This calculation goes on for the number of months specified
//   in the "working" retire_info structure.


// Second, you should perform a very similar calculation for each
//month of retirment.  The difference here is that you will use the
//information in the "retired" retire_info structure instead
// of the information in the "working" structure.  As with
// working, you should print out the same information as before.

//Hint: since you are performing a very similar computation,
//think about how you can abstract that part out into a function,
//and re-use it, rather than re-writing it]

// 4. Write a main function which computes the retirement assuming
//   Working:
// --------
//Months: 489
// Per Month Savings: $1000
// Rate of Return:  4.5% per year ( 0.045/12 per month)
//                 [above inflation]




