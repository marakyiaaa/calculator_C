#include "s21_smartcalc.h"

int validate_expression(char* input) {
  int check = SUCCES, array_length = strlen(input), i = 0;
  if (input[i] == '*' || input[i] == '/' || input[i] == '^' ||
      input[i] == '.') {
    return FAIL;
  }
  if (input[array_length - 1] == '+' || input[array_length - 1] == '-' ||
      input[array_length - 1] == '*' || input[array_length - 1] == '/' ||
      input[array_length - 1] == '^' || input[array_length - 1] == '.' ||
      input[array_length - 1] == '(') {
    return FAIL;
  }
  for (; i < array_length - 1; ++i) {
    if (input[i] == input[i + 1] &&
        (input[i] == '+' || input[i] == '-' || input[i] == '*' ||
         input[i] == '/' || input[i] == '^')) {
      return FAIL;
    }
    if ((strchr("+-*/^", input[i])) && (strchr("+-*/^)", input[i + 1])))
      return FAIL;
    if ((strchr("(", input[i])) && (strchr(")", input[i + 1]))) return FAIL;
  }
  for (i = 0; i < array_length - 1; ++i) {
    if ((input[i] == 'm' || input[i] == '^') && !isdigit(input[i + 1])) {
      return FAIL;
    }
  }
  for (i = 0; i < array_length - 1; ++i) {
    if (input[i] == '.' && (!isdigit(input[i + 1]) || !isdigit(input[i + 1]))) {
      return FAIL;
    }
  }
  for (i = 0; i < array_length - 1; ++i) {
    if ((input[i] == 'x') && (input[i + 1] == 'x' || isdigit(input[i + 1]))) {
      return FAIL;
    }
  }
  return check;
}

int check_staples(char* input) {
  int check = SUCCES, array_length = strlen(input);
  int flag_ = 0, _flag = 0;
  for (int i = 0; i < array_length && check == SUCCES; ++i) {
    if (input[i] == '(') {
      _flag++;
    } else if (input[i] == ')') {
      flag_++;
      if (flag_ > _flag) {
        check = FAIL;
      }
    }
  }
  if (_flag != flag_) {
    check = FAIL;
  }

  return check;
}

int check_dot_error(char* input) {
  int check = SUCCES, array_length = strlen(input);
  int flag = 0;
  for (int i = 0; i < array_length && check == SUCCES; ++i) {
    if (input[i] == '.') {
      flag++;
    }
    if (flag >= 2) {
      check = FAIL;
    } else if ((input[i] == '+' || input[i] == '-' || input[i] == '*' ||
                input[i] == '/') &&
               flag == 1) {
      check = SUCCES;
      flag = 0;
    }
  }
  return check;
}

int check_input_errors(char* input) {
  if (validate_expression(input) == FAIL || check_dot_error(input) == FAIL ||
      check_staples(input) == FAIL)
    return FAIL;
  return SUCCES;
}
