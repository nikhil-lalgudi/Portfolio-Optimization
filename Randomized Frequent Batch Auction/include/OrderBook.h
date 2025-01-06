#ifndef ORDER_BOOK_H
#define ORDER_BOOK_H

#include <vector>
#include <memory>
#include "Order.h"
#include "OrderMatchingStrategy.h"

class OrderBook {
private:
    std::vector<std::shared_ptr<Order>> book;
    OrderMatchingStrategy* strategy; // Could also use unique_ptr if you “own” the strategy

public:
    OrderBook();
    explicit OrderBook(OrderMatchingStrategy* strategy);
    void addOrder(const std::shared_ptr<Order>& order);
    void matchOrders(); // Delegates to strategy->matchOrders(...)
    void setStrategy(OrderMatchingStrategy* newStrategy);
    void printOrderBook() const;
};

#endif 
