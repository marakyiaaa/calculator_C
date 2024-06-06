#include <check.h>

#include "s21_smartcalc.h"

// s21_stack
START_TEST(s21_test_stack_1) {
  int res = 0;
  STACK* stack = NULL;
  stack = push(stack, '+');
  stack = push(stack, '/');
  stack = push(stack, '*');
  while (stack != NULL) {
    stack = pop(stack);
  }
  clear_stack(stack);
  ck_assert_int_eq(res, 0);
}
END_TEST

// s21_queue
START_TEST(s21_test_queue_1) {
  int res = 0;
  pointers queue;
  initQueue(&queue);
  push_queue(&queue, '1');
  push_queue(&queue, '+');
  push_queue(&queue, '2');
  push_queue(&queue, '*');
  // show_queue(queue);
  ck_assert_int_eq(res, 0);
  clear_queue(&queue);
}
END_TEST

START_TEST(s21_test_queue_2) {
  int res = 0;
  pointers queue;
  initQueue(&queue);
  push_queue(&queue, '5');
  push_queue(&queue, '+');
  push_queue(&queue, '-');
  push_queue(&queue, '*');
  while (queue.front != NULL) {
    pop_queue(&queue);
  }
  ck_assert_int_eq(res, 0);
  clear_queue(&queue);
}
END_TEST

// polish_nat
START_TEST(s21_test_polish_1) {
  int res = 0;
  STACK* stack = NULL;
  char output[50] = {0};
  char input[] = "-2.2*(-7+4.5^2)+4.2";
  char result[] = "0 2.2 - 0 7 - 4.5 2 ^ + * 4.2 + ";
  convert_to_rpn(input, &stack, output, 0.0);
  clear_stack(stack);
  ck_assert_int_eq(res, 0);
  ck_assert_str_eq(result, output);
}
END_TEST

START_TEST(s21_test_polish_2) {
  int res = 0;
  STACK* stack = NULL;
  char output[50] = {0};
  char input[] = "2-3*4.4+5";
  char result[] = "2 3 4.4 * - 5 + ";
  convert_to_rpn(input, &stack, output, 0.0);
  clear_stack(stack);
  ck_assert_int_eq(res, 0);
  ck_assert_str_eq(result, output);
}
END_TEST

START_TEST(s21_test_polish_3) {
  int res = 0;
  STACK* stack = NULL;
  char output[50] = {0};
  char input[] = "2.2*(7-4.5^2)+4.2^2*3";
  char result[] = "2.2 7 4.5 2 ^ - * 4.2 2 ^ 3 * + ";
  convert_to_rpn(input, &stack, output, 0.0);
  clear_stack(stack);
  ck_assert_int_eq(res, 0);
  ck_assert_str_eq(result, output);
}
END_TEST

START_TEST(s21_test_polish_4) {
  int res = 0;
  STACK* stack = NULL;
  char output[50] = {0};
  char input[] = "2.2*(7+4.5^2)+4.2";
  char result[] = "2.2 7 4.5 2 ^ + * 4.2 + ";
  convert_to_rpn(input, &stack, output, 0.0);
  clear_stack(stack);
  ck_assert_int_eq(res, 0);
  ck_assert_str_eq(result, output);
}
END_TEST

START_TEST(s21_test_polish_5) {
  int res = 0;
  STACK* stack = NULL;
  char output[50] = {0};
  char input[] = "2^2^3";
  char result[] = "2 2 ^ 3 ^ ";
  convert_to_rpn(input, &stack, output, 0.0);
  clear_stack(stack);
  ck_assert_int_eq(res, 0);
  ck_assert_str_eq(result, output);
}
END_TEST

START_TEST(s21_test_polish_6) {
  int res = 0;
  STACK* stack = NULL;
  char output[50] = {0};
  char input[] = "-1.1+2+(-4)";
  char result[] = "0 1.1 - 2 + 0 4 - + ";
  convert_to_rpn(input, &stack, output, 0.0);
  clear_stack(stack);
  ck_assert_int_eq(res, 0);
  ck_assert_str_eq(result, output);
}
END_TEST

// t_polish_x_1
START_TEST(s21_test_polish_x_1) {
  int res = 0;
  STACK* stack = NULL;
  char output[50] = {0};
  char input[] = "10-x";
  char result[] = "10 0.000000 - ";
  convert_to_rpn(input, &stack, output, 0.0);
  clear_stack(stack);
  ck_assert_int_eq(res, 0);
  ck_assert_str_eq(result, output);
}
END_TEST

START_TEST(s21_test_polish_x_2) {
  int res = 0;
  STACK* stack = NULL;
  char output[50] = {0};
  char input[] = "10-x";
  char result[] = "10 0 6.000000 - - ";
  convert_to_rpn(input, &stack, output, -6.0);
  clear_stack(stack);
  ck_assert_int_eq(res, 0);
  ck_assert_str_eq(result, output);
}
END_TEST

// polish_nat_fail
START_TEST(s21_test_polish_fail_1) {
  int res = 1;
  STACK* stack = NULL;
  char output[50] = {0};
  char input[] = "++5+3";
  convert_to_rpn(input, &stack, output, 0.0);
  clear_stack(stack);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_test_polish_fail_2) {
  int res = 1;
  STACK* stack = NULL;
  char output[50] = {0};
  char input[] = "2.2.2";
  convert_to_rpn(input, &stack, output, 0.0);
  clear_stack(stack);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_test_polish_fail_3) {
  int res = 1;
  STACK* stack = NULL;
  char output[50] = {0};
  char input[] = "--5+3";
  convert_to_rpn(input, &stack, output, 0.0);
  clear_stack(stack);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_test_polish_fail_4) {
  int res = 1;
  STACK* stack = NULL;
  char output[50] = {0};
  char input[] = "2+((0)";
  convert_to_rpn(input, &stack, output, 0.0);
  clear_stack(stack);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_test_polish_fail_5) {
  int res = 1;
  STACK* stack = NULL;
  char output[50] = {0};
  char input[] = "-1.1+2+()";
  convert_to_rpn(input, &stack, output, 0.0);
  clear_stack(stack);
  ck_assert_int_eq(res, 1);
}
END_TEST

// // polish_nat_trigo
START_TEST(s21_test_polish_tgigo_1) {
  int res = 0;
  STACK* stack = NULL;
  char output[50] = {0};
  char input[] = "sin(30)+cos(45)*2";
  char result[] = "30 s 45 c 2 * + ";
  convert_to_rpn(input, &stack, output, 0.0);
  clear_stack(stack);
  ck_assert_int_eq(res, 0);
  ck_assert_str_eq(result, output);
}
END_TEST

START_TEST(s21_test_polish_tgigo_2) {
  int res = 0;
  STACK* stack = NULL;
  char output[50] = {0};
  char input[] = "1-sin(45)*sin(45)";
  char result[] = "1 45 s 45 s * - ";
  convert_to_rpn(input, &stack, output, 0.0);
  clear_stack(stack);
  ck_assert_int_eq(res, 0);
  ck_assert_str_eq(result, output);
}
END_TEST

START_TEST(s21_test_polish_tgigo_3) {
  int res = 0;
  STACK* stack = NULL;
  char output[50] = {0};
  char input[] = "cos(45)*sin(45)";
  char result[] = "45 c 45 s * ";
  convert_to_rpn(input, &stack, output, 0.0);
  clear_stack(stack);
  ck_assert_int_eq(res, 0);
  ck_assert_str_eq(result, output);
}
END_TEST

START_TEST(s21_test_polish_tgigo_4) {
  int res = 0;
  STACK* stack = NULL;
  char output[50] = {0};
  char input[] = "1/tan(45)";
  char result[] = "1 45 t / ";
  convert_to_rpn(input, &stack, output, 0.0);
  clear_stack(stack);
  ck_assert_int_eq(res, 0);
  ck_assert_str_eq(result, output);
}
END_TEST

// str_in_queue
START_TEST(s21_test_str_to_queue_1) {
  int res = 0;
  pointers* queue;
  char output[] = "1 + 5.2 - 6.3 ";
  queue = str_to_queue(output);
  ck_assert_int_eq(res, 0);
  clear_queue(queue);
  free(queue);
}
END_TEST

// calculate
START_TEST(s21_test_calculate_1) {
  int res = 0;
  pointers queue;
  queue.front = NULL;
  queue.rear = NULL;
  // initQueue(&queue);
  push_queue(&queue, '1'), push_queue(&queue, ' '), push_queue(&queue, '4'),
      push_queue(&queue, '.'), push_queue(&queue, '3');
  push_queue(&queue, ' '), push_queue(&queue, '6'), push_queue(&queue, ' '),
      push_queue(&queue, '*'), push_queue(&queue, ' ');
  push_queue(&queue, '+'), push_queue(&queue, ' '), push_queue(&queue, '7'),
      push_queue(&queue, ' '), push_queue(&queue, '-');

  char* result_test = calculate(NULL, &queue);
  ck_assert_int_eq(res, 0);
  ck_assert_str_eq(result_test, "19.800000");
  free(result_test);
  clear_queue(&queue);
}
END_TEST

START_TEST(s21_test_calculate_2) {
  int res = 1;
  pointers queue;
  queue.front = NULL;
  queue.rear = NULL;
  push_queue(&queue, '0');
  push_queue(&queue, ' ');
  push_queue(&queue, '0');
  push_queue(&queue, ' ');
  push_queue(&queue, '/');

  char* result_test = calculate(NULL, &queue);

  ck_assert_int_eq(res, 1);
  free(result_test);
  clear_queue(&queue);
}
END_TEST

START_TEST(s21_test_calculate_3) {
  int res = 0;
  pointers queue;
  queue.front = NULL;
  queue.rear = NULL;
  // "0 2.2 - 0 7 - 4.5 2 ^ + * 4.2 + ";
  push_queue(&queue, '0'), push_queue(&queue, ' '), push_queue(&queue, '2'),
      push_queue(&queue, '.'), push_queue(&queue, '2');
  push_queue(&queue, ' '), push_queue(&queue, '-'), push_queue(&queue, ' '),
      push_queue(&queue, '0'), push_queue(&queue, ' ');
  push_queue(&queue, '7'), push_queue(&queue, ' '), push_queue(&queue, '-'),
      push_queue(&queue, ' '), push_queue(&queue, '4'), push_queue(&queue, '.'),
      push_queue(&queue, '5'), push_queue(&queue, ' '), push_queue(&queue, '2'),
      push_queue(&queue, ' ');
  push_queue(&queue, '^'), push_queue(&queue, ' '), push_queue(&queue, '+'),
      push_queue(&queue, ' '), push_queue(&queue, '*'), push_queue(&queue, ' ');
  push_queue(&queue, '4'), push_queue(&queue, '.'), push_queue(&queue, '2'),
      push_queue(&queue, ' '), push_queue(&queue, '+');

  char* result_test = calculate(NULL, &queue);
  ck_assert_int_eq(res, 0);
  ck_assert_str_eq(result_test, "-24.950000");
  free(result_test);
  clear_queue(&queue);
}
END_TEST

START_TEST(s21_test_calculate_4) {
  int res = 0;
  pointers queue;
  queue.front = NULL;
  queue.rear = NULL;
  // acos0.5 +asin1 +atan1
  // 0.5 C 1 S + 1 T +
  push_queue(&queue, '0'), push_queue(&queue, '.'), push_queue(&queue, '5'),
      push_queue(&queue, ' '), push_queue(&queue, 'C'), push_queue(&queue, ' ');
  push_queue(&queue, '1'), push_queue(&queue, ' '), push_queue(&queue, 'S'),
      push_queue(&queue, ' '), push_queue(&queue, '+');
  push_queue(&queue, ' '), push_queue(&queue, '1'), push_queue(&queue, ' '),
      push_queue(&queue, 'T'), push_queue(&queue, ' ');
  push_queue(&queue, '+');

  char* result_test = calculate(NULL, &queue);
  ck_assert_int_eq(res, 0);
  ck_assert_str_eq(result_test, "3.403392");
  free(result_test);
}
END_TEST

// credit_calc_ann
START_TEST(s21_test_credit_calc_ann_1) {
  double summa = 10000.0;
  int period = 12;
  double stake = 5.0;
  double monthly_pay = 0.0, over_pay = 0.0, total_pay = 0.0;
  credit_calc_ann(summa, period, stake, &monthly_pay, &over_pay, &total_pay);
  ck_assert_double_eq_tol(monthly_pay, 856.07, 0.01);
  ck_assert_double_eq_tol(over_pay, 272.84, 0.01);
  ck_assert_double_eq_tol(total_pay, 10272.84, 0.01);
}
END_TEST

START_TEST(s21_test_credit_calc_ann_2) {
  double summa = 500000.0;
  int period = 30;
  double stake = 12.0;
  double monthly_pay = 0.0, over_pay = 0.0, total_pay = 0.0;
  credit_calc_ann(summa, period, stake, &monthly_pay, &over_pay, &total_pay);
  ck_assert_double_eq_tol(monthly_pay, 19374.1, 0.1);
  ck_assert_double_eq_tol(over_pay, 81221.8, 0.1);
  ck_assert_double_eq_tol(total_pay, 581222, 1);
}
END_TEST

START_TEST(s21_test_credit_calc_ann_3) {
  double summa = 1000000.0;
  int period = 60;
  double stake = 20.0;
  double monthly_pay = 0.0, over_pay = 0.0, total_pay = 0.0;
  credit_calc_ann(summa, period, stake, &monthly_pay, &over_pay, &total_pay);
  ck_assert_double_eq_tol(monthly_pay, 26493.9, 0.1);
  ck_assert_double_eq_tol(over_pay, 589633, 1);
  ck_assert_double_eq_tol(total_pay, 1.58963e+06, 10);
}
END_TEST

// // credit_diff
START_TEST(s21_test_credit_calc_diff_1) {
  double summa = 50000.0;
  int period = 30;
  double stake = 12.0;
  double over_pay = 0.0, total_pay = 0.0, first_pay = 0.0, last_pay = 0.0;
  credit_diff(summa, period, stake, &over_pay, &total_pay, &first_pay,
              &last_pay);
  ck_assert_double_eq_tol(first_pay, 2166.67, 0.1);
  ck_assert_double_eq_tol(last_pay, 1666.67, 0.1);
  ck_assert_double_eq_tol(over_pay, 7750, 1);
  ck_assert_double_eq_tol(total_pay, 57750, 1);
}
END_TEST

START_TEST(s21_test_credit_calc_diff_2) {
  double summa = 300000.0;
  int period = 18;
  double stake = 16.0;
  double over_pay = 0.0, total_pay = 0.0, first_pay = 0.0, last_pay = 0.0;
  credit_diff(summa, period, stake, &over_pay, &total_pay, &first_pay,
              &last_pay);
  ck_assert_double_eq_tol(first_pay, 20666.7, 0.1);
  ck_assert_double_eq_tol(last_pay, 16666.7, 0.1);
  ck_assert_double_eq_tol(over_pay, 38000, 1);
  ck_assert_double_eq_tol(total_pay, 338000, 1);
}
END_TEST

int main() {
  Suite* suite = suite_create("TEST");
  TCase* tCase = tcase_create("TEST");
  SRunner* sRunner = srunner_create(suite);

  double FAILED = 0;
  suite_add_tcase(suite, tCase);

  // stack
  tcase_add_test(tCase, s21_test_stack_1);

  // s21_queue
  tcase_add_test(tCase, s21_test_queue_1);
  tcase_add_test(tCase, s21_test_queue_2);

  // polish_nat_ok
  tcase_add_test(tCase, s21_test_polish_1);
  tcase_add_test(tCase, s21_test_polish_2);
  tcase_add_test(tCase, s21_test_polish_3);
  tcase_add_test(tCase, s21_test_polish_4);
  tcase_add_test(tCase, s21_test_polish_5);
  tcase_add_test(tCase, s21_test_polish_6);

  // polish_x_1
  tcase_add_test(tCase, s21_test_polish_x_1);
  tcase_add_test(tCase, s21_test_polish_x_2);

  // polish_nat_fail
  tcase_add_test(tCase, s21_test_polish_fail_1);
  tcase_add_test(tCase, s21_test_polish_fail_2);
  tcase_add_test(tCase, s21_test_polish_fail_3);
  tcase_add_test(tCase, s21_test_polish_fail_4);
  tcase_add_test(tCase, s21_test_polish_fail_5);

  // polish_nat_trigo
  tcase_add_test(tCase, s21_test_polish_tgigo_1);
  tcase_add_test(tCase, s21_test_polish_tgigo_2);
  tcase_add_test(tCase, s21_test_polish_tgigo_3);
  tcase_add_test(tCase, s21_test_polish_tgigo_4);

  // str_in_queue
  tcase_add_test(tCase, s21_test_str_to_queue_1);

  // calculate
  tcase_add_test(tCase, s21_test_calculate_1);
  tcase_add_test(tCase, s21_test_calculate_2);
  tcase_add_test(tCase, s21_test_calculate_3);
  tcase_add_test(tCase, s21_test_calculate_4);

  // credit_calc_ann
  tcase_add_test(tCase, s21_test_credit_calc_ann_1);
  tcase_add_test(tCase, s21_test_credit_calc_ann_2);
  tcase_add_test(tCase, s21_test_credit_calc_ann_3);

  // credit_calc_diff
  tcase_add_test(tCase, s21_test_credit_calc_diff_1);
  tcase_add_test(tCase, s21_test_credit_calc_diff_2);

  srunner_run_all(sRunner, CK_NORMAL);
  FAILED = srunner_ntests_failed(sRunner);
  srunner_free(sRunner);
  return !FAILED ? EXIT_SUCCESS : EXIT_FAILURE;
}
