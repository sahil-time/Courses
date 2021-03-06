#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <vector>

using namespace std;

void print_all_N_digit_numbers(int digits, int base, string prefix = "", int is_dice = 0) { //while reading the code dont think about 'is_dice'
//    this_thread::sleep_for(chrono::milliseconds(100));
    if(digits == 0) { //base case [ to make it easy, thing of base case if digits == 1 ]
        cout << prefix << endl;
    } else {
        for(int i = 0; i < base; i++) {
            print_all_N_digit_numbers(digits - 1, base, prefix + to_string(i + is_dice), is_dice);
       }
    }
}

void print_all_permutations_N_time_diceRoll(int num_of_rolls) {
    print_all_N_digit_numbers(num_of_rolls, 6, "", 1);
}

//All possible anagrams
void print_all_permutations_string(const vector<char>& vc, string prefix = "") {
//    this_thread::sleep_for(chrono::milliseconds(100));
    if(vc.size() == 0) {
        cout << prefix << endl;
    } else {
        for(int i = 0; i < vc.size(); i++) {
            char ch = vc[i];
            vector<char> tmp = vc; //Not a good thing to make deep copy of vectors. Change this
            tmp.erase(tmp.begin() + i);
            print_all_permutations_string(tmp, prefix + ch);
        }
    }
}

//Copying vectors NOT good
void find_all_sublists(vector<string> chosen, vector<string> list) {
    //cout << chosen;
    if(!list.empty()) {
        string tmp = list[0];
        chosen.push_back(tmp);
        list.erase(list.begin());
        find_all_sublists(chosen, list); //do a search of all sublists on the chosen
        chosen.pop_back();
        find_all_sublists(chosen, list);
    } else {
        for (auto c: chosen)
            cout << c << endl;
        cout << endl;
    }
}

int main()
{
#if 0
    cout << "Enter number of digits - ";
    int digits;
    cin >> digits;
    cout << "Enter base of the numbers - ";
    int base;
    cin >> base;
    print_all_N_digit_numbers(digits, base); //base can be anything like 2 for Binary or 10 for Decimal

    cout << "Enter string - " << endl;
    string str;
    cin >> str;
    cout << endl;
    vector<char> vc(str.begin(), str.end());
    print_all_permutations_string(vc);
    return 0;

    cout << "Enter the number of times a dice has rolled - ";
    int num_rolls;
    cin >> num_rolls;
    print_all_permutations_N_time_diceRoll(num_rolls);

#endif
    vector<string> list {"Jane", "Bob", "Matt", "Sara"};
    vector<string> sublist;
    find_all_sublists(sublist, list);
}
