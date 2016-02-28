#include <iostream>
#include <string>

using namespace std;

class Quote{
    public:
        Quote() = default;
        Quote(const string &book, double sales_prices):
            bookNo(book), price(sales_prices){}

        string isbs() const{ return bookNo;}

        virtual double net_price(std::size_t n) const
        {   return n * price;}
        
        virtual ~Quote() = default;

    private:
        string bookNo;

    protected:
        double price = 0.0;
};

class Bulk_quote : public Quote{
    public:
        Bulk_quote() = default;
        Bulk_quote(const string&, double, std::size_t, double);

        double net_price(std::size_t) const override;
    private:
        std::size_t min_qty = 0;
        double discount = 0;
};

Bulk_quote:: Bulk_quote(const string &book, double p, std::size_t qty, double disc):
    Quote(book, p), min_qty(qty), discount(disc)
{}

double net_price(std::size_t n){
    if(n >= min_qty)
        return cnt *(1-discount)*price;
    else
        return cnt* price;
}
    




