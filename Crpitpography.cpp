#include <iostream> //okay
#include <sstream>  //To use the istringstream function
#include <string.h> // To use the string functions.
#include <string>   // For string and to_string()
#include <stdlib.h> // Used in key function
#include <time.h>   // Used for key function
#include <limits>   // Used for getline
using namespace std;

class Encryption
{
public:
   string k = "#", cipher;
   string modify(string s)
   {
      s = s + ' ';
      int n = 0;
      string s1, ns = "";
      istringstream iis(s);
      while (getline(iis, s1, ' '))
      {
         s1 = Cipher(s1);
         ns += s1;
         ns += " ";
      }
      k = key();
      cout << "\nYour Encrypted text is: \n\n-----------------------" << endl
           << ns << endl
           << "-----------------------\n"
           << endl
           << "And Your KEY Provided is: \n\n*----------#-----------*" << endl
           << k << endl
           << "*----------#-----------*\n"
           << endl;
   }
   string Cipher(string input)
   {
      input.erase(input.find_last_not_of(" \n\r\t") + 1); // triming the right spaces
      string output = "";
      for (char c : input)
      {
         int ascii = (int)c; // type casting
         ascii += 3;
         char modified_char = (char)ascii;
         output += modified_char;
      }
      return output;
   }
   string key()
   {
      char Alphabets[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
                            'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
                            'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

      char RandString[5];
      srand(time(NULL));

      int k = 0;
      while (k < 5)
      {
         int temp = rand() % 26;
         RandString[k] = Alphabets[temp];
         k++;
      }
      string ns = "#";
      for (k = 0; k < 5; k++)
         ns += RandString[k];
      return ns;
   }
};

class Decription : private Encryption
{
private:
   string Dkey = Encryption::key();
   /* data */
public:
   bool check();
   string DCipher();
   string Dmodify(string s)
   {
      s = s + ' ';
      int n = 0;
      // cin >> x;
      string s1, ns = "", dk;
      cout << "-----------------------\n\nEnter the KEY:"
           << "\n*-----------#----------*" << endl;
      cin >> dk;

      if (check(dk))
      {
         istringstream iis(s);
         while (getline(iis, s1, ' '))
         {
            s1 = DCipher(s1);
            ns += s1;
            ns += " ";
         }
         return ns;
      }
      else
         cout << "KEY DOES NOT MATCH" << endl;
   }

   string DCipher(string input)
   {
      input.erase(input.find_last_not_of(" \n\r\t") + 1); // triming the right spaces
      string output = "";
      for (char c : input)
      {
         int ascii = (int)c;
         ascii -= 3;
         char modified_char = (char)ascii;
         output += modified_char;
      }
      return output;
   }
   bool check(string s)
   {
      cout << "*-----------#----------*\n";
      string s2;
      s2 = Dkey;
      if (s == s2)
         return true;
      else
         return false;
   }
};

int main()
{
   cout << "Enter the message to be Encrypted :\n-----------------------" << endl;
   string s;
   getline(cin, s);
   int i;

   Encryption fn1;
   Decription fn2;

   string ns = fn1.modify(s);
   cout << "Press '1' Decrypt the message:" << endl;
   int n;
   cin >> n;
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
   if (n == 1)
   {
      cout << "\n\nEnter the Ciphered text:\n-----------------------" << endl;
      string txt;
      getline(cin, txt);
      string nss = fn2.Dmodify(txt);
      cout << "The message is: "
           << "\n"
           << nss << endl;
   }
   else
      cout << "KEY doesn't match";
//l
   return 0;
}
