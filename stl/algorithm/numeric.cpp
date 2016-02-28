#include <numeric> 
#include <vector>   
#include <functional>
#include <iostream>
#include <iterator>

using namespace std;

int main(int argc, const char *argv[])
{
    int ia[5] = {1, 2, 3, 4, 5};
    std::vector<int> iv(ia, ia+5);

    cout << accumulate(iv.begin(), iv.end(), 0) << endl;

    cout << accumulate(iv.begin(), iv.end(), 0, minus<int>()) << endl;
    
    cout << inner_product(iv.begin(), iv.end(), iv.begin(), 10) << endl;

    cout << inner_product(iv.begin(), iv.end(), iv.begin(), 10, minus<int>(), plus<int>()) << endl;

    ostream_iterator<int> oite(cout, " ");

    partial_sum(iv.begin(), iv.end(), oite);

    partial_sum(iv.begin(), iv.end(), oite, minus<int>());

    adjacent_difference(iv.begin(), iv.end(), oite);


    adjacent_difference(iv.begin(), iv.end(), oite, plus<int>());

    int n = 3;
    iota(iv.begin(), iv.end(), n);
    for (int i = 0; i < iv.size(); i++) {
        cout << iv[i] << ' ';
    }

    return 0;
}
