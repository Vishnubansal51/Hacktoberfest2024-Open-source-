// #include <iostream>

// #include "cart_model.h"
// #include <vector>


// vector<Product> all_products = {
//     Product(1, "apple", 26),
//     Product(3, "mango", 16),
//     Product(2, "guava", 36),
//     Product(5, "banana", 56),
//     Product(4, "strawberry", 29),
//     Product(6, "pineapple", 2),
// };

// Product* chooseProduct()
// {
//     string product_list;
//     cout<<"available products"<<endl;

//     for(auto product: all_products){
//         product_list.append(product.get_display_name());
//     }

//     cout<<product_list<<endl;
//     cout<<"-------------------"<<endl;
//     cout<<"choose the item you want to select with its initial letter"<<endl;
//     string choice;
//     cin>> choice;
//     for(int i =0;i<all_products.size();i++)
//     {
//         if(all_products[i].get_short_name()==choice)
//         {
//             return &all_products[i];
//         }
//     }
//     cout<< "product is not found"<<endl;
//     return NULL;
// }

// bool Checkout(Cart &cart)
// {
//     if(cart.is_empty())
//     {
//         return false;
//     }
//     int total =cart.get_total();
//     cout<<"Pay in Cash Rs ";
//     int paid;
//     cin>> paid;
//     if(paid>= total){
//         cout<< "Change : Rs "<<paid-total<<endl;
//         cout<< " Thank you for Shopping"<<endl;
//         return true;
//     }
//     else
//     {
//         cout<< " not enough cash ";
//         return false;
//     }
// }
// int main()
// {
//     // Product p(1, " litchi",100);
//     // cout<<p.get_display_name();

//     // Item fruit( p,3);
//     // cout<< fruit.get_item_info();
//     // return 0;

//     char action;

//     Cart cart;
//     while (true)
//     {
//         cout << "Select an action -  (a)dd item, (v)iew cart, (c) heckout" << endl;
//         cin>>action;
//         if (action == 'a')
//         {
//             // Todo: Add to Cart
//             //  View all Products + choose product + Add to the Cart-
//             Product * product= chooseProduct();
//             if(product!= NULL)
//             {
//                 cout<<"added to the cart "<<product->get_display_name()<<endl;
//                 cart.add_product(*product);
//             }
//         }
//         else if (action == 'v')
//         {
//             // View the Cart
//             cout<<"----------------"<<endl;
//             cout<< cart.view_cart();
//             cout<<"----------------"<<endl;

//         }
//         else
//         {
//             // Checkout
//             cart.view_cart();
//             if(Checkout(cart))
//             {
//                 break;
//             }
//         }
//     }
//     return 0;
// }




#include <iostream>
#include <vector>
#include "cart_model.h"

using namespace std;

vector<Product> all_products = {
    Product(1, "Apple", 26),
    Product(2, "Mango", 16),
    Product(3, "Guava", 36),
    Product(4, "Banana", 56),
    Product(5, "Strawberry", 29),
    Product(6, "Pineapple", 20)
};

Product* choose_product() {
    cout << "Available products:\n";

    for (const auto& product : all_products) {
        cout << product.get_display_name();
    }

    cout << "-------------------\n";
    cout << "Choose the item you want to select by entering its initial letter: ";
    string choice;
    cin >> choice;

    for (auto& product : all_products) {
        if (product.get_short_name() == choice) {
            return &product;
        }
    }

    cout << "Product not found.\n";
    return nullptr;
}

bool checkout(Cart& cart) {
    if (cart.is_empty()) {
        cout << "Your cart is empty. Add items to your cart before checking out.\n";
        return false;
    }

    int total = cart.get_total();
    cout << "Total amount to pay: Rs " << total << "\nEnter amount paid: ";
    int paid;
    cin >> paid;

    if (paid >= total) {
        cout << "Change: Rs " << paid - total << "\nThank you for shopping!\n";
        return true;
    } else {
        cout << "Not enough cash. Please try again.\n";
        return false;
    }
}

int main() {
    char action;
    Cart cart;

    while (true) {
        cout << "Select an action - (a)dd item, (v)iew cart, (c)heckout, (r)emove item, (q)uit: ";
        cin >> action;

        if (action == 'a') {
            Product* product = choose_product();
            if (product != nullptr) {
                cart.add_product(*product);
                cout << "Added to cart: " << product->get_display_name() << endl;
            }
        } else if (action == 'v') {
            cout << cart.view_cart() << endl;
        } else if (action == 'c') {
            if (checkout(cart)) {
                break; // exit loop after successful checkout
            }
        } else if (action == 'r') {
            cout << "Enter the product ID to remove: ";
            int product_id;

            cin >> product_id;
            cart.remove_product(product_id);
            cout << "Product removed from cart.\n";
        } else if (action == 'q') {
            cout << "Exiting the program.\n";
            break; // exit loop and program
        } else {
            cout << "Invalid action. Please try again.\n";
        }
    }

    return 0;
}
