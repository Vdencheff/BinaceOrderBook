#pragma once

#include <chrono>
#include "Tools.hpp"
#include "OrderBook.hpp"

class FunctionalTests {

public:
    FunctionalTests() = default;

    int letterInNumber() {
        std::cout << "\n" << YELLOW << "Starting test : letterInNumber" << RESET << std::endl;
        std::map<std::string, std::map<ull, ull, OrderBook::DescendingComparator>> bookBids = {};
        std::map<std::string, std::map<ull, ull>> bookAsks;
        std::string dataBaseFile = "ResourceFiles/letter_in_number.txt";
        OrderBook orderBook(bookBids, bookAsks);
        int result = orderBook.bookUpdate(bookBids, bookAsks, dataBaseFile);
        int testStatus = 0;
        if (result == 0) {
            std::cerr << __func__ << ": The existing error has not been detected!. Test fail." << std::endl;
            testStatus = 1;
        }
        else {
            std::cout << "Error has been successfully detected." << std::endl;
            consoleWriteInColors("Test passed!", GREEN);
        }
        std::cout << YELLOW << "Test ended: letterInNumber" << RESET << std::endl;

        return testStatus;
    }
    int noValidNumber() {
        std::cout << "\n" << YELLOW << "Starting test : noValidNumber" << RESET << std::endl;
        std::map<std::string, std::map<ull, ull, OrderBook::DescendingComparator>> bookBids = {};
        std::map<std::string, std::map<ull, ull>> bookAsks;
        std::string dataBaseFile = "ResourceFiles/no_valid_number.txt";
        OrderBook orderBook(bookBids, bookAsks);
        int result = orderBook.bookUpdate(bookBids, bookAsks, dataBaseFile);
        int testStatus = 0;
        if (result == 0) {
            std::cerr << __func__ << ": The existing error has not been detected!" << std::endl;
            consoleWriteInColors("Test failed!", RED);
            testStatus = 1;
        }
        else {
            std::cout << "Error has been successfully detected." << std::endl;
            consoleWriteInColors("Test passed!", GREEN);
        }
        std::cout << YELLOW << "Test ended: noValidNumber" << RESET << std::endl;

        return testStatus;
    }
    int numberOutOfRange() {
        std::cout << "\n" << YELLOW << "Starting test : numberOutOfRange" << RESET << std::endl;
        std::map<std::string, std::map<ull, ull, OrderBook::DescendingComparator>> bookBids = {};
        std::map<std::string, std::map<ull, ull>> bookAsks;
        std::string dataBaseFile = "ResourceFiles/number_out_of_range.txt";
        OrderBook orderBook(bookBids, bookAsks);
        int result = orderBook.bookUpdate(bookBids, bookAsks, dataBaseFile);
        int testStatus = 0;
        if (result == 0) {
            std::cerr << __func__ << ": The existing error has not been detected!" << std::endl;
            consoleWriteInColors("Test failed!", RED);
            testStatus = 1;
        }
        else {
            std::cout << "Error has been successfully detected." << std::endl;
            consoleWriteInColors("Test passed!", GREEN);
        }
        std::cout << YELLOW << "Test ended: numberOutOfRange" << RESET << std::endl;

        return testStatus;
    }
    int missingS() {
        std::cout << "\n" << YELLOW << "Starting test : missingS" << RESET << std::endl;
        std::map<std::string, std::map<ull, ull, OrderBook::DescendingComparator>> bookBids = {};
        std::map<std::string, std::map<ull, ull>> bookAsks;
        std::string dataBaseFile = "ResourceFiles/missing_s.txt";
        OrderBook orderBook(bookBids, bookAsks);
        int result = orderBook.bookUpdate(bookBids, bookAsks, dataBaseFile);
        int testStatus = 0;
        if (result == 0) {
            std::cerr << __func__ << ": The existing error has not been detected!." << std::endl;
            consoleWriteInColors("Test failed!", RED);
            testStatus = 1;
        }
        else {
            std::cout << "Error has been successfully detected." << std::endl;
            consoleWriteInColors("Test passed!", GREEN);
        }
        std::cout << YELLOW << "Test ended: missingS" << RESET << std::endl;

        return testStatus;
    }
    int missingA() {
        std::cout << "\n" << YELLOW << "Starting test : missingA" << RESET << std::endl;
        std::map<std::string, std::map<ull, ull, OrderBook::DescendingComparator>> bookBids = {};
        std::map<std::string, std::map<ull, ull>> bookAsks;
        std::string dataBaseFile = "ResourceFiles/missing_a.txt";
        OrderBook orderBook(bookBids, bookAsks);
        int result = orderBook.bookUpdate(bookBids, bookAsks, dataBaseFile);
        int testStatus = 0;
        if (result == 0) {
            std::cerr << __func__ << ": The existing error has not been detected!" << std::endl;
            consoleWriteInColors("Test failed!", RED);
            testStatus = 1;
        }
        else {
            std::cout << "Error has been successfully detected." << std::endl;
            consoleWriteInColors("Test passed!", GREEN);
        }
        std::cout << YELLOW << "Test ended: missingA" << RESET << std::endl;

        return testStatus;
    }
    int missingB() {
        std::cout << "\n" << YELLOW << "Starting test : missingB" << RESET << std::endl;
        std::map<std::string, std::map<ull, ull, OrderBook::DescendingComparator>> bookBids = {};
        std::map<std::string, std::map<ull, ull>> bookAsks;
        std::string dataBaseFile = "ResourceFiles/missing_b.txt";
        OrderBook orderBook(bookBids, bookAsks);
        int result = orderBook.bookUpdate(bookBids, bookAsks, dataBaseFile);
        int testStatus = 0;
        if (result == 0) {
            std::cerr << __func__ << ": The existing error has not been detected!" << std::endl;
            consoleWriteInColors("Test failed!", RED);
            testStatus = 1;
        }
        else {
            std::cout << "Error has been successfully detected." << std::endl;
            consoleWriteInColors("Test passed!", GREEN);
        }
        std::cout << YELLOW << "Test ended: missingB" << RESET << std::endl;

        return testStatus;
    }
    int multipleCurencies() {
        std::cout << "\n" << YELLOW << "Starting test : multipleCurencies" << RESET << std::endl;
        std::map<std::string, std::map<ull, ull, OrderBook::DescendingComparator>> bookBids = {};
        std::map<std::string, std::map<ull, ull>> bookAsks;
        std::string dataBaseFile = "ResourceFiles/multiple_curencies.txt";
        OrderBook orderBook(bookBids, bookAsks);
        int result = orderBook.bookUpdate(bookBids, bookAsks, dataBaseFile);
        int testStatus = 0;
        int currenciesInFile = 4;
        if (result == 0) {
            if (bookBids.size() == currenciesInFile) {
                std::cout << "All currencies stored in order book" << std::endl;
                consoleWriteInColors("Test passed!", GREEN);
                testStatus = 0;
            }
            else {
                consoleWriteInColors("All currencies not detected!", RED);
                std::cout << "Pprovided currencies count" << currenciesInFile << std::endl;
                std::cout << "Detected currencies count" << bookBids.size() << std::endl;
                testStatus = 1;
            }
        }
        else {
            // Detected error that is not checked for in this test case 
            std::cerr << "Unexpected error has been detected." << std::endl;
            consoleWriteInColors("Test failed!", RED);
            testStatus = 1;
        }
        std::cout << YELLOW << "Test ended: multipleCurencies" << RESET << std::endl;

        return testStatus;
    }
    int repeatedData() {
        std::cout << "\n" << YELLOW << "Starting test : repeatedData" << RESET << std::endl;
        std::map<std::string, std::map<ull, ull, OrderBook::DescendingComparator>> bookBids = {};
        std::map<std::string, std::map<ull, ull>> bookAsks;
        std::string dataBaseFile = "ResourceFiles/repeated_data.txt";
        OrderBook orderBook(bookBids, bookAsks);
        int result = orderBook.bookUpdate(bookBids, bookAsks, dataBaseFile);
        int testStatus = 0;
        int dataEntries = 1;
        if (result == 0) {
            if (bookBids.size() == dataEntries) {
                std::cout << "All repeated entries overwrited" << std::endl;
                consoleWriteInColors("Test passed!", GREEN);
                testStatus = 0;
            }
            else {
                consoleWriteInColors("All repeated entries not overwrited!", RED);
                std::cout << "Pprovided entries count" << dataEntries << std::endl;
                std::cout << "Storred entries count" << bookBids.size() << std::endl;
                testStatus = 1;
            }
        }
        else {
            // Detected error that is not checked for in this test case 
            std::cerr << "Unexpected error has been detected." << std::endl;
            consoleWriteInColors("Test failed!", RED);
            testStatus = 1;
        }
        std::cout << YELLOW << "Test ended: repeatedData" << RESET << std::endl;

        return testStatus;
    }
    int updatingExistingEntry() {
        std::cout << "\n" << YELLOW << "Starting test : updatingExistingEntry" << RESET << std::endl;
        std::map<std::string, std::map<ull, ull, OrderBook::DescendingComparator>> bookBids = {};
        std::map<std::string, std::map<ull, ull>> bookAsks;
        std::string dataBaseFile = "ResourceFiles/update_existing_entry.txt";
        OrderBook orderBook(bookBids, bookAsks);
        int result = orderBook.bookUpdate(bookBids, bookAsks, dataBaseFile);
        int testStatus = 0;
        ull expectedBidPrice = 9465000000000;
        ull expectedBidQuantity = 100000000;

        if (result == 0) {
            if (bookBids.find("BTCUSDT") != bookBids.end()) {
                const auto& bids = bookBids.at("BTCUSDT");

                auto it = bids.find(expectedBidPrice);  // Search for the target bid price

                if (it != bids.end()) {
                    std::cout << "Bid found! Price: " << it->first << ", Quantity: " << it->second << std::endl;
                    if (it->second != expectedBidQuantity) {
                        consoleWriteInColors("Bid not updated!", RED);
                        std::cout << "Expected: " << " : [" << expectedBidPrice << " -> " << expectedBidQuantity << "] \n";
                        std::cout << "Storred: " << ": [" << expectedBidPrice << " -> " << expectedBidQuantity << "]\n";
                        testStatus = 1;
                    }
                    else {
                        std::cout << "Bid updated!" << std::endl;
                        testStatus = 0;
                    }
                }
                else {
                    std::cout << "Bid price " << expectedBidPrice << " not found." << std::endl;
                    testStatus = 1;
                }
            }
            else {
                consoleWriteInColors("No bids available in the order book.", RED);
                testStatus = 1;
            }
        }
        else {
            // Detected error that is not checked for in this test case 
            std::cerr << "Unexpected error has been detected." << std::endl;
            consoleWriteInColors("Test failed!", RED);
            testStatus = 1;
        }
        if (testStatus) {
            consoleWriteInColors("Test failed!", RED);
        }
        else {
            consoleWriteInColors("Test passed!", GREEN);
        }
        std::cout << YELLOW << "Test ended: updatingExistingEntry" << RESET << std::endl;

        return testStatus;
    }
    int zeroBidValueInitially() {
        std::cout << "\n" << YELLOW << "Starting test : zeroBidValueInitially" << RESET << std::endl;
        std::map<std::string, std::map<ull, ull, OrderBook::DescendingComparator>> bookBids = {};
        std::map<std::string, std::map<ull, ull>> bookAsks;
        std::string dataBaseFile = "ResourceFiles/zero_value_for_bid_initially.txt";
        OrderBook orderBook(bookBids, bookAsks);
        int result = orderBook.bookUpdate(bookBids, bookAsks, dataBaseFile);
        int testStatus = 0;

        if (result == 0) {
            if (bookBids.find("BTCUSDT") != bookBids.end()) {
                consoleWriteInColors("Bids available in the order book. Must be empty.", RED);
                orderBook.printOrderBook(bookBids, bookAsks, 1);
                std::cout << "Order book bid size: " << bookBids.size() << std::endl;
                testStatus = 1;
            }
            else {
                consoleWriteInColors("No bids available in the order book.", GREEN);
                testStatus = 0;
            }
        }
        else {
            // Detected error that is not checked for in this test case 
            std::cerr << "Unexpected error has been detected." << std::endl;
            consoleWriteInColors("Test failed!", RED);
            testStatus = 1;
        }
        if (testStatus) {
            consoleWriteInColors("Test failed!", RED);
        }
        else {
            consoleWriteInColors("Test passed!", GREEN);
        }
        std::cout << YELLOW << "Test ended: zeroBidValueInitially" << RESET << std::endl;

        return testStatus;
    }
    int letterInNumberUnOrdered() {
        std::cout << "\n" << YELLOW << "Starting test : letterInNumber" << RESET << std::endl;
        std::unordered_map<std::string, std::unordered_map<ull, ull>> bookBids;
        std::unordered_map < std::string, std::unordered_map<ull, ull>> bookAsks;
        std::string dataBaseFile = "ResourceFiles/letter_in_number.txt";
        OrderBook orderBook(bookBids, bookAsks);
        int result = orderBook.bookUpdate(bookBids, bookAsks, dataBaseFile);
        int testStatus = 0;
        if (result == 0) {
            std::cerr << __func__ << ": The existing error has not been detected!. Test fail." << std::endl;
            testStatus = 1;
        }
        else {
            std::cout << "Error has been successfully detected." << std::endl;
            consoleWriteInColors("Test passed!", GREEN);
        }
        std::cout << YELLOW << "Test ended: letterInNumber" << RESET << std::endl;

        return testStatus;
    }
    int noValidNumberUnOrdered() {
        std::cout << "\n" << YELLOW << "Starting test : noValidNumber" << RESET << std::endl;
        std::unordered_map<std::string, std::unordered_map<ull, ull>> bookBids;
        std::unordered_map < std::string, std::unordered_map<ull, ull>> bookAsks;
        std::string dataBaseFile = "ResourceFiles/no_valid_number.txt";
        OrderBook orderBook(bookBids, bookAsks);
        int result = orderBook.bookUpdate(bookBids, bookAsks, dataBaseFile);
        int testStatus = 0;
        if (result == 0) {
            std::cerr << __func__ << ": The existing error has not been detected!" << std::endl;
            consoleWriteInColors("Test failed!", RED);
            testStatus = 1;
        }
        else {
            std::cout << "Error has been successfully detected." << std::endl;
            consoleWriteInColors("Test passed!", GREEN);
        }
        std::cout << YELLOW << "Test ended: noValidNumber" << RESET << std::endl;

        return testStatus;
    }
    int numberOutOfRangeUnOrdered() {
        std::cout << "\n" << YELLOW << "Starting test : numberOutOfRange" << RESET << std::endl;
        std::unordered_map<std::string, std::unordered_map<ull, ull>> bookBids;
        std::unordered_map < std::string, std::unordered_map<ull, ull>> bookAsks;
        std::string dataBaseFile = "ResourceFiles/number_out_of_range.txt";
        OrderBook orderBook(bookBids, bookAsks);
        int result = orderBook.bookUpdate(bookBids, bookAsks, dataBaseFile);
        int testStatus = 0;
        if (result == 0) {
            std::cerr << __func__ << ": The existing error has not been detected!" << std::endl;
            consoleWriteInColors("Test failed!", RED);
            testStatus = 1;
        }
        else {
            std::cout << "Error has been successfully detected." << std::endl;
            consoleWriteInColors("Test passed!", GREEN);
        }
        std::cout << YELLOW << "Test ended: numberOutOfRange" << RESET << std::endl;

        return testStatus;
    }
    int missingSUnOrdered() {
        std::cout << "\n" << YELLOW << "Starting test : missingS" << RESET << std::endl;
        std::unordered_map<std::string, std::unordered_map<ull, ull>> bookBids;
        std::unordered_map < std::string, std::unordered_map<ull, ull>> bookAsks;
        std::string dataBaseFile = "ResourceFiles/missing_s.txt";
        OrderBook orderBook(bookBids, bookAsks);
        int result = orderBook.bookUpdate(bookBids, bookAsks, dataBaseFile);
        int testStatus = 0;
        if (result == 0) {
            std::cerr << __func__ << ": The existing error has not been detected!." << std::endl;
            consoleWriteInColors("Test failed!", RED);
            testStatus = 1;
        }
        else {
            std::cout << "Error has been successfully detected." << std::endl;
            consoleWriteInColors("Test passed!", GREEN);
        }
        std::cout << YELLOW << "Test ended: missingS" << RESET << std::endl;

        return testStatus;
    }
    int missingAUnOrdered() {
        std::cout << "\n" << YELLOW << "Starting test : missingA" << RESET << std::endl;
        std::unordered_map<std::string, std::unordered_map<ull, ull>> bookBids;
        std::unordered_map < std::string, std::unordered_map<ull, ull>> bookAsks;
        std::string dataBaseFile = "ResourceFiles/missing_a.txt";
        OrderBook orderBook(bookBids, bookAsks);
        int result = orderBook.bookUpdate(bookBids, bookAsks, dataBaseFile);
        int testStatus = 0;
        if (result == 0) {
            std::cerr << __func__ << ": The existing error has not been detected!" << std::endl;
            consoleWriteInColors("Test failed!", RED);
            testStatus = 1;
        }
        else {
            std::cout << "Error has been successfully detected." << std::endl;
            consoleWriteInColors("Test passed!", GREEN);
        }
        std::cout << YELLOW << "Test ended: missingA" << RESET << std::endl;

        return testStatus;
    }
    int missingBUnOrdered() {
        std::cout << "\n" << YELLOW << "Starting test : missingB" << RESET << std::endl;
        std::unordered_map<std::string, std::unordered_map<ull, ull>> bookBids;
        std::unordered_map < std::string, std::unordered_map<ull, ull>> bookAsks;
        std::string dataBaseFile = "ResourceFiles/missing_b.txt";
        OrderBook orderBook(bookBids, bookAsks);
        int result = orderBook.bookUpdate(bookBids, bookAsks, dataBaseFile);
        int testStatus = 0;
        if (result == 0) {
            std::cerr << __func__ << ": The existing error has not been detected!" << std::endl;
            consoleWriteInColors("Test failed!", RED);
            testStatus = 1;
        }
        else {
            std::cout << "Error has been successfully detected." << std::endl;
            consoleWriteInColors("Test passed!", GREEN);
        }
        std::cout << YELLOW << "Test ended: missingB" << RESET << std::endl;

        return testStatus;
    }
    int multipleCurenciesUnOrdered() {
        std::cout << "\n" << YELLOW << "Starting test : multipleCurencies" << RESET << std::endl;
        std::unordered_map<std::string, std::unordered_map<ull, ull>> bookBids;
        std::unordered_map < std::string, std::unordered_map<ull, ull>> bookAsks;
        std::string dataBaseFile = "ResourceFiles/multiple_curencies.txt";
        OrderBook orderBook(bookBids, bookAsks);
        int result = orderBook.bookUpdate(bookBids, bookAsks, dataBaseFile);
        int testStatus = 0;
        int currenciesInFile = 4;
        if (result == 0) {
            if (bookBids.size() == currenciesInFile) {
                std::cout << "All currencies stored in order book" << std::endl;
                consoleWriteInColors("Test passed!", GREEN);
                testStatus = 0;
            }
            else {
                consoleWriteInColors("All currencies not detected!", RED);
                std::cout << "Pprovided currencies count" << currenciesInFile << std::endl;
                std::cout << "Detected currencies count" << bookBids.size() << std::endl;
                testStatus = 1;
            }
        }
        else {
            // Detected error that is not checked for in this test case 
            std::cerr << "Unexpected error has been detected." << std::endl;
            consoleWriteInColors("Test failed!", RED);
            testStatus = 1;
        }
        std::cout << YELLOW << "Test ended: multipleCurencies" << RESET << std::endl;

        return testStatus;
    }
    int repeatedDataUnOrdered() {
        std::cout << "\n" << YELLOW << "Starting test : repeatedData" << RESET << std::endl;
        std::unordered_map<std::string, std::unordered_map<ull, ull>> bookBids;
        std::unordered_map < std::string, std::unordered_map<ull, ull>> bookAsks;
        std::string dataBaseFile = "ResourceFiles/repeated_data.txt";
        OrderBook orderBook(bookBids, bookAsks);
        int result = orderBook.bookUpdate(bookBids, bookAsks, dataBaseFile);
        int testStatus = 0;
        int dataEntries = 1;
        if (result == 0) {
            if (bookBids.size() == dataEntries) {
                std::cout << "All repeated entries overwrited" << std::endl;
                consoleWriteInColors("Test passed!", GREEN);
                testStatus = 0;
            }
            else {
                consoleWriteInColors("All repeated entries not overwrited!", RED);
                std::cout << "Pprovided entries count" << dataEntries << std::endl;
                std::cout << "Storred entries count" << bookBids.size() << std::endl;
                testStatus = 1;
            }
        }
        else {
            // Detected error that is not checked for in this test case 
            std::cerr << "Unexpected error has been detected." << std::endl;
            consoleWriteInColors("Test failed!", RED);
            testStatus = 1;
        }
        std::cout << YELLOW << "Test ended: repeatedData" << RESET << std::endl;

        return testStatus;
    }
    int updatingExistingEntryUnOrdered() {
        std::cout << "\n" << YELLOW << "Starting test : updatingExistingEntry" << RESET << std::endl;
        std::unordered_map<std::string, std::unordered_map<ull, ull>> bookBids;
        std::unordered_map < std::string, std::unordered_map<ull, ull>> bookAsks;
        std::string dataBaseFile = "ResourceFiles/update_existing_entry.txt";
        OrderBook orderBook(bookBids, bookAsks);
        int result = orderBook.bookUpdate(bookBids, bookAsks, dataBaseFile);
        int testStatus = 0;
        ull expectedBidPrice = 9465000000000;
        ull expectedBidQuantity = 100000000;

        if (result == 0) {
            if (bookBids.find("BTCUSDT") != bookBids.end()) {
                const auto& bids = bookBids.at("BTCUSDT");

                auto it = bids.find(expectedBidPrice);  // Search for the target bid price

                if (it != bids.end()) {
                    std::cout << "Bid found! Price: " << it->first << ", Quantity: " << it->second << std::endl;
                    if (it->second != expectedBidQuantity) {
                        consoleWriteInColors("Bid not updated!", RED);
                        std::cout << "Expected: " << " : [" << expectedBidPrice << " -> " << expectedBidQuantity << "] \n";
                        std::cout << "Storred: " << ": [" << expectedBidPrice << " -> " << expectedBidQuantity << "]\n";
                        testStatus = 1;
                    }
                    else {
                        std::cout << "Bid updated!" << std::endl;
                        testStatus = 0;
                    }
                }
                else {
                    std::cout << "Bid price " << expectedBidPrice << " not found." << std::endl;
                    testStatus = 1;
                }
            }
            else {
                consoleWriteInColors("No bids available in the order book.", RED);
                testStatus = 1;
            }
        }
        else {
            // Detected error that is not checked for in this test case 
            std::cerr << "Unexpected error has been detected." << std::endl;
            consoleWriteInColors("Test failed!", RED);
            testStatus = 1;
        }
        if (testStatus) {
            consoleWriteInColors("Test failed!", RED);
        }
        else {
            consoleWriteInColors("Test passed!", GREEN);
        }
        std::cout << YELLOW << "Test ended: updatingExistingEntry" << RESET << std::endl;

        return testStatus;
    }
    int zeroBidValueInitiallyUnOrdered() {
        std::unordered_map<std::string, std::unordered_map<ull, ull>> bookBids;
        std::unordered_map < std::string, std::unordered_map<ull, ull>> bookAsks;
        std::string dataBaseFile = "ResourceFiles/zero_value_for_bid_initially.txt";
        OrderBook orderBook(bookBids, bookAsks);
        int result = orderBook.bookUpdate(bookBids, bookAsks, dataBaseFile);
        int testStatus = 0;

        if (result == 0) {
            if (bookBids.find("BTCUSDT") != bookBids.end()) {
                consoleWriteInColors("Bids available in the order book. Must be empty.", RED);
                orderBook.printOrderBook(bookBids, bookAsks, 1);
                std::cout << "Order book bid size: " << bookBids.size() << std::endl;
                testStatus = 1;
            }
            else {
                consoleWriteInColors("No bids available in the order book.", GREEN);
                testStatus = 0;
            }
        }
        else {
            // Detected error that is not checked for in this test case 
            std::cerr << "Unexpected error has been detected." << std::endl;
            consoleWriteInColors("Test failed!", RED);
            testStatus = 1;
        }
        if (testStatus) {
            consoleWriteInColors("Test failed!", RED);
        }
        else {
            consoleWriteInColors("Test passed!", GREEN);
        }
        std::cout << YELLOW << "Test ended: zeroBidValueInitially" << RESET << std::endl;

        return testStatus;
    }
    int runALlTests() {
        int passedTests = 0;
        int totalTests = 0;
        if (!letterInNumber()) {
            ++passedTests;
            ++totalTests;
        }
        else {
            ++totalTests;
        }
        if (!noValidNumber()) {
            ++passedTests;
            ++totalTests;
        }
        else {
            ++totalTests;
        }
        if (!numberOutOfRange()) {
            ++passedTests;
            ++totalTests;
        }
        else {
            ++totalTests;
        }
        if (!missingS()) {
            ++passedTests;
            ++totalTests;
        }
        else {
            ++totalTests;
        }
        if (!missingA()) {
            ++passedTests;
            ++totalTests;
        }
        else {
            ++totalTests;
        }
        if (!missingB()) {
            ++passedTests;
            ++totalTests;
        }
        else {
            ++totalTests;
        }
        if (!multipleCurencies()) {
            ++passedTests;
            ++totalTests;
        }
        else {
            ++totalTests;
        }
        if (!repeatedData()) {
            ++passedTests;
            ++totalTests;
        }
        else {
            ++totalTests;
        }
        if (!updatingExistingEntry()) {
            ++passedTests;
            ++totalTests;
        }
        else {
            ++totalTests;
        }
        if (!zeroBidValueInitially()) {
            ++passedTests;
            ++totalTests;
        }
        else {
            ++totalTests;
        }
        if (!letterInNumberUnOrdered()) {
            ++passedTests;
            ++totalTests;
        }
        else {
            ++totalTests;
        }
        if (!noValidNumberUnOrdered()) {
            ++passedTests;
            ++totalTests;
        }
        else {
            ++totalTests;
        }
        if (!numberOutOfRangeUnOrdered()) {
            ++passedTests;
            ++totalTests;
        }
        else {
            ++totalTests;
        }
        if (!missingSUnOrdered()) {
            ++passedTests;
            ++totalTests;
        }
        else {
            ++totalTests;
        }
        if (!missingAUnOrdered()) {
            ++passedTests;
            ++totalTests;
        }
        else {
            ++totalTests;
        }
        if (!missingBUnOrdered()) {
            ++passedTests;
            ++totalTests;
        }
        else {
            ++totalTests;
        }
        if (!multipleCurenciesUnOrdered()) {
            ++passedTests;
            ++totalTests;
        }
        else {
            ++totalTests;
        }
        if (!repeatedDataUnOrdered()) {
            ++passedTests;
            ++totalTests;
        }
        else {
            ++totalTests;
        }
        if (!updatingExistingEntryUnOrdered()) {
            ++passedTests;
            ++totalTests;
        }
        else {
            ++totalTests;
        }
        if (!zeroBidValueInitiallyUnOrdered()) {
            ++passedTests;
            ++totalTests;
        }
        else {
            ++totalTests;
        }
        std::cout << "Total tests: " << totalTests << "; Passed tests: " << passedTests << std::endl;
        if (totalTests == passedTests) {
            consoleWriteInColors("All Test passed!\n", GREEN);
        }
        else {
            consoleWriteInColors("Not all Test passed!\n", RED);
        }
        return 0;
    }
};
