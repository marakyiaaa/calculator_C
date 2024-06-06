#include "s21_smartcalc.h"

void credit_calc_ann(double summa, int period, double stake,
                     double *monthly_pay, double *over_pay, double *total_pay) {
  double monthly_stake = 0.0;
  monthly_stake = stake / 12.0 / 100.0;

  double dop_calculation = 0.0;
  dop_calculation = pow(1.0 + monthly_stake, period);

  double coefficient = 0.0;
  coefficient = monthly_stake * dop_calculation / (dop_calculation - 1.0);

  *monthly_pay = round((summa * coefficient) * 100.0) / 100.0;
  *over_pay = (*monthly_pay * period) - summa;
  *total_pay = (*monthly_pay) * period;
}

void credit_diff(double summa, int period, double stake, double *over_pay,
                 double *total_pay, double *first_pay, double *last_pay) {
  double mon_added_rate = 0.0;
  double mon_pay_with_rate = 0.0;

  double diff_month_pay = 0.0;
  diff_month_pay = summa / period;

  *last_pay = diff_month_pay;

  for (int i = 0; i < period; i++) {
    mon_added_rate = (summa - (diff_month_pay * i)) * stake / 100.0 / 12.0;
    mon_pay_with_rate = diff_month_pay + mon_added_rate;
    if (i == 0) *first_pay = mon_pay_with_rate;
    *total_pay += mon_pay_with_rate;
  }
  *over_pay = *total_pay - summa;
}