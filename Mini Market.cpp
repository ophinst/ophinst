 #include <iostream>

 using namespace std;

int main(int argc, char const *argv[])

// This program created by:
// Maulana Luthfi Nasution
// CIT - 2021 Class 2
// 001202100065
// Created at 14 September 2021


{
    int inputType;
    int itemTotal;
    double originalPrice;
    double albumPrice;
    double photobookPrice;
    double merchandisePrice;
    double totalPrice;
    char finish;

    cout << "=======================" << endl;
    cout << "Welcome to Dub's store!" << endl;
    cout << "=======================" << endl;
    cout << "What do you want to buy today?" << endl;
    cout << endl;

    //input item type
    retry:
    cout << "We sell :" << endl;
    cout << endl;
    cout << "1.Album ($15.00 each)" << endl;
    cout << "2.Photobook ($35.00 each" << endl;
    cout << "3.Merchandise ($5.00 each)" << endl;
    cout << endl;
    cout << "Input the number of item you want : ";  //input for the item other thanin the list will triggger default case
    cin >> inputType;
    

   switch (inputType) //using switch for showing different prompt and case for each item
   {
   case 1:
       cout << "How many Album you want to buy? "; //input quantity of the item
     cin >> itemTotal;

    originalPrice = 15.00 * itemTotal;

    if (originalPrice > 30.00) //requirements for the discount
    {
       albumPrice = originalPrice - (originalPrice * 0.3);

       cout << "You get 30 % Discount for Album" << endl;
    }

    else

        albumPrice = originalPrice; //item price if it is not meet the requirement for the discount

       break;

    case 2:
        cout << "How many Photobook you want to buy? ";
    cin >> itemTotal;

    originalPrice = 35.00 * itemTotal;

    if (originalPrice > 70.00)
    {
       photobookPrice = originalPrice - (originalPrice * 0.2);

       cout << "You get 20 % Discount for Photobook" << endl;
    }

    else

        photobookPrice = originalPrice;

       break;

    case 3:
        cout << "How many Merchandise you want to buy? ";
    cin >> itemTotal;

    originalPrice = 5.00 * itemTotal;

    if (originalPrice > 20.00)
    {
       merchandisePrice = originalPrice - (originalPrice * 0.1);

       cout << "You get 10 % Discount for Merchandise" << endl;
    }

    else
    
        merchandisePrice = originalPrice;

      break;

    default:
        cout << "Invalid Item!" << endl;
        cout << endl;  
        goto retry; //will send back the user to starting point

   }
        //arithmatic for total price
         totalPrice = albumPrice + photobookPrice + merchandisePrice;
       
       cout << endl;
       cout <<"Current total price = $" << totalPrice << endl;
       cout << endl;

       cout << "Are you done shopping?" << endl;
       cout << "Input 'n' if you're not done or input anything else if you're done : ";
       cin >> finish;

       if (finish=='n') //trigger loop
       {
           system("cls");
           goto retry;
       }

       else

       {
       cout << endl;
       cout << "Total payment for the item you buy is : $" << totalPrice << endl; //final output
       cout << endl;
       cout << "Thank you for shopping here :)" << endl;
       
       }
       
    return 0;
}
