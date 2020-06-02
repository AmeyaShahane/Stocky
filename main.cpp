#include "ofMain.h"
#include "ofApp.h"
#include "C:\Users\Ameya\Desktop\of_v0.10.1_vs2017_release\examples\3d\ofBoxExample\file_reader.h"
#include "C:\Users\Ameya\Desktop\of_v0.10.1_vs2017_release\examples\3d\ofBoxExample\QuandlAPI.h"
#include <vector>

using namespace std;

////========================================================================
int main() {

	file_reader read; // instance of file reader
	read.LoadDailyValuesFile(); // loading value from CSV into collective finances vector
	read.ParseDailyValues(); // creating sub vectors from finance vector into closed and open price vectors

	int index = 0; // index 
	std::cout << read.closed_prices.size(); // default to ensure program is okay

	ofSetupOpenGL(30000, 30000, OF_WINDOW);			// <-------- setup the GL context

//// this kicks off the running of my app
//// can be OF_WINDOW or OF_FULLSCREEN
//// pass in width and height too:

	ofRunApp(new ofApp(read.closed_prices, read.open_prices)); // constructor passed into constructor from file reader to ofApp

	return 0; // int main returns 0

}