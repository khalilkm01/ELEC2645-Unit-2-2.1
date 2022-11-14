//ELEC/XJEL2645
// Dr Craig A. Evans and Dr Tim J. Amsdon

#include <iostream>
#include <regex>
#include "circle.h"

void main_menu();
int get_user_input();
void select_menu_item(int input);
void print_main_menu();
void go_back_to_main_menu();
bool is_integer(std::string num);
void menu_item_1();
void menu_item_2();
void menu_item_3();
void menu_item_4();
void menu_item_5();

void performCalculation(float (*func)(float,float));

float addition(float num1, float num2);
float subtraction(float num1, float num2);
float multiplication(float num1, float num2);
float division(float num1, float num2);

int main(int argc, char const *argv[]) {
  main_menu();
  return 0;
}

void main_menu() {
  print_main_menu();
  int input = get_user_input();
  select_menu_item(input);
}

int get_user_input() {
  int input;
  std::string input_string;
  bool valid_input = false;
  int menu_items = 6;

  do {
    std::cout << "\nSelect item: ";
    std::cin >> input_string;
    valid_input = is_integer(input_string);
    // if input is not an integer, print an error message
    if (valid_input == false) {
      std::cout << "Enter an integer!\n";
    } else {  // if it is an int, check whether in range
      input = std::stoi(input_string);  // convert to int
      if (input >= 1 && input <= menu_items) {
        valid_input = true;
      } else {
        std::cout << "Invalid menu item!\n";
        valid_input = false;
      }
    }
  } while (valid_input == false);

  return input;
}

void select_menu_item(int input) {
  switch (input) {
    case 1:
      menu_item_1();
      break;
    case 2:
      menu_item_2();
      break;
    case 3:
      menu_item_3();
      break;
    case 4:
      menu_item_4();
      break;
    case 5:
      menu_item_5();
      break;
    default:
      exit(1);
      break;
  }
}

void print_main_menu() {
  std::cout << "\n----------- Main menu -----------\n";
  std::cout << "|\t\t\t\t\t\t|\n";
  std::cout << "|\t1. Menu item 1\t\t|\n";
  std::cout << "|\t2. Menu item 2\t\t|\n";
  std::cout << "|\t3. Menu item 3\t\t|\n";
  std::cout << "|\t4. Menu item 4\t\t|\n";
  std::cout << "|\t5. Menu item 5\t\t|\n";
  std::cout << "|\t6. Exit\t\t\t\t|\n";
  std::cout << "|\t\t\t\t\t\t|\n";
  std::cout << "---------------------------------\n";
}

void go_back_to_main() {
  std::string input;
  do {
    std::cout << "\n\nEnter 'b' or 'B' to go back to main menu: ";
    std::cin >> input;
  } while (input != "b" && input != "B");
  main_menu();
}

// https://codereview.stackexchange.com/questions/162569/checking-if-each-char-in-a-string-is-a-decimal-digit
bool is_integer(std::string num) {
  return std::regex_match(num, std::regex("[+-]?[0-9]+"));
}

void menu_item_1() {
  std::cout << "\n>> Menu 1 - Addition\n";
  std::cout << "\nThis is an addition calculator\n";
  performCalculation(&addition);
  go_back_to_main();
}
void menu_item_2() {
  std::cout << "\n>> Menu 2 - Subtraction\n";
  std::cout << "\nThis is an subtraction calculator\n";
  performCalculation(&subtraction);
  go_back_to_main();
}
void menu_item_3() {
  std::cout << "\n>> Menu 3 - Multiplication\n";
  std::cout << "\nThis is an multiplication calculator\n";
  performCalculation(&multiplication);
  go_back_to_main();
}
void menu_item_4() {
  std::cout << "\n>> Menu 4 - Division\n";
  std::cout << "\nThis is an division calculator\n";
  performCalculation(&division);
  go_back_to_main();
}
void menu_item_5() {
  float radius;
  std::cout << "\n>> Menu 5 - Circle\n";
  std::cout << "\nThis is an area calculator for circles\n";
  std::cout << "\n Please input the circle's radius: ";
  std::cin >> radius;
  Circle circle(radius);

  std::cout << "\n Area of the circle: \n" << circle.get_area();
  go_back_to_main();
}

void performCalculation(float (*func)(float,float)){
  float num1,num2;


  std::cout << "\n Please input num1: ";
  std::cin >> num1;

  std::cout << "\n Please input num2: ";
  std::cin >> num2;

  std::cout << "\n Calculation Answer: \n"<< func(num1,num2);
}

float addition(float num1, float num2) {
  return num1 + num2;
}

float subtraction(float num1, float num2) {
  return num1 - num2;
}

float multiplication(float num1, float num2) {
  return num1 * num2;
}

float division(float num1, float num2) {
  return num1 / num2;
}