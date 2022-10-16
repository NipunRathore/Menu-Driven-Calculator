#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;

#define new_cal 1
#define old_cal 0

//stand_cal to define standard calculator functions
class stand_calc
{
public:
  static double addition(double , double);
  static double subtract(double , double);
  static double multiplication(double , double);
  static double division(double , double *);
  static double modulu(double * , double *);
};

//scien_calc to define scientific calculator functions
class scien_calc
{
public:
  static double square(double);
  static double cube(double);
  static double power(double , double);
  static double sq_root(double);
  static long int fact(double);
  static double sin_func(double);
  static double cos_func(double);
  static double tan_func(double);
};

double stand_calc::addition(double a , double b)
{ return(a+b) ; }

double stand_calc::subtract(double a , double b)
{ return(a-b) ; }

double stand_calc::multiplication(double a , double b)
{ return(a*b) ; }

/*division function will divide the first number by the second number. This function accepts two arguments, one is a copy of a variable and another is a pointer type because if accepting divisor s zero, then this function will show a message to enter the divisor again. Using pointer means that the entered value of the divisor for this function should be updated at the main
function also.*/
double stand_calc::division(double a , double *b)
{ while(*b == 0)
  {
    cout << "\nCannot divide by zero.";
    cout << "\nEnter second number again:";
    cin >> *b;
  }
  return(a/(*b));
}

/*Modulus function will divide the first number by the second number and return the remaining part of the division. Similar to the division function, it will not accept zero in the divisor. Modulus cannot be performed on a double number, so we need to convert
it into an integer.*/
double stand_calc::modulu(double *a , double *b)
{
    while(*b == 0)
    {
        cout << "\nCannot divide by zero.";
        cout << "\nEnter second number again:";
        cin >> *b;
    }
    //Converting double into an integer .
    int x = (int)*a ;
    int y = (int)*b ;
    if(*a-x>0 || *b-y>0)
    cout << "\nConverting decimal number into an integer to perform modulus";
    *a = x ;
    *b = y ;
    return(x%y);
}

// Declaration of scien_calc class functions starts from here.
double scien_calc::square(double x)
{
     return(pow(x , 2)) ;
}
double scien_calc::cube(double x)
{
    return(pow(x , 3)) ;
}
double scien_calc::power(double x , double y)
{
    return(pow(x , y)) ;
}
double scien_calc::sq_root(double x)
{
    return(sqrt(x)) ;
}

/*Factorial function of the scien_calc class to return a long integer as the factorial of an acceptable number. This will convert the accepting number into an integer before calculating the factorial.*/
long int scien_calc::fact(double x)
{
    int n = (int)x;
    long int f = 1;
    while(n > 1)
    {
        f*=n ;
        n--;
    }
    return f ;
}
double scien_calc::sin_func(double x)
{
    return(sin(x)) ;
}
double scien_calc::cos_func(double x)
{
    return(cos(x)) ;
}
double scien_calc::tan_func(double x)
{
     return(tan(x)) ;
}


//Displaying the menus to enter the option and values.
int main()
{
    double num1 , num2 ,num3 , temp ;
    int choice1 = 0 , choice2 , flag ;
    //Loop of the main menu from where the program starts. It will show the menu to choose the type of calculator.
do
{
    cout << "\n========Type of Calculators=======";
    cout << "\n1\tStandard Calculator\n2\tScientific Calculator\n3\tQuit";
    cout << "\nChoose the type of Calculator:";
    cin >> choice1;
    flag = new_cal ;
    switch(choice1)
    {
    case 1:
        //Loop to display standard calculator menu.
        do
        {
            cout << "==========Standard Calculator===========";
            cout << "\n1\tAddition\n2\tSubtraction\n3\tMultiplication\n4\tDivision\n5\tModulus\n6\tReturn to Previous Menu\n7\tQuit";
         //Option 8 will be displayed only when working on old calculations. Here, already a number is saved in calculator memory.

        if(flag == old_cal)
        cout << "\n8\tClear Memory";
        cout << "\nChoose the type of calculation:";
        cin >> choice2;
        switch(choice2)
        {
          case 1:
//If a new calculation is there, then accept the first number else the previous calculation result will be the first number.
          if(flag == new_cal)
          {
             cout << "Enter first number:";
             cin >> num1;
          }
          else
            {
                num1=temp;
                cout << "\nFirst number is:" << num1 <<endl;
            }
              cout << "\nEnter second number:";
              cin >> num2;

              num3=stand_calc :: addition(num1 , num2);
              cout << "\nAddition of " << num1 << " and " << num2 <<" is " << num3;
              cout << "\nPress any key to continue......";
              temp = num3;
              flag = old_cal;
              break;
          case 2:
              if(flag == new_cal)
              {
                  cout << "Enter first number:";
                  cin >> num1;
              }
              else
              {
                num1 = temp;
                cout << "\nFirst number is:" << num1 << endl;
              }
              cout << "Enter second number:";
              cin >> num2;
              num3 = stand_calc :: subtract(num1 , num2);
              cout << "\nSubtraction of " << num2 << " from " << num1 << " is " << num3;
              cout << "\nPress any key to continue......";
              temp = num3;
              flag = old_cal;
              break;
          case 3:
            if(flag == new_cal)
            {
                cout << "Enter first number:";
                cin >> num1;
            }
            else
            {
                num1 = temp;
                cout << "\nFirst number is" << num1 << endl;
            }
            cout << "Enter second number:";
            cin >> num2;
            num3 = stand_calc :: multiplication(num1 , num2);
            cout << "\nMultiplication of " << num1 << " and " << num2 << " is " << num3;
            cout << "\nPress any key to continue......";
              temp = num3;
              flag = old_cal;
              break;
          case 4:
            if(flag == new_cal)
            {
                cout << "Enter first number:";
                cin >> num1;
            }
            else
            {
                num1 = temp;
                cout << "\nFirst number is" << num1 << endl;
            }
            cout << "Enter second number:";
            cin >> num2;
            num3 = stand_calc :: division(num1 , &num2);
            cout << "\nDivision of " << num1 << " by " << num2 << " is " << num3;
             cout << "\nPress any key to continue......";
              temp = num3;
              flag = old_cal;
              break;
          case 5:
              if(flag == new_cal)
            {
                cout << "Enter first number:";
                cin >> num1;
            }
            else
            {
                num1 = temp;
                cout << "\nFirst number is" << num1 << endl;
            }
            cout << "Enter second number:";
            cin >> num2;
            num3=stand_calc::modulu(&num1 , &num2);
            cout << "\nModulus of " << num1 << " by " << num2 << " is " << num3;
             cout << "\nPress any key to continue......";
              temp = num3;
              flag = old_cal;
              break;
          case 6:
            cout << "\nReturning to previous menu.";
            cout << "\nPress any key to continue......";
            break;
          case 7:
            cout << "\nQuiting..........";
            cout << "\nPress any key to continue......";
            exit(0);
          case 8:
//If a new calculation is going on then option 8 is an invalid option, else 8 is an option to start a new calculation.
            if(flag == new_cal)
            {
                 cout << "\nInvalid choice.";
                 cout << "\nPress any key to continue......";
            }
            else
            {
                temp = 0;
                flag = new_cal;
            }
            break;
          default:
             cout << "\nInvalid Choice.";
             cout << "\nPress any key to continue......";
             break;
        }
    } while(choice2!=6);
      break;
          case 2:
// Loop to display the scientific calculator menu.
          {
            do
            {
                cout << "\n==========Scientific Calculator===========";
                cout << "\n1\tSquare\n2\tCube\n3\tPower\n4\tFactorial\n5\tSin\n6\tCos\n7\tTan\n8\tReturn to previous menu\n9\tQuit";
                if(flag == old_cal)
                    cout << "\n10\tClear Memory";
                cout << "\nChoose the type of calculation:";
                cin >> choice2;
                switch(choice2)
                {
                case 1:
                    if(flag == new_cal)
                    {
                         cout << "Enter number to find square:";
                         cin >> num1;
                    }
                    else
                    {
                        num1 = temp;
                        cout << "\nNumber is" << num1  << endl;
                    }
                    num3 = scien_calc :: square(num1);
                    cout << "\nSquare of " << num1 << " is " << num3;

                    cout << "\nPress any key to continue.......";
                    temp = num3;
                    flag = old_cal;
                    break;
                case 2:
                     if(flag == new_cal)
                    {
                         cout << "Enter number to find cube:";
                         cin >> num1;
                    }
                    else
                    {
                        num1 = temp;
                        cout << "\nNumber is" << num1  << endl;
                    }
                    num3 = scien_calc :: cube(num1);
                    cout << "\nCube of " << num1 << " is " << num3;
                    cout << "\nPress any key to continue.......";
                    temp = num3;
                    flag = old_cal;
                    break;
                case 3:
                {
                    if(flag == new_cal)
                    {
                        cout << "Enter first number for base to find power:";
                        cin >> num1;
                    }
                    else
                    {
                        num1 = temp;
                        cout << "\nFirst number is:" << num1 << endl;
                    }
                    cout << "Enter second number for power to find power:";
                    cin >> num2;
                    num3 = scien_calc :: power(num1 , num2);
                    cout << "\n" << num1 << " to the power " << num2 << " is " << num3;
                    cout << "\nPress any key to continue....... ";
                    temp = num3;
                    flag = old_cal;
                }
                    break;
                case 4:
                {
                    if(flag == new_cal)
                    {
                        cout << "Enter number to find factorial:";
                        cin >> num1;
                    }
                    else
                    {
                        num1 = temp;
                        cout << "\nNumber to find factorial is " << num1 << endl;
                    }
                    long int num4 = scien_calc :: fact(num1);
                    cout << "\nFactorial of " << num1 << " is " << num4;
                    cout << "\nPress any key to continue.......";
                    temp = num4;
                    flag = old_cal;
                }
                    break;
                case 5:
                {
                    if(flag == new_cal)
                    {
                        cout << "Enter number to find sin value:";
                        cin >> num1;
                    }
                    else
                    {
                        num1 = temp;
                        cout << "\nNumber for sin value is:" << num1 << endl;
                    }
                    num3 = scien_calc :: sin_func(num1);
                    cout << "\nSin value of " << num1 << " is " << num3;
                    cout << "Press any key to continue.......";
                    temp = num3;
                    flag = old_cal;
                }
                    break;
                case 6:
                {
                     if(flag == new_cal)
                    {
                        cout << "Enter number to find cos value:";
                        cin >> num1;
                    }
                    else
                    {
                        num1 = temp;
                        cout << "\nNumber for cos value is:" << num1 << endl;
                    }
                    num3 = scien_calc :: cos_func(num1);
                    cout << "\nCos value of " << num1 << " is " << num3;
                    cout << "Press any key to continue.......";
                    getchar();
                    temp = num3;
                    flag = old_cal;
                }
                    break;
                case 7:
                {
                     if(flag == new_cal)
                    {
                        cout << "Enter number to find tan value:";
                        cin >> num1;
                    }
                    else
                    {
                        num1 = temp;
                        cout << "\nNumber for tan value is:" << num1 << endl;
                    }
                    num3 = scien_calc :: tan_func(num1);
                    cout << "\nTan value of " << num1 << " is " << num3;
                    cout << "Press any key to continue.......";
                    getchar();
                    temp = num3;
                    flag = old_cal;
                }
                    break;
                case 8:
                {
                    cout << "\nReturning to previous menu.";
                    cout << "\nPress any key to continue.......";
                    getchar();
                }
                    break;
                case 9:
                {
                    cout << "\nQuitting..........";
                    cout << "\nPress any key to continue.......";
                    getchar();
                    exit(0);
                }
                   break;
                case 10:
                {
                    if(flag == new_cal)
                    {
                        cout << "\nInvalid choice.";
                        cout << "\nPress any key to continue.......";
                        getchar();
                    }
                    else
                    {
                        temp = 0;
                        flag = new_cal;
                    }
                }
                    break;
                default:
                {
                    cout << "\nInvalid choice.";
                    cout << "\nPress any key to continue.......";
                }
                    break;
                }
            } while(choice2!=8);
        }
            break;
        case 3:
        {
            cout << "\nQuitting.......";
            cout << "\nPress any key to continue.......";
        }
            break;
        default:
        {
            cout << "\nInvalid choice.";
            cout << "\nPress any key to continue.......";
            getchar();
        }
            break;
   }
  } while(choice1!=3);
  return 0;
}
