#include "s21_smartcalc.h"

int convert_to_rpn(char* input, STACK** stack, char* output, double x) {
  int array_length = strlen(input), check = SUCCES, i = 0, j = 0, flag_unar = 0;
  if (check_input_errors(input)) check = FAIL;
  for (; i < array_length && check != FAIL; ++i) {
    char inp_char = input[i];
    if ((inp_char == '-' || inp_char == '+') &&
        ((i == 0) || (input[i - 1] == '('))) {
      output[j++] = '0', output[j++] = ' ';
      *stack = push(*stack, inp_char);
      flag_unar++;
    } else if (isdigit(inp_char) || inp_char == '.') {
      while (input[i] == '.' || isdigit(input[i])) {
        output[j++] = input[i++];
      }
      output[j++] = ' ';
      i--;
      if (flag_unar == 1) {
        output[j++] = pop_one_element(stack), output[j++] = ' ';
      }
    } else if (inp_char == '(' && !flag_unar) {
      *stack = push(*stack, inp_char);
    } else if (inp_char == ')') {
      while (*stack != NULL && (*stack)->symbol != '(') {
        output[j++] = pop_one_element(stack), output[j++] = ' ';
      }
      pop_one_element(stack);
    } else if (strchr("+-*/^", inp_char)) {
      while (*stack != NULL &&
             priority(inp_char) < priority((*stack)->symbol) &&
             ((*stack)->symbol != '(' || inp_char == '^')) {
        output[j++] = pop_one_element(stack), output[j++] = ' ';
      }
      while (*stack != NULL &&
             priority(inp_char) == priority((*stack)->symbol) &&
             (*stack)->symbol != '(') {
        output[j++] = pop_one_element(stack), output[j++] = ' ';
      }
      *stack = push(*stack, inp_char);
    } else if (inp_char == 'x') {
      processing_x(output, &j, x);
    } else
      (process_trig_func(input, &i, stack));
  }
  while (*stack != NULL) {
    output[j++] = pop_one_element(stack), output[j++] = ' ';
  }
  return check;
}