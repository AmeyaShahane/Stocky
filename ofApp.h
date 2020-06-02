#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {
public:

	vector<double> closing; // vector of closing stock value prices
	vector<double> opening; // vector of opening stock value prices

	ofApp(vector<double> close, vector<double> open); // Constructor from file reader to OfApp cpp files

	void setup(); // setup console
	void update(); // update console
	void draw(); // draw method for boxes and axis
	void GraphOpenValues(); // graphing open values as boxes
	void GraphClosedValues(); // graphing closed values as boxes



	ofImage ofLogo; // the OF logo
	ofLight light; // creates a light and enables lighting
	ofEasyCam cam; // add mouse controls for camera movement

	int kLineIdealWidth = 2; // default box line width
	int kHeight = 30000; // box height
	int kWidth = 30; // box width
	int kLength = 30; // box length 
	int kIndexMultiplier = 40; // multiplier for box position in space
	int kZDimension = 20; // z dimension of box
	int kDateWidth = 0; // bit map string "date" width
	int kDateHeight = -3500; // bit map string "date" height
	int kPricesWidth = -8000; // bit map string "prices" width
	int kPricesHeight = 500; // bit map string "prices" height 
	int kLabelDim = 100; // default label value
	int kIndexTranslator = 4000; // box position translation
	int kTitleWidth = -5000; // bit map string "title" width
	int kTitleHeight = 3600; // bit map string "title" height
	int kXAxisXDim = -5000; // X axis X dimension
	int kXAxisYDim = -3000; // X axis Y dimension
	int kYAxisXDim = -7000; // Y axis X dimension
	int kYAxisYDim = -5000; // Y axis Y dimension 


};

