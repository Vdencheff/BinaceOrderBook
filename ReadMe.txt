This file describes project structure.

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