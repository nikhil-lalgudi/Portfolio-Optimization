#ifndef TRADER_H
#define TRADER_H

#include <vector>
#include <memory>
#include <string>
#include "Stock.h"
#include "Order.h"
#include "OrderBook.h"
#include "OrderFactory.h"

class Trader {
private:
    static int id_counter;
    int id;
    std::string name;
    std::vector<Stock> stocks;
    OrderFactory* orderFactory;   // Could be MarketOrderFactory or LimitOrderFactory
    OrderBook* orderBook;         // External or shared from somewhere
    std::vector<std::shared_ptr<Order>> orders;

public:
    Trader(const std::string& name, OrderFactory* factory, OrderBook* ob);

    int getID() const;
    const std::vector<std::shared_ptr<Order>>& getOrders() const;
    void addStock(const Stock& stock);
    std::vector<Stock> getStocks() const;
    void buy(const Stock& stock, int quantity);
    void sell(const Stock& stock, int quantity);
    // Example trade function for more flexible usage:
    void trade(double price, double quantity, int side); // side: 1=BUY, -1=SELL
};

#endif 