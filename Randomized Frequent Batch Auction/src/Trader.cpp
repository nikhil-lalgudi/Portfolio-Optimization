#include "Trader.h"
#include <iostream>

int Trader::id_counter = 1;

Trader::Trader(const std::string& name, OrderFactory* factory, OrderBook* ob)
    : id(id_counter++), name(name), orderFactory(factory), orderBook(ob) {}

int Trader::getID() const {
    return id;
}

const std::vector<std::shared_ptr<Order>>& Trader::getOrders() const {
    return orders;
}

void Trader::addStock(const Stock& stock) {
    stocks.push_back(stock);
}

std::vector<Stock> Trader::getStocks() const {
    return stocks;
}

void Trader::buy(const Stock& stock, int quantity) {
    if (!orderFactory || !orderBook) {
        std::cerr << "OrderFactory or OrderBook is not set for Trader " << id << "\n";
        return;
    }

    auto order = orderFactory->createOrder(id, stock.getPrice(), quantity, OrderType::BUY);
    orders.push_back(order);
    orderBook->addOrder(order);
}

void Trader::sell(const Stock& stock, int quantity) {
    if (!orderFactory || !orderBook) {
        std::cerr << "OrderFactory or OrderBook is not set for Trader " << id << "\n";
        return;
    }

    auto order = orderFactory->createOrder(id, stock.getPrice(), quantity, OrderType::SELL);
    orders.push_back(order);
    orderBook->addOrder(order);
}

void Trader::trade(double price, double quantity, int side) {
    if (!orderFactory || !orderBook) {
        std::cerr << "OrderFactory or OrderBook is not set for Trader " << id << "\n";
        return;
    }

    OrderType type = (side > 0) ? OrderType::BUY : OrderType::SELL;
    auto order = orderFactory->createOrder(id, price, static_cast<int>(quantity), type);
    orders.push_back(order);
    orderBook->addOrder(order);
}
