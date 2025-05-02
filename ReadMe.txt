This file describes project structure and functional decisions.

~\OrderBookManagement\WebSocketAccessToBinance.py:
	This python script connects to Binance stream and save provided data.
	Data is saved in file ~\OrderBookManagement\ResourceFiles\binance_stream_output.txt
	Script is parametrized with number of entries to download:
	Line 5: entries_to_download = 5 -> put here desired number of entries.
	This file can be used in the C++ program as a data source.

~\OrderBookManagement\OrderBookManagement.sln:
	Visual Studio solution containing task implementation.
	
Main.cpp:
	Runs functional and performance tests.
	For comparison reasons solution implements two version of book management- one based on std::map, the other based on std::unordered_map.
	Both versions are equally measured and tested.
	Solution provides two methods for testing:
		1. Use database file
		2. Use random generate data
	All data base files used for tests are in folder "ResourceFiles" in the current solution folder.
	
OrderBook.cpp:
	File containing logic for order book management.
	
RandomEntryGenerator.hpp:
	Generator for random entries, similar to what Binance stream provides.
	Can be used for large data source. Helpfull for better performance measurements. 
	
FunctionalTests.hpp:
	Tests for data integrity and logic.
	
PerformanceTests.hpp:
	Tests for time and memory consumption.
	
Having std::unordered_map as a internal structure for order book provides better update time and less memory consumption, compared to std::map.
It has slower best element search and no search in range.
Having map provides fast best element search and have search in range.

Binance stream provides bids and asks entries as string. String manipulation is unefficient compared to integer number manipulation.
For that reason bids and asks string values are converted to unsigned long long. The accuracy is preserved and speed is increased.
The bids and asks strings provide floating point data. To preserve accuracy this data is multiplied to 10^8.
Consider that the output of the program is in [10^-8 BTC].
program output              -> actual value
9465012345678 [10^-8 BTC]  -> 94650.12345678 [BTC]