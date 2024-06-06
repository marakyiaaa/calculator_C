#ifndef MAINWINDOW_HMAINWINDOW_H
#define MAINWINDOW_HMAINWINDOW_H

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack {
  char symbol;
  struct stack* next;
} STACK;

typedef struct queue {
  char value;
  struct queue* next;
} QUEUE;

typedef struct {
  QUEUE* front;
  QUEUE* rear;
} pointers;

#define SUCCES 0
#define FAIL 1

// realiz_queue
QUEUE* create_queue(char value);
void initQueue(pointers* point);
void push_queue(pointers* point, char value);
char pop_queue(pointers* point);
void show_queue(pointers point);
void clear_queue(pointers* queue);

// realiz_stack
STACK* push(STACK* top, char data);
STACK* pop(STACK* top);
void show_stack(STACK* top);
void clear_stack(STACK* stack);
STACK* initStack(STACK* stack);
char pop_one_element(STACK** top);

// check_error_input
int validate_expression(char* input);
int check_dot_error(char* input);
int check_staples(char* input);
int check_input_errors(char* input);

// polish
void processing_x(char* output, int* j, double x);
int priority(char input_oper);
int convert_to_rpn(char* input, STACK** stack, char* output, double x);
void process_trig_func(char* input, int* i, STACK** stack);

// calc
pointers* str_to_queue(char* output);
void poping_num_stack(STACK** stack, char* num_str);
void reverse_num(char* num_str);
double calculate_operator(double num1, double num2, char operator_math);
double calculate_function(double num1, char operator_math);
STACK* queue_to_stack(pointers* str_in_queue, STACK* stack);
char* calculate(STACK* stack, pointers* queue);
char* is_reverse_string(char* input);

// credit_calc
void credit_calc_ann(double summa, int period, double stake,
                     double* monthly_pay, double* over_pay, double* total_pay);
void credit_diff(double summa, int period, double stake, double* over_pay,
                 double* total_pay, double* first_pay, double* last_pay);

#endif
