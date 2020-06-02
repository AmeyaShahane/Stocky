#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "C:\Users\Ameya\Desktop\of_v0.10.1_vs2017_release\examples\3d\ofBoxExample\catch.hpp"
#include "file_reader.h"
#include "ofApp.h"
#include "vector_tester.h"
#include <string>

// Assert closed prices vector size
TEST_CASE("Closed Prices Size") {

	SECTION("Required Closed Prices Size") {

		file_reader financials;
		financials.LoadDailyValuesFile();
		financials.ParseDailyValues();
		REQUIRE(financials.closed_prices.size() == 365);

	}
}

// Assert open prices vector size 
TEST_CASE("Open Prices Size") {

	SECTION("Required Open Prices Size") {
		file_reader financials;
		financials.LoadDailyValuesFile();
		financials.ParseDailyValues();
		REQUIRE(financials.open_prices.size() == 365);

	}
}

// Assert hard coded vector decrease function 
TEST_CASE("Default Vector Decrease") {

	SECTION("Vector Prices Decrease") {

		vector<double> default_closing_vector = { 29.0,27.758 };

		vector_tester financials;

		REQUIRE(financials.stock_changes(default_closing_vector) == "decrease");
	}
}

// Assert hard coded vector increase function 
TEST_CASE("Default Vector Increase") {

	SECTION("Vector Prices Decrease") {

		vector<double> default_closing_vector = { 27.86, 29.64 };

		vector_tester financials;

		REQUIRE(financials.stock_changes(default_closing_vector) == "increase");
	}
}

// Assert Stable Vector 
TEST_CASE("Stable Vector") {

	SECTION("Stable Vector") {

		vector<double> default_closing_vector = { 34.6, 34.6 };

		vector_tester financials;

		REQUIRE(financials.stock_changes(default_closing_vector) == "green");
	}
}

// Assert Empty Vector 
TEST_CASE("Empty Vector") {

	SECTION("Empty Vector") {

		vector<double> default_closing_vector = {};

		vector_tester financials;

		REQUIRE(financials.stock_changes(default_closing_vector) == "empty");
	}
}