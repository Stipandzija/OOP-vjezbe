#include "hand.hpp"
#include <iostream>
#include <vector>
#include "print_cards.hpp"

using namespace std;
hand::hand(){}
int hand::get_score_of_hand() {
    score_of_hand = 0; 
    for (int i = 0; i < h.size(); i++)
    {
        if (!h[i].check_is_turned()) 
        {
            score_of_hand += h[i].get_value();
        }
    }
    return score_of_hand;
}

hand::~hand() {

}
void hand::print_hand() {
	print p;
    print_sym(p);
    get_score_of_hand();
 }
void hand::print_sym(print& p) {

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < h.size(); ++j)
        {
            if (h[j].check_is_turned())  // Check to if card is hidden
            {
                cout << p.print_card("hidden", i) << "  ";
            }
            else
            {
                cout << p.print_card(h[j].get_suit(), i) << "  ";
            }
        }
        cout << endl;
    }
}
