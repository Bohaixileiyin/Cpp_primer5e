#ifndef QUOTE_HPP
#define QUOTE_HPP

#include <string>
#include <iostream>
class Quote{
    public:
        Quote() = default;
        Quote(const std::string &book, double sales_price):bookNo(book), price(sales_price){}
        std::string isbn()const {return bookNo;}

        virtual double net_price(std::size_t n)const{return n*price;}
        //ex15.11
        virtual void debug()const{std::cout << bookNo << " " << price << std::endl;}
        virtual ~Quote() = default;
    private:
        std::string bookNo;
    protected:
        double price = 0.0;
};

double print_total(std::ostream &os, const Quote &item, size_t n){
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << "# sold: " << n << " total due: " << ret << std::endl;
    return ret;
}
#endif