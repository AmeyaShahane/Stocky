
#include "C:\Users\Ameya\Desktop\of_v0.10.1_vs2017_release\examples\3d\ofBoxExample\file_reader.h"

#include <regex>
#include <string>
using std::sregex_token_iterator;
using std::string;
using std::regex;

/*
Extracting default values from CSV into collective finances vector
*/
void file_reader::LoadDailyValuesFile() {

	quandl ql;
	ql.auth("rHjGkj7sJk4nxaAMdxGQ"); // Replace <code> with your own token.
	ql.get("EOD/MSFT");
	ifstream reader("C:\\Users\\Ameya\\Desktop\\of_v0.10.1_vs2017_release\\examples\\3d\\ofBoxExample\\bin\\MSFT.csv");
	string Date;
	string Open;
	string High;
	string Low;
	string Close;
	string Volume;
	string Dividend;
	string Split;
	string Adj_Open;
	string Adj_High;
	string Adj_Low;
	string Adj_Close;
	string Adj_Volume;
	int i = 0;
	while (reader >> Date >> Open >> High >> Low >> Close >> Volume >> Dividend >> Split >> Adj_Open >> Adj_High >> Adj_Low >> Adj_Close >> Adj_Volume && i < kYear) {
		i++;

		finances.push_back(Open);
	}

	reader.close();
}

/*
Parsed values of open and closed values into vectors
*/
void file_reader::ParseDailyValues() {
	/**
	 Syntax: https://social.msdn.microsoft.com/Forums/vstudio/en-US/8b393baf-be07-425e-bac8-a28f55cf9b3a/vectorstring-splitting-at-the-comma?forum=vcgeneral
	 **/
	for (int i = finances.size(); i-- > 0; ) {

		string currentLine = finances.at(i);
		regex re(",");
		sregex_token_iterator it(currentLine.begin(), currentLine.end(), re, -1);
		sregex_token_iterator reg_end;
		int indexCounter = 0;
		for (; it != reg_end; ++it) {
			if (indexCounter == kClosedPricesIndex) {
				closed_prices.push_back(stod(it->str()));
			}
			if (indexCounter == kOpenPricesIndex) {
				open_prices.push_back(stod(it->str()));
			}
			indexCounter++;
		}
	}
}

