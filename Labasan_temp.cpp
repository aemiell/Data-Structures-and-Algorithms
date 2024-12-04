#include <iostream>
using namespace std;

int main() {
   int temp;
   int num_choice;

  cout << "Enter Temperature: "; 
  cin >> temp;

  cout << "Press 1 to convert to Fahrenheit to Celcius \n";
  cout << "Press 2 to convert to Celcius to Fahrenheit \n";
  cout << "Type the number you want to choose: ";
  cin >> num_choice;

  if (num_choice == 1) {
    float Celcius = (temp - 32) * 5.0 / 9.0; // Formula
    cout << "Your Temperature to Celcius: " << Celcius;
  }
  
    else if (num_choice == 2) {
    float Fahrenheit = (temp * 9.0 / 5.0) + 32; // Formula
    cout << "Your Temperature to Fahrenheit: " << Fahrenheit;
  }

   return 0;
  }
