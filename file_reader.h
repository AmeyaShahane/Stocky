#include <iostream>
#include <vector>
#include "C:\Users\Ameya\Desktop\of_v0.10.1_vs2017_release\examples\3d\ofBoxExample\QuandlAPI.h"

#include <stdio.h>

class file_reader {

public:

	vector<string> finances; // Overall Stocks

	vector<double> closed_prices; // Closed Price Measures

	vector<double> open_prices; // Open Price Measures 

	void LoadDailyValuesFile(); // Live CSV loader

	void ParseDailyValues(); // Daily Values Parsed into sub vectors

	int kClosedPricesIndex = 4; // Closed Prices Index in CSV

	int kOpenPricesIndex = 1; // Open Prices Index in CSV

	int kYear = 365; // Length of year in days 
};
