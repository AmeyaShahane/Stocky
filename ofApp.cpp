#include "ofApp.h"
ofSoundPlayer mySound;
ofImage myImage;
#include "C:\Users\Ameya\Desktop\of_v0.10.1_vs2017_release\examples\3d\ofBoxExample\file_reader.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetVerticalSync(true);

	// this uses depth information for occlusion 
	// rather than always drawing things on top of each other
	ofEnableDepthTest();

	// ofBox uses texture coordinates from 0-1, so you can load whatever 
	// sized images you want and still use them to texture your box 
	// but we have to explicitly normalize our tex coords here 
	ofEnableNormalizedTexCoords();

	// Loads the OF logo from disk
	mySound.load("C:\\Users\\Ameya\\Downloads\\SystemMusic.mp3");
	mySound.play();
	myImage.load("C:\\Users\\Ameya\\Desktop\\wallstreetbg.jpg");

	// Draw the ofBox outlines with appropriate width 
	ofSetLineWidth(kLineIdealWidth);
}


//--------------------------------------------------------------
void ofApp::update() {

}

/*
Default constructor for passing in vectors from file reader to ofApp cpp file
*/
ofApp::ofApp(vector<double> setClose, vector<double> setOpen) {
	closing = setClose;
	opening = setOpen;
}

//--------------------------------------------------------------
/*
Draw method to draw boxes for open and closed values along with axis.
*/
void ofApp::draw() {

	// default background is black
	ofBackground(0, 0, 0);

	// starting camera for console display 
	cam.begin();

	// Drawing bit map string of title 
	ofDrawBitmapString("MICROSOFT OPEN AND CLOSED PRICES", kTitleWidth, kTitleHeight);

	// graph open vals 
	GraphOpenValues();

	// graph close vals
	GraphClosedValues();

	// ending console display output 
	cam.end();
}

void ofApp::GraphOpenValues() {

	// default open x value
	int x_val_open = -7000;

	// default number of boxes for 365 days in 1 year
	int boxCount = 365;

	// looping 365 for the creation of 365 boxes respective to vectorization of information 
	for (int i = 0; i < boxCount; i++) {

		// first instance of iteration allows illustration of x and y axis in console space
		if (i == 0) {

			ofBoxPrimitive x_axis; // x axis 
			x_axis.set(kHeight, kWidth, kLength); //size
			x_axis.setPosition(kXAxisXDim, kXAxisYDim, kZDimension); // position in space  
			x_axis.draw(); // process of drawing x axis
			ofDrawBitmapString("DATES", kDateWidth, kDateHeight); // drawing bit map string of "Dates"

			ofBoxPrimitive y_axis; // y axis
			y_axis.set(kLength, kHeight, kWidth); // size 
			y_axis.setPosition(kYAxisXDim, kYAxisYDim, kZDimension); // position in space
			y_axis.draw(); // process of drawing y axis 
			ofDrawBitmapString("PRICES", kPricesWidth, kPricesHeight); // drawing bit map string of "Prices"

		}

		ofPushMatrix();

		// vectorization of blocks for open price positions
		ofVec3f open_pos;

		// open value positions for each block in space 
		open_pos.set(x_val_open, opening.at(i) * kIndexMultiplier - kIndexTranslator, kZDimension);

		// incremented x value for block
		x_val_open += 50;

		// default box size in space
		float boxSize = 10;

		// process of translating vector values in space
		ofTranslate(open_pos);

		//ofLogo.load("C:\\Users\\Ameya\\Desktop\\of_v0.10.1_vs2017_release\\examples\\3d\\ofBoxExample\\bin\\data\\microsoftImg.png");

		/*
		Default box logo structure
		*/
		ofLogo.bind();
		ofFill();
		ofSetColor(155);
		ofDrawBox(boxSize);
		ofLogo.unbind();
		ofNoFill();

		/*
		Changes box color based on whether there is an incrementation or decrease in box prices.
		*/
		if (i != 0 && opening.at(i - 1) > opening.at(i)) {
			ofSetColor(ofColor::red);
		}
		else {
			ofSetColor(ofColor::green);
		}

		ofDrawBitmapString(opening.at(i), kLabelDim, kLabelDim); // default box labels dimensions 

		ofDrawBox(boxSize); // draws box based on adjusted size

		ofPopMatrix(); // default 
	}
}

void ofApp::GraphClosedValues() {

	// default open x value
	int x_val_close = -7000;

	// default number of boxes for 365 days in 1 year
	int boxCount = 365;

	// looping 365 for the creation of 365 boxes respective to vectorization of information 
	for (int i = 0; i < boxCount; i++) {

		ofPushMatrix();

		// vectorization of blocks for closed price positions
		ofVec3f closed_pos;

		// open value positions for each block in space 
		closed_pos.set(x_val_close, closing.at(i) * kIndexMultiplier - kIndexTranslator, kZDimension);

		// incremented x value for each block 
		x_val_close += 50;

		// default box size
		float boxSize = 10;

		// process of translating vector values in space
		ofTranslate(closed_pos);


		/*
		Default box logo structure
		*/
		//ofLogo.load("C:\\Users\\Ameya\\Desktop\\of_v0.10.1_vs2017_release\\examples\\3d\\ofBoxExample\\bin\\data\\microsoftImg.png");
		ofLogo.bind();
		ofFill();
		ofSetColor(155);
		ofDrawBox(boxSize);
		ofLogo.unbind();
		ofNoFill();

		/*
		Changes box color based on whether there is an incrementation or decrease in box prices.
		*/
		if (i != 0 && closing.at(i - 1) > closing.at(i)) {
			ofSetColor(ofColor::red);
		}
		else {
			ofSetColor(ofColor::green);
		}

		ofDrawBitmapString(closing.at(i), kLabelDim, kLabelDim); // default box labels dimensions 

		ofDrawBox(boxSize); // draws box based on adjusted size

		ofPopMatrix(); // default 
	}
}