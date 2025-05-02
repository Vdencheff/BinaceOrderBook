#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <random>
#include <sstream>

class RandomEntryGenerator {
public:
    RandomEntryGenerator() = default;

    std::string createEntry(int bidCount, int askCount) {

        auto bids = generateOrderBookEntries(bidCount, 60000.0, 95000.0, 1.0, 100.0); // Price and quantity ranges for bids
        auto asks = generateOrderBookEntries(askCount, 94650.0, 95000.0, 0.01, 10.0);  // Price and quantity ranges for asks

        // Construct the final JSON-like string
        std::ostringstream finalJson;
        finalJson << "{\"e\": \"depthUpdate\", \"E\": 1745652665014, \"s\": \"BTCUSDT\", \"b\": " << entriesToString(bids)
            << ", \"a\": " << entriesToString(asks) << "}";

        return finalJson.str();
    }

private:
    // Generate random floating-point numbers
    double generateRandomDouble(double min, double max) {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(min, max);
        return dis(gen);
    }

    // Generate random entries for the order book
    std::vector<std::vector<std::string>> generateOrderBookEntries(int count, double priceMin, double priceMax, double qtyMin, double qtyMax) {
        std::vector<std::vector<std::string>> entries;
        for (int i = 0; i < count; ++i) {
            std::ostringstream priceStream, qtyStream;
            priceStream << std::fixed << std::setprecision(8) << generateRandomDouble(priceMin, priceMax);
            qtyStream << std::fixed << std::setprecision(8) << generateRandomDouble(qtyMin, qtyMax);
            entries.push_back({ priceStream.str(), qtyStream.str() });
        }
        return entries;
    }

    // Convert the entries to JSON-like string format
    std::string entriesToString(const std::vector<std::vector<std::string>>& entries) {
        std::ostringstream oss;
        oss << "[";
        for (size_t i = 0; i < entries.size(); ++i) {
            oss << "[\"" << entries[i][0] << "\", \"" << entries[i][1] << "\"]";
            if (i < entries.size() - 1) oss << ", ";
        }
        oss << "]";
        return oss.str();
    }
};