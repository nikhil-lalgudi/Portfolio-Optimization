#ifndef STOCK_H
#define STOCK_H

#include <string>

class Stock {
private:
    std::string name;
    double price;

public:
    Stock() : name(""), price(0.0) {}
    Stock(const std::string& name, double price);
    void setName(const std::string& newName);
    void setPrice(double newPrice);
    std::string getName() const;
    double getPrice() const;
};

#endif // STOCK_H
