#include <iostream>
#include "Stock.h"
#include "MarketOrderFactory.h"
#include "LimitOrderFactory.h"
#include "OrderBook.h"
#include "PriceTimeOrderMatchingStrategy.h"
#include "Trader.h"

int main() {
    // Create a strategy
    PriceTimeOrderMatchingStrategy strategy;

    // Create an order book with that strategy
    OrderBook orderBook(&strategy);

    // Create factories
    MarketOrderFactory marketFactory;
    LimitOrderFactory limitFactory;

    // Create traders
    Trader traderA("Alice", &marketFactory, &orderBook);
    Trader traderB("Bob", &limitFactory, &orderBook);

    // Create a sample stock
    Stock apple("AAPL", 150.0);

    // Traders place orders
    traderA.buy(apple, 10);
    traderB.sell(apple, 5);

    // Match orders
    orderBook.matchOrders();

    // Print the order book
    orderBook.printOrderBook();

    return 0;
}
