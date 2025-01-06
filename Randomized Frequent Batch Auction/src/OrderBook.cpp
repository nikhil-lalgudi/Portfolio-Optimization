#include "OrderBook.h"
#include <iostream>

OrderBook::OrderBook() : strategy(nullptr) {}

OrderBook::OrderBook(OrderMatchingStrategy* strategy) : strategy(strategy) {}

void OrderBook::addOrder(const std::shared_ptr<Order>& order) {
    book.push_back(order);
}

void OrderBook::matchOrders() {
    if (strategy) {
        // Fill with real logic.
        std::vector<std::shared_ptr<Order>> buys;
        std::vector<std::shared_ptr<Order>> sells;

        // Separate buy and sell orders
        for (auto& o : book) {
            if (o->getOrderType() == OrderType::BUY) {
                buys.push_back(o);
            } else {
                sells.push_back(o);
            }
        }
        strategy->matchOrders(buys, sells);
    }
}

void OrderBook::setStrategy(OrderMatchingStrategy* newStrategy) {
    strategy = newStrategy;
}

void OrderBook::printOrderBook() const {
    std::cout << "Order Book:\n";
    for (const auto& order : book) {
        std::cout << " - " << order->getOrderTypeString() 
                  << " Trader=" << order->getTraderId() 
                  << " Price=" << order->getPrice() 
                  << " Qty=" << order->getQuantity() << "\n";
    }
}
