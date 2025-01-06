#include "PriceTimeOrderMatchingStrategy.h"
#include <algorithm>

void PriceTimeOrderMatchingStrategy::matchOrders(std::vector<std::shared_ptr<Order>>& buys,
                                                 std::vector<std::shared_ptr<Order>>& sells)
{
    // Idea:
    // 1. Sort buys descending by price, then ascending by timestamp
    // 2. Sort sells ascending by price, then ascending by timestamp
    // 3. Attempt matches

    // Sort buys (higher price first, older timestamp first)
    std::sort(buys.begin(), buys.end(),
              [](const std::shared_ptr<Order>& a, const std::shared_ptr<Order>& b) {
                  if (a->getPrice() == b->getPrice()) {
                      return a->getTimestamp() < b->getTimestamp();
                  }
                  return a->getPrice() > b->getPrice();
              });

    // Sort sells (lower price first, older timestamp first)
    std::sort(sells.begin(), sells.end(),
              [](const std::shared_ptr<Order>& a, const std::shared_ptr<Order>& b) {
                  if (a->getPrice() == b->getPrice()) {
                      return a->getTimestamp() < b->getTimestamp();
                  }
                  return a->getPrice() < b->getPrice();
              });

    // Matching logic placeholder
}
