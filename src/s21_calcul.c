#include "s21_smartcalc.h"

STACK* queue_to_stack(pointers* str_in_queue, STACK* stack) {
  QUEUE* temp = str_in_queue->front;
  int k = 0;
  while (temp != NULL &&
         (isdigit(temp->value) || temp->value == '.' || temp->value == ' ')) {
    stack = push(stack, temp->value);
    temp = temp->next;
    pop_queue(str_in_queue);
  }
  if (temp != NULL &&
      (temp->value == '-' || temp->value == '+' || temp->value == '/' ||
       temp->value == '*' || temp->value == '^' || temp->value == 'm')) {
    char num1_str[16] = {0}, num2_str[16] = {0};
    temp = temp->next;
    char operator= pop_queue(str_in_queue);
    if (((isdigit(stack->symbol) || stack->symbol == '.' ||
          stack->symbol == ' '))) {
      poping_num_stack(&stack, num1_str), poping_num_stack(&stack, num2_str);
    }
    reverse_num(num1_str), reverse_num(num2_str);
    double num1 = atof(num1_str), num2 = atof(num2_str);
    double result = calculate_operator(num1, num2, operator);
    char res_math[16] = {0};
    sprintf(res_math, "%f", result);
    while (res_math[k] != '\0') {
      stack = push(stack, res_math[k]);
      k++;
    }
  } else if (temp != NULL &&
             (temp->value == 's' || temp->value == 'c' || temp->value == 't' ||
              temp->value == 'C' || temp->value == 'S' || temp->value == 'T' ||
              temp->value == 'q' || temp->value == 'g' || temp->value == 'l')) {
    temp = temp->next;
    char num1_str[16] = {0}, operator= pop_queue(str_in_queue);
    if (((isdigit(stack->symbol) || stack->symbol == '.' ||
          stack->symbol == ' '))) {
      poping_num_stack(&stack, num1_str);
    }
    reverse_num(num1_str);
    double num1 = atof(num1_str), result = calculate_function(num1, operator);
    char res_math[16] = {0};
    sprintf(res_math, "%f", result);
    while (res_math[k] != '\0') {
      stack = push(stack, res_math[k]);
      k++;
    }
  }
  return stack;
}

char* calculate(STACK* stack, pointers* queue) {
  if (queue == NULL || queue->front == NULL) {
    return NULL;
  }
  int length = 0;
  QUEUE* temp = queue->front;
  while (temp != NULL) {
    length++;
    temp = temp->next;
  }

  char* str_res = (char*)calloc(length + 1, sizeof(char));
  int j = 0;
  STACK* stack_res = (STACK*)calloc(1, sizeof(STACK));

  while (queue->front != NULL) {
    stack_res = queue_to_stack(queue, stack_res);
  }

  while (stack_res->next != NULL) {
    str_res[j++] = pop_one_element(&stack_res);
  }
  char* result = is_reverse_string(str_res);
  clear_stack(stack);
  clear_stack(stack_res);
  free(str_res);
  free(stack_res);
  clear_queue(queue);
  return result;
}

pointers* str_to_queue(char* output) {
  int array_length = strlen(output), i = 0;
  pointers* queue = calloc(1, sizeof(pointers));
  if (queue == NULL) {
    return NULL;
  }
  initQueue(queue);
  for (; i < array_length - 1; ++i) {
    while (output[i] != '\0') {
      push_queue(queue, output[i]);
      i += 1;
    }
    if (output[i] != ' ') {
      push_queue(queue, ' ');
    }
  }
  return queue;
}

void poping_num_stack(STACK** stack, char* num_str) {
  int i = 0;
  if ((*stack)->symbol == ' ') pop_one_element(stack);
  if (isdigit((*stack)->symbol) || (*stack)->symbol == '.') {
    while ((*stack)->symbol != ' ' && (*stack)->symbol != '\0') {
      num_str[i++] = pop_one_element(stack);
    }
    num_str[i] = '\0';
  }
}

void reverse_num(char* num_str) {
  STACK* stack_num = calloc(1, sizeof(STACK));
  int j = 0;
  while (num_str[j] != '\0' && num_str[j] != ' ') {
    stack_num = push(stack_num, num_str[j]);
    j++;
  }
  char copy_num[16] = {0};
  j = 0;
  while (stack_num != NULL) {
    char pop_num = pop_one_element(&stack_num);
    copy_num[j++] = pop_num;
  }
  copy_num[j] = '\0';
  strcpy(num_str, copy_num);
}

char* is_reverse_string(char* input) {
  size_t input_length = strlen(input);
  char* output = (char*)calloc(input_length + 1, sizeof(char));
  if (output == NULL) {
    return NULL;
  }
  for (int i = input_length - 1, j = 0; i >= 0; i--, j++) {
    output[j] = input[i];
  }
  output[input_length] = '\0';
  return output;
}

double calculate_operator(double num1, double num2, char operator) {
  double result = 0.0;
  switch (operator) {
    case '+':
      result = num2 + num1;
      break;
    case '-':
      result = num2 - num1;
      break;
    case '*':
      result = num2 * num1;
      break;
    case 'm':
      result = fmod(num2, num1);
      break;
    case '/':
      if (num1 == '0') break;
      result = num2 / num1;
      break;
    case '^':
      result = pow(num2, num1);
      break;
  }
  return result;
}

double calculate_function(double num1, char operator) {
  double result = 0.0;
  switch (operator) {
    case 's':
      result = sin(num1);
      break;
    case 'c':
      result = cos(num1);
      break;
    case 't':
      result = tan(num1);
      break;
    case 'C':
      result = acos(num1);
      break;
    case 'S':
      result = asin(num1);
      break;
    case 'T':
      result = atan(num1);
      break;
    case 'q':
      result = sqrt(num1);
      break;
    case 'g':
      result = log10(num1);
      break;
    case 'l':
      result = log(num1);
      break;
  }
  return result;
}
