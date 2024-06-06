#include "s21_smartcalc.h"

STACK* push(STACK* top, char data) {
  STACK* newstack = calloc(1, sizeof(STACK));
  newstack->symbol = data;
  newstack->next = top;
  return newstack;
}

STACK* initStack(STACK* stack) {
  stack = calloc(1, sizeof(STACK));
  return stack;
}

STACK* pop(STACK* top) {
  if (top == NULL) return top;
  STACK* ptr_next = top->next;
  free(top);
  return ptr_next;
}

char pop_one_element(STACK** top) {
  if (*top == NULL) return '\0';
  char symbol = (*top)->symbol;
  *top = pop(*top);
  return symbol;
}

void clear_stack(STACK* stack) {
  if (stack == NULL) return;

  while (stack->next != NULL) {
    STACK* temp = stack;
    stack = stack->next;
    free(temp);
  }
}

// start_queue
QUEUE* create_queue(char value) {
  QUEUE* ptr = calloc(1, sizeof(QUEUE));
  if (ptr != NULL) {
    ptr->value = value;
    ptr->next = NULL;
  }
  return ptr;
}

void initQueue(pointers* point) {
  point->front = NULL;
  point->rear = NULL;
}

void push_queue(pointers* point, char value) {
  QUEUE* ptr = create_queue(value);
  if (point->rear == NULL) {
    point->front = point->rear = ptr;
  } else {
    point->rear->next = ptr;
    point->rear = ptr;
  }
}

char pop_queue(pointers* point) {
  if (point == NULL || point->front == NULL) {
    return FAIL;
  }
  QUEUE* ptr = point->front;
  char symbol = ptr->value;
  point->front = point->front->next;
  if (point->front == NULL) {
    point->rear = NULL;
  }
  free(ptr);
  return symbol;
}

void clear_queue(pointers* queue) {
  QUEUE* ptr = queue->front;
  while (ptr != NULL) {
    QUEUE* tmp = ptr;
    ptr = ptr->next;
    free(tmp);
  }
  queue->front = NULL;
  queue->rear = NULL;
}
