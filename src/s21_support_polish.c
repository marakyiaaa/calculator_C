#include "s21_smartcalc.h"

int priority(char input_oper) {
  int priority = 0;
  switch (input_oper) {
    case 's':
    case 'c':
    case 't':
    case 'S':
    case 'C':
    case 'T':
    case 'q':
    case 'g':
    case 'l':
      priority = 5;
      break;
    case '^':
      priority = 4;
      break;
    case '*':
    case '/':
      priority = 3;
      break;
    case '+':
    case '-':
      priority = 2;
      break;
  }
  return priority;
}

void process_trig_func(char *input, int *i, STACK **stack) {
  const char *trigo_functions[] = {"sin",  "cos",  "tan", "ACOS", "ASIN",
                                   "ATAN", "sqrt", "log", "ln",   "mod"};
  const char *trigo_symbols[] = {"s", "c", "t", "C", "S",
                                 "T", "q", "g", "l", "m"};

  for (size_t j = 0; j < sizeof(trigo_functions) / sizeof(trigo_functions[0]);
       j++) {
    if (!strncmp(trigo_functions[j], input + *i, strlen(trigo_functions[j]))) {
      *stack = push(*stack, *trigo_symbols[j]);
      *i += strlen(trigo_functions[j] - 1);
    }
  }
}

void processing_x(char *output, int *j, double x) {
  char temp[128] = {0};
  if (x < 0) {
    x = -x;
    output[(*j)++] = '0', output[(*j)++] = ' ';
    sprintf(temp, "%f", x);
    strcat(output, temp);
    *j += strlen(temp);
    output[(*j)++] = ' ', output[(*j)++] = '-', output[(*j)++] = ' ';
  } else {
    sprintf(temp, "%f", x);
    strcat(output, temp);
    *j += strlen(temp);
    output[(*j)++] = ' ';
  }
}