#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <unordered_map>
#include "RandomEntryGenerator.hpp"

typedef unsigned long long ull;

class OrderBook
{
public:

    struct DescendingComparator {

        bool operator()(const ull& lhs, const ull& rhs) const {
            return lhs > rhs; // Change '<' to '>' for descending order
        }

        bool operator==(const DescendingComparator& other) const
        {
            return false;
        }
    };

    OrderBook(std::map<std::string, std::map<ull, ull, DescendingComparator>>& orderBookBids, std::map<std::string, std::map<ull, ull>>& orderBookAsks);
    OrderBook(std::unordered_map<std::string, std::unordered_map<ull, ull>> unOrderBookBids, std::unordered_map < std::string, std::unordered_map<ull, ull>> unoOrderBookAsks);

    template<typename OrderBookBids, typename OrderBookAsks>
    int bookUpdate(OrderBookBids& orderBookBids, OrderBookAsks& orderBookAsks, unsigned long entryCount, int bidCount, int asksCount);

    template<typename OrderBookBids, typename OrderBookAsks>
    int bookUpdate(OrderBookBids& orderBookBids, OrderBookAsks& orderBookAsks, std::string& dataBase);

    template<typename OrderBookBids, typename OrderBookAsks>
    void printOrderBook(OrderBookBids orderBookBids, OrderBookAsks orderBookAsks, int detailLevel);
    void printBestOffers(std::map<std::string, std::map<ull, ull, DescendingComparator>>& orderBookBids, std::map<std::string, std::map<ull, ull>>& orderBookAsks);
    void printBestOffers(std::unordered_map<std::string, std::unordered_map<ull, ull>>& unOrderBookBids, std::unordered_map< std::string, std::unordered_map<ull, ull>>& unOrderBookAsks);

private:
    struct BestEntry {
        ull price;
        ull quantity;
    };

    inline int stringToULL(const std::string& strParam, ull& result);
    std::string randomEntryGenerator(int bidCount, int asksCount);
    int bookUpdateHelper(std::map<std::string, std::map<ull, ull, DescendingComparator>>& orderBookBids, std::map<std::string, std::map<ull, ull>>& orderBookAsks, std::string& line);
    int bookUpdateHelper(std::unordered_map<std::string, std::unordered_map<ull, ull>>& unOrderBookBids, std::unordered_map< std::string, std::unordered_map<ull, ull>>& unOrderBookAsks, std::string& line);
    void updateBestBid(const std::string& source, ull newBidPrice, ull newBidQuantity);
    void updateBestAsk(const std::string& source, ull newAskPrice, ull newAskQuantity);
    void updateBestBid(const std::string& source, ull newBidPrice, ull newBidQuantity, std::unordered_map<std::string, std::unordered_map<ull, ull>>& unOrderBookBids);
    void updateBestAsk(const std::string& source, ull newAskPrice, ull newAskQuantity, std::unordered_map<std::string, std::unordered_map<ull, ull>>& unOrderBookAsks);
    void findMaxElemInUnorderedMap(const std::string& source, std::unordered_map<std::string, std::unordered_map<ull, ull>>& unOrderBookBids, std::unordered_map<std::string, OrderBook::BestEntry>& bestEntry);
    void findMinElemInUnorderedMap(const std::string& source, std::unordered_map<std::string, std::unordered_map<ull, ull>>& unOrderBookAsks, std::unordered_map<std::string, OrderBook::BestEntry>& bestEntry);
    // Best bid per source
    std::unordered_map<std::string, BestEntry> bestBids;
    std::unordered_map<std::string, BestEntry> bestAsks;
};

template<typename OrderBookBids, typename OrderBookAsks>
void OrderBook::printOrderBook(OrderBookBids orderBookBids, OrderBookAsks orderBookAsks, int detailLevel) {
    long totalBidsEntries = 0;
    long totalAsksEntries = 0;
    if (detailLevel == 1) {
        std::cout << "OrderBook\nBids:" << std::endl;
    }
    for (const auto& [symbol, bids] : orderBookBids) {
        totalBidsEntries += orderBookBids[symbol].size();
        if (detailLevel == 1) {
            std::cout << "Bids entries: " << orderBookBids[symbol].size() << std::endl;
            for (const auto& [price, quantity] : bids) {
                std::cout << symbol << ": [" << price << " -> " << quantity << "]\n";
            }
        }
    }
    if (detailLevel == 1) {
        std::cout << "Asks:" << std::endl;
    }
    for (const auto& [symbol, asks] : orderBookAsks) {
        totalAsksEntries += orderBookAsks[symbol].size();
        if (detailLevel == 1) {
            std::cout << "Asks entries: " << orderBookAsks[symbol].size() << std::endl;
            for (const auto& [price, quantity] : asks) {
                std::cout << symbol << ": [" << price << " -> " << quantity << "]\n";
            }
        }
    }
    std::cout << "Total Bids entries: " << totalBidsEntries << std::endl;
    std::cout << "Total Bids entries: " << totalAsksEntries << std::endl;
}

template<typename OrderBookBids, typename OrderBookAsks>
int OrderBook::bookUpdate(OrderBookBids& orderBookBids, OrderBookAsks& orderBookAsks, std::string& dataBase) {
    // Open the file containing multiple JSON entries
    std::ifstream inputFile(dataBase);
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }
    // Process each JSON entry in the file
    std::string line;
    while (std::getline(inputFile, line)) { // Read each line
        int result = bookUpdateHelper(orderBookBids, orderBookAsks, line);
        if (result) {
            std::cerr << "OrderBook::" << __func__ << ": Error reported " << std::endl;
            return 1;
        }
    }
    return 0;
}

template<typename OrderBookBids, typename OrderBookAsks>
int OrderBook::bookUpdate(OrderBookBids& orderBookBids, OrderBookAsks& orderBookAsks, unsigned long entryCount, int bidCount, int asksCount) {
    std::cout<< __func__ << "OrderBook::bookUpdate(OrderBookBids& orderBookBids, OrderBookAsks& orderBookAsks, unsigned long entryCount, int bidCount, int asksCount) " << std::endl;
    for (unsigned long i = 0; i < entryCount; ++i) {
        std::string line = randomEntryGenerator(bidCount, asksCount);
        int result = bookUpdateHelper(orderBookBids, orderBookAsks, line);
        if (result) {
            std::cerr << "OrderBook::" << __func__ << ": Error reported " << std::endl;
            return 1;
        }
    }
    return 0;
}