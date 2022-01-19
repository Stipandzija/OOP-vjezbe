#include "hand.hpp"
#include <iostream>
#include <vector>
#include <string>
#include "print_cards.hpp"

using namespace std;



hand::hand() {}
int hand::get_score_of_hand() {
    score_of_hand = 0;
    for (int i = 0; i < (int)h.size(); i++)
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
    
    print_top_bot(p);
    print_top_rank(p);
    print_sym(p);
    print_bot_rank(p);
    print_top_bot(p);

    get_score_of_hand();
}

void hand::print_top_bot(print& p)
{
    for (int i = 0; i < p.get_sizee(); ++i)
    {
        for (int y = 0; y < (int)h.size(); ++y)
        {
            cout << p.get_header(i) << "   ";
        }
        cout << endl; 
    }
}

void hand::print_sym(print& p) {

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < (int)h.size(); ++j)
        {
            if (h[j].check_is_turned())  // Check to if card is hidden
            {
                cout << p.print_card("hidden", i) << "   ";
            }
            else
            {
                cout << p.print_card(h[j].get_suit(), i) << "   ";
            }
        }
        cout << endl;
    }
}
void hand::print_bot_rank(print& p)
{
    for (int i = 0; i < (int)h.size(); ++i)
    {
        if (h[i].check_is_turned())
        {
            cout << p.bot_rank("?") << "   ";
        }
        else
        {
           cout << p.bot_rank(get_card_rank(i)) << "   ";
        }
    }
    cout << endl;
}
void hand::print_top_rank(print& p) {
    {
        for (int i = 0; i < (int)h.size(); ++i)
        {
            if (h[i].check_is_turned())
            {
                cout << p.top_rank("?") << "   ";
            }
            else
            {
                cout << p.top_rank(get_card_rank(i)) << "   ";
            }
        }
        cout << endl; 
    }
}
