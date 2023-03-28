// WRITE YOUR CODE HERE
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>
#include <sstream>
#include <iterator>


using std::vector;
using std::string;
using std::stable_sort;
using std::mismatch;
using std::pair;
using std::find_if;
using std::copy_if;
using std::lexicographical_compare;
using std::back_inserter;
using std::accumulate;
using std::ostringstream;
using std::transform;
using std::ostream_iterator;
using std::copy;
using std::to_string;
using std::cout;

bool FindCapital(char one){
    if (one < 97){
        return true;
    }
    return false;
}

bool CompareByUppercase(string a, string b){
    string acaps;
    string bcaps;
    copy_if(a.begin(),a.end(), back_inserter(acaps), FindCapital);
    copy_if(b.begin(), b.end(), back_inserter(bcaps), FindCapital);
    return(lexicographical_compare(acaps.begin(),acaps.end(),bcaps.begin(),bcaps.end()));
}

void SortByUppercase(vector<string> &vect){
    stable_sort(vect.begin(),vect.end(),CompareByUppercase);
}

int SumOfOdd(vector<int>::const_iterator a, vector<int>::const_iterator b){
    int sum = accumulate(a,b,0,[](int total = 0, int one){
        if(one % 2 ==1){
            return (total += one);
        }
        else{
            return total;
        }
    });
    return sum;
}

string DoubletoPercentString(vector<double> const &input){
    ostringstream oss;
    vector<string> output;
    transform(input.begin(),input.end(),back_inserter(output),[](double a){
        return (to_string((a * 100)/1) + "% ");
    });
    ostream_iterator<string> out(oss);
    copy(output.begin(),output.end(),out);
    return (oss.str());
}

int main(){
    std::vector<std::string> words = {"wolf", "BanAna", "caRRot", "AprIcots", "BEets", "chiCkPeas", "orAngEs", "apple", "CAT", "dOG"};
    SortByUppercase(words);
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 8, 5, 2, 2, 5, 101};
    int result = SumOfOdd(numbers.begin(), numbers.end());
    vector<double> const doubles = {1, 2, 100, 200, 12.3456, 4787, 0.123};
    string res = DoubletoPercentString(doubles);
    for(;;){
        int x = 2;
    }
}