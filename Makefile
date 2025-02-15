# Makefile for a C++20 trading engine project

CXX         = g++
CXXFLAGS    = -std=c++20 -Wall -Wextra -O2 -pthread
INCLUDES    = -I include
SRC_DIR     = src
BUILD_DIR   = build
TARGET      = trading_engine

# List all source files
SRCS = \
    $(SRC_DIR)/Stock.cpp \
    $(SRC_DIR)/Order.cpp \
    $(SRC_DIR)/MarketOrder.cpp \
    $(SRC_DIR)/LimitOrder.cpp \
    $(SRC_DIR)/OrderFactory.cpp \
    $(SRC_DIR)/MarketOrderFactory.cpp \
    $(SRC_DIR)/LimitOrderFactory.cpp \
    $(SRC_DIR)/OrderBook.cpp \
    $(SRC_DIR)/OrderMatchingStrategy.cpp \
    $(SRC_DIR)/PriceTimeOrderMatchingStrategy.cpp \
    $(SRC_DIR)/Trader.cpp \
    $(SRC_DIR)/TraderException.cpp \
    main.cpp

# For each .cpp, build an object file in the build/ directory
OBJS = $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

# Default rule
all: $(TARGET)

# Link objects into final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

# Compile .cpp -> .o
$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)  # ensure build directory structure exists
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean
