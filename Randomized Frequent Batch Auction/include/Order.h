#ifndef ORDER_H
#define ORDER_H
#include <ctime>    
#include <string>

enum class OrderType {
    BUY,
    SELL
};

class Order {
protected:
    int trader_id;
    double price;
    int quantity;
    std::time_t timestamp;
    OrderType orderType;

public:
    // Constructors
    Order();
    Order(int traderId, double p, int qty, std::time_t ts, OrderType type);
    // Virtual destructor to allow subclass cleanup
    virtual ~Order() = default;
    // Getters
    int getTraderId() const;
    double getPrice() const;
    int getQuantity() const;
    std::time_t getTimestamp() const;
    OrderType getOrderType() const;
    // Setters / Modifiers
    void reduceQuantity(int qty);
    void setOrderType(OrderType type);
    // Virtual method to identify the order type (Market/Limit) by string
    virtual std::string getOrderTypeString() const = 0;
};

#endif 