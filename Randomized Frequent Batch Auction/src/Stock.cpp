#include "Stock.h"

Stock::Stock(const std::string& name, double price)
    : name(name), price(price) {}

void Stock::setName(const std::string& newName) {
    name = newName;
}

void Stock::setPrice(double newPrice) {
    price = newPrice;
}

std::string Stock::getName() const {
    return name;
}

double Stock::getPrice() const {
    return price;
}
