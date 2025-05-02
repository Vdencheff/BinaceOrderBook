#include "OrderBook.hpp"
#include <iostream>
#include <fstream>
#include "C:/ws/nLohman/json-develop/single_include/nlohmann/json.hpp"
#include "RandomEntryGenerator.hpp"

using json = nlohmann::json;

OrderBook::OrderBook(std::map<std::string, std::map<ull, ull, DescendingComparator>>& orderBookBids, std::map<std::string, std::map<ull, ull>>& orderBookAsks)
{
}
OrderBook::OrderBook(std::unordered_map<std::string, std::unordered_map<ull, ull>> unOrderBookBids, std::unordered_map < std::string, std::unordered_map<ull, ull>> unOrderBookAsks)
{
}

void OrderBook::printBestOffers(std::map<std::string, std::map<ull, ull, DescendingComparator>>& orderBookBids, std::map<std::string, std::map<ull, ull>>& orderBookAsks) {
    std::cout << "\nBest Bids:\n";
    for (const auto& [symbol, bids] : orderBookBids) {
        auto bestBid = bids.begin();
        if (bestBid != bids.end()) {
            std::cout << symbol << ": [" << bestBid->first << " -> " << bestBid->second << "]\n";
        }
    }
    std::cout << "\nBest Asks:\n";
    for (const auto& [symbol, asks] : orderBookAsks) {
        auto bestAsks = asks.begin();
        if (bestAsks != asks.end()) {
            std::cout << symbol << ": [" << bestAsks->first << " -> " << bestAsks->second << "]\n";
        }
    }
}
void OrderBook::printBestOffers(std::unordered_map<std::string, std::unordered_map<ull, ull>>& unOrderBookBids, std::unordered_map < std::string, std::unordered_map<ull, ull>>& unOrderBookAsks) {
    std::cout << "\nBest Bids:\n";
    for (const auto& [symbol, entry] : bestBids) {
        std::cout << symbol << ": [" << entry.price << " -> " << entry.quantity << "]\n";
    }
    std::cout << "\nBest Asks:\n";
    for (const auto& [symbol, entry] : bestAsks) {
        std::cout << symbol << ": [" << entry.price << " -> " << entry.quantity << "]\n";
    }
}

int OrderBook::stringToULL(const std::string& strParam, ull& result) {
    try {
        std::string str = strParam;
        str.erase(str.find("."), 1);
        for (char c : str) {
            if (!std::isdigit(c)) {
                std::cout << __func__ << ": Provided number contains non number character: " << str << std::endl;
                return 1;
            }
        }
        result = std::stoull(str);
        //std::cout << "Converted value= " << result << std::endl;
        return 0;
    }
    catch (const std::invalid_argument&) {
        // Handle case where the string is not a valid number (not start with number)
        std::cout << "OrderBook::" << __func__ << ": Invalid numeric string" << std::endl;
        throw std::runtime_error("Invalid numeric string");
    }
    catch (const std::out_of_range&) {
        // Handle case where the number is too large to fit in ull
        std::cout << "OrderBook::" << __func__ << ": Number out of range " << std::endl;
        throw std::runtime_error("Number out of range");
    }
}

std::string OrderBook::randomEntryGenerator(int bidCount, int asksCount)
{
    RandomEntryGenerator reg;
    return reg.createEntry(bidCount, asksCount); // bid count, asks count
}

int OrderBook::bookUpdateHelper(std::map<std::string, std::map<ull, ull, DescendingComparator>>& orderBookBids, std::map<std::string, std::map<ull, ull>>& orderBookAsks, std::string& line) {
    try {
        json data = json::parse(line);
        if (data["s"].size() == 0) {
            std::cerr << "OrderBook::" << __func__ << " Error: source entry is missing!" << std::endl;
            return 1;
        }
        if (data["b"].size() == 0) {
            std::cerr << "OrderBook::" << __func__ << " Error: bid entry is missing!" << std::endl;
            return 1;
        }
        if (data["a"].size() == 0) {
            std::cerr << "OrderBook::" << __func__ << " Error: ask entry is missing!" << std::endl;
            return 1;
        }
        std::string symbol = data["s"];
        // Extract bids (b) and store in the map
        ull bidPrice = 0;
        ull bidQuantity = 0;
        for (const auto& bid : data["b"]) {
            if (stringToULL(bid[0], bidPrice) || stringToULL(bid[1], bidQuantity)) {
                std::cerr << "OrderBook::" << __func__ << ": Provided bidPrice or bidQuantity contain non number character: " << std::endl;
                return 1;
            }
            if (bidQuantity == 0) {
                orderBookBids[symbol].erase(bidPrice);
                if (orderBookBids[symbol].size() == 0) {
                    orderBookBids.erase(symbol);
                }
            }
            else {
                orderBookBids[symbol][bidPrice] = bidQuantity; // Store price as key, quantity as value
            }
        }
        // Extract asks (a) and store in the map
        ull asksPrice = 0;
        ull asksQuantity = 0;
        for (const auto& ask : data["a"]) {
            if (stringToULL(ask[0], asksPrice) || stringToULL(ask[1], asksQuantity)) {
                std::cerr << "OrderBook::" << __func__ << ": Provided asksPrice or asksQuantity contain non number character: " << std::endl;
                return 1;
            }
            if (asksQuantity == 0) {
                orderBookAsks[symbol].erase(asksPrice);
                if (orderBookAsks[symbol].size() == 0) {
                    orderBookAsks.erase(symbol);
                }
            }
            else {
                orderBookAsks[symbol][asksPrice] = asksQuantity; // Store price as key, quantity as value
            }
        }
    }
    catch (const std::runtime_error& e) {
        // Handle case where the string is not a valid number (not start with number)
        std::cerr << "OrderBook::" << __func__ << ": Error converting string to number: " << e.what() << std::endl;
        return 1;
    }
    catch (const std::exception& e) {
        std::cerr << "OrderBook::" << __func__ << ": Error parsing JSON: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}

int OrderBook::bookUpdateHelper(std::unordered_map<std::string, std::unordered_map<ull, ull>>& unOrderBookBids, std::unordered_map < std::string, std::unordered_map<ull, ull>>& unOrderBookAsks, std::string& line) {
    try {
        json data = json::parse(line);
        if (data["s"].size() == 0) {
            std::cerr << "OrderBook::" << __func__ << " Error: source entry is missing!" << std::endl;
            return 1;
        }
        if (data["b"].size() == 0) {
            std::cerr << "OrderBook::" << __func__ << " Error: bid entry is missing!" << std::endl;
            return 1;
        }
        if (data["a"].size() == 0) {
            std::cerr << "OrderBook::" << __func__ << " Error: ask entry is missing!" << std::endl;
            return 1;
        }
        std::string symbol = data["s"];
        // Extract bids (b) and store in the map
        ull bidPrice = 0;
        ull bidQuantity = 0;
        for (const auto& bid : data["b"]) {
            if (stringToULL(bid[0], bidPrice) || stringToULL(bid[1], bidQuantity)) {
                std::cerr << "OrderBook::" << __func__ << ": Provided bidPrice or bidQuantity contain non number character: " << std::endl;
                return 1;
            }
            if (bidQuantity == 0) {
                unOrderBookBids[symbol].erase(bidPrice);
                if (unOrderBookBids[symbol].size() == 0) {
                    unOrderBookBids.erase(symbol);
                }
                updateBestBid(symbol, bidPrice, 0, unOrderBookBids);
            }
            else {
                updateBestBid(symbol, bidPrice, bidQuantity);
                unOrderBookBids[symbol][bidPrice] = bidQuantity;
            }
        }
        // Extract asks (a) and store in the map
        ull asksPrice = 0;
        ull asksQuantity = 0;
        for (const auto& ask : data["a"]) {
            if (stringToULL(ask[0], asksPrice) || stringToULL(ask[1], asksQuantity)) {
                std::cerr << "OrderBook::" << __func__ << ": Provided asksPrice or asksQuantity contain non number character: " << std::endl;
                return 1;
            }
            if (asksQuantity == 0) {
                unOrderBookAsks[symbol].erase(asksPrice);
                if (unOrderBookAsks[symbol].size() == 0) {
                    unOrderBookAsks.erase(symbol);
                }
                updateBestAsk(symbol, asksPrice, 0, unOrderBookAsks);
            }
            else {
                updateBestAsk(symbol, asksPrice, asksQuantity);
                unOrderBookAsks[symbol][asksPrice] = asksQuantity; // Store price as key, quantity as value
            }
        }
    }
    catch (const std::runtime_error& e) {
        // Handle case where the string is not a valid number (not start with number)
        std::cerr << "OrderBook::" << __func__ << ": Error converting string to number: " << e.what() << std::endl;
        return 1;
    }
    catch (const std::exception& e) {
        std::cerr << "OrderBook::" << __func__ << ": Error parsing JSON: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}

// this function is applicable for unordered map
void OrderBook::updateBestBid(const std::string& source, ull newBidPrice, ull newBidQuantity) {
    // Check if we already have a bid for this source
    if (bestBids.find(source) != bestBids.end()) {
        // Compare with the existing best bid
        if (newBidPrice > bestBids[source].price) {
            //std::cout << "New bid (" << newBidPrice << ") is better than current best (" << bestBids[source].price << "). Updating...\n";
            bestBids[source] = { newBidPrice, newBidQuantity };  // Replace the existing best bid
        }
    }
    else {
        if (newBidQuantity > 0) {
            //std::cout << "No existing bid for source \"" << source << "\". Adding new bid...\n";
            bestBids[source] = { newBidPrice, newBidQuantity };  // Store the first bid
        }
    }
}

void OrderBook::updateBestBid(const std::string& source, ull newBidPrice, ull newBidQuantity, std::unordered_map<std::string, std::unordered_map<ull, ull>>& unOrderBookBids) {
    // Check if we already have a bid for this source
    if (bestBids.find(source) != bestBids.end()) {
        // if the best price now have zero quantity, then this best price is not available anymore. Search the whole map for the next best price
        if (newBidPrice == bestBids[source].price && newBidQuantity == 0) {// have we just removed from order Book the best price?
            findMaxElemInUnorderedMap(source, unOrderBookBids, bestBids); // remove this best entry form bestBids and add new best entry if orderBook not empty
        }
    }
    else {
        if (newBidQuantity > 0) {
            //std::cout << "No existing bid for source \"" << source << "\". Adding new bid...\n";
            bestBids[source] = { newBidPrice, newBidQuantity };  // Store the first bid
        }
    }
}

void OrderBook::findMaxElemInUnorderedMap(const std::string& source, std::unordered_map<std::string, std::unordered_map<ull, ull>>& unOrderBookBids, std::unordered_map<std::string, OrderBook::BestEntry>& bestEntry) {
    ull bestBidPrice = 0;
    ull bestBidQuantity = 0;
    bestEntry.erase(source); // remove the only element for this source, together with the source
    if (unOrderBookBids.find("b") != unOrderBookBids.end()) {
        for (const auto& bid : unOrderBookBids.at("b")) {
            if (bid.first > bestBidPrice) {  // Find biggest bid price
                bestBidPrice = bid.first;
                bestBidQuantity = bid.second;  // Store corresponding quantity
            }
        }
        bestBids[source].price = bestBidPrice;
        bestBids[source].quantity = bestBidQuantity;
    }
}

// this function is applicable for unordered map
void OrderBook::updateBestAsk(const std::string& source, ull newAskPrice, ull newAskQuantity) {
    // Check if we already have a bid for this source
    if (bestAsks.find(source) != bestAsks.end()) {
        // Compare with the existing best bid
        if (newAskPrice < bestAsks[source].price) {
            //std::cout << "New ask (" << newAskPrice << ") is better than current best (" << bestAsks[source].price << "). Updating...\n";
            bestAsks[source] = { newAskPrice, newAskQuantity };  // Replace the existing best ask
        }
        else {
            //std::cout << "New ask (" << newAskPrice << ") is not better than current best (" << bestAsks[source].price << ")\n";
        }
    }
    else {
        //std::cout << "No existing ask for source \"" << source << "\". Adding new ask...\n";
        bestAsks[source] = { newAskPrice, newAskQuantity };  // Store the first ask
    }
}
void OrderBook::updateBestAsk(const std::string& source, ull newAskPrice, ull newAskQuantity, std::unordered_map<std::string, std::unordered_map<ull, ull>>& unOrderBookAsks) {
    // Check if we already have a bid for this source
    if (bestAsks.find(source) != bestAsks.end()) {
        // if the best price now have zero quantity, then this best price is not available anymore. Search the whole map for the next best price
        if (newAskPrice == bestAsks[source].price && newAskQuantity == 0) {
            findMinElemInUnorderedMap(source, unOrderBookAsks, bestAsks);
        }
    }
    else {
        if (newAskQuantity > 0) {
            //std::cout << "No existing bid for source \"" << source << "\". Adding new bid...\n";
            bestAsks[source] = { newAskPrice, newAskQuantity };  // Store the first bid
        }
    }
}

void OrderBook::findMinElemInUnorderedMap(const std::string& source, std::unordered_map<std::string, std::unordered_map<ull, ull>>& unOrderBookAsks, std::unordered_map<std::string, OrderBook::BestEntry>& bestEntry) {
    ull bestAsksPrice = 0;
    ull bestAsksQuantity = 0;
    bestEntry.erase(source); // remove the only element for this source, together with the source
    if (unOrderBookAsks.find("a") != unOrderBookAsks.end()) {
        for (const auto& ask : unOrderBookAsks.at("a")) {
            if (ask.first < bestAsksPrice) {  // Find smallest ask price
                bestAsksPrice = ask.first;
                bestAsksQuantity = ask.second;  // Store corresponding quantity
            }
        }
        bestAsks[source].price = bestAsksPrice;
        bestAsks[source].quantity = bestAsksQuantity;
    }
}