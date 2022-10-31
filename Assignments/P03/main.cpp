/*
 
   /$$$$$$    /$$ /$$   /$$  /$$$$$$                               
  /$$__  $$ /$$$$| $$  | $$ /$$__  $$                              
 |__/  \ $$|_  $$| $$  | $$|__/  \ $$                              
   /$$$$$$/  | $$| $$$$$$$$   /$$$$$/                              
  /$$____/   | $$|_____  $$  |___  $$                              
 | $$        | $$      | $$ /$$  \ $$                              
 | $$$$$$$$ /$$$$$$    | $$|  $$$$$$/                              
 |________/|______/    |__/ \______/                               
                                                                   
                                                                   
                                                                   
  /$$$$$$$   /$$$$$$   /$$$$$$                                     
 | $$__  $$ /$$$_  $$ /$$__  $$                                    
 | $$  \ $$| $$$$\ $$|__/  \ $$                                    
 | $$$$$$$/| $$ $$ $$   /$$$$$/                                    
 | $$____/ | $$\ $$$$  |___  $$                                    
 | $$      | $$ \ $$$ /$$  \ $$                                    
 | $$      |  $$$$$$/|  $$$$$$/                                    
 |__/       \______/  \______/                                     
                                                                   
                                                                   
                                                                   
  /$$   /$$                           /$$   /$$                    
 | $$  | $$                          | $$$ | $$                    
 | $$  | $$ /$$   /$$ /$$   /$$      | $$$$| $$  /$$$$$$   /$$$$$$ 
 | $$$$$$$$| $$  | $$| $$  | $$      | $$ $$ $$ /$$__  $$ /$$__  $$
 | $$__  $$| $$  | $$| $$  | $$      | $$  $$$$| $$  \ $$| $$  \ $$
 | $$  | $$| $$  | $$| $$  | $$      | $$\  $$$| $$  | $$| $$  | $$
 | $$  | $$|  $$$$$$/|  $$$$$$$      | $$ \  $$|  $$$$$$$|  $$$$$$/
 |__/  |__/ \______/  \____  $$      |__/  \__/ \____  $$ \______/ 
                      /$$  | $$                 /$$  \ $$          
                     |  $$$$$$/                |  $$$$$$/          
                      \______/                  \______/           
 
*/
#include <iostream>
#include <string>

#include "blackjack.hpp"
#include <time.h>
#include <vector>

// stdio.h, sys/ioctl.h, unistd.h

using namespace std;

// colors
// xy location
// terminal size

int main() {
  srand(time(0));
  string answer;
  cout << "Player's Cards: " << endl;
  Player p1;
  Card C1(rand() % 52);
  cout << C1 << endl;

  Card C2(rand() % 52);
  cout << C2 << endl;
  p1.setTotal((C1 + C2) + 2);
  cout << p1.getTotal() << endl;

  Player dealer;
  cout << "Dealer's Cards: " << endl;
  Card C3(rand() % 52);
  cout << C3 << endl;

  Card C4(rand() % 52);
  cout << C4 << endl;

  dealer.setTotal((C3 + C4) + 2);
  cout << dealer.getTotal() << endl;
  cout << "Do you want to hit?" << endl;
  cin >> answer;

  if (answer == "Yes" || answer == "YES" || answer == "yes") {
    Card C5((rand() % 52));
    cout << C5 << endl;
    p1.addTotal(C5.getRank());
    cout << p1.getTotal() << endl;
    if (p1.getTotal() < 21) {
      cout << "Do you want to hit?" << endl;
      cin >> answer;
      if (answer == "Yes" || answer == "YES" || answer == "yes") {
        Card C6((rand() % 52));
        cout << C6 << endl;
        p1.addTotal(C6.getRank());
        cout << p1.getTotal() << endl;
        if (p1.getTotal() > 21) {
          cout << "You lost" << endl;
        }
      }
    }
  } else if (answer == "No" || answer == "NO" || answer == "no") {
    if (dealer.getTotal() == 21) {
      cout << "The dealer won" << endl;
    } else if (dealer.getTotal() < p1.getTotal() && dealer.getTotal() < 21) {
      Card C30((rand() % 52));
      cout << "The dealer Draws" << endl << C30 << endl;
      dealer.addTotal(C30.getRank());
      cout << dealer.getTotal() << endl;
      if(dealer.getTotal() < p1.getTotal() && dealer.getTotal() < 21)
      {
        Card C31((rand() % 52));
        cout << "The dealer Draws again" << endl << C31 << endl;
        dealer.addTotal(C31.getRank());
        cout << dealer.getTotal();
        if(dealer.getTotal() < p1.getTotal() && dealer.getTotal() < 21)
        {
          Card C32((rand() % 52));
          cout << "The dealer Draws again" << endl << C32 << endl;
          dealer.addTotal(C32.getRank());
          cout << dealer.getTotal();
        }
        else if (dealer.getTotal() <= 21 && dealer.getTotal() > p1.getTotal()) {
        cout << "The dealer has won" << endl;
        }
        else
        {
        cout << "the dealer has bust" << endl;
        }
      }
      else if (dealer.getTotal() <= 21 && dealer.getTotal() > p1.getTotal()) {
        cout << "The dealer has won" << endl;
      }
      else
      {
        cout << "the dealer has bust" << endl;
      }

    } else if (dealer.getTotal() <= 21 && dealer.getTotal() > p1.getTotal()) {
      cout << "The dealer has won" << endl;
    } else {
      cout << "the dealer has bust" << endl;
    }
  }
}