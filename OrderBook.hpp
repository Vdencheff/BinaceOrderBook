#pragma once
#include <iostream>
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

    int bookUpdate(std::map<std::string, std::map<ull, ull, DescendingComparator>>& orderBookBids, std::map<std::string, std::map<ull, ull>>& orderBookAsks, std::string& dataBase);
    int bookUpdate(std::map<std::string, std::map<ull, ull, DescendingComparator>>& orderBookBids, std::map<std::string, std::map<ull, ull>>& orderBookAsks, unsigned long entryCount, int bidCount, int asksCount);
    int bookUpdate(std::unordered_map<std::string, std::unordered_map<ull, ull>>& unOrderBookBids, std::unordered_map< std::string, std::unordered_map<ull, ull>>& unOrderBookAsks, std::string& dataBase);
    int bookUpdate(std::unordered_map<std::string, std::unordered_map<ull, ull>>& unOrderBookBids, std::unordered_map< std::string, std::unordered_map<ull, ull>>& unOrderBookAsks, unsigned long entryCount, int bidCount, int asksCount);

    void printOrderBook(std::map<std::string, std::map<ull, ull, DescendingComparator>>& orderBookBids, std::map<std::string, std::map<ull, ull>>& orderBookAsks, int detailLevel); // 0 - few details; 1 - more details
    void printOrderBook(std::unordered_map<std::string, std::unordered_map<ull, ull>> unOrderBookBids, std::unordered_map< std::string, std::unordered_map<ull, ull>> unOrderBookAsks, int detailLevel); // 0 - few details; 1 - more details

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

