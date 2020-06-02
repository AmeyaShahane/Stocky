# Process:

* For starters, I decided to use a 50 block openframeworks ofxBox2d library and I decided to 
modify the number of blocks and sizes.  At first, I decided to code 5 blocks without any for loop
but it appeared to be the case that only 1 method was running and that I had to ensure there was a for loop
in order to create multiple blocks at different positions.  I also decided to experiment with the block
size using the OfDrawBoxSize method based on different iterations of the for loop which point out the 
different blocks being created as the code is sequentially being run.  In addition, I decided to change the 
logo of the box by uploading a Microsoft logo near the size of the actual OpenFramwork logo around
114 x 114 pixel size. For this, I had to provide an absolute path in order to make sure that my png file
was being loaded and read. 

* Something significant that I had to deal with was the box positions which made it seem as if the boxes
were diluting, when in reality, the physics behind the box movement was making them apppear farther
from the screen than usual (ofxBox2d is a physics-based library).  In addition, it is because of this
that I was having issues dealing with casting string-based text dialogues denoting the various descriptions 
of the stocks.  In order to tweak the box sizes to mirror a live reading of parsed data, I also decided 
to use the srand() function that using function time for a pseudo - random number generation of size
integers. This way, I can logically parse the data and change the box ratio sizes in case I want to enact
the live version of the API.   

# Progress By Code Review:

* First Code Review: 

* Got API to complement live data stream from JSON to CSV and in the process of using either QWT or KoolPlot library
for plotting stock line graph for company. 

* Second Code Review:

* Added boundary to stock based on votality, complemented vectorization of parsed API data with GUI info, stabilized
block in space for graph. Deciding to purse option of graphing with blocks to utilize ofBox2dLibrary efficiently.

* By Final Project: 

* Effectively made the net increases and decreases within the closed and opening prices of the 
stock API to reflect in the visualization of each of the box's colors.
* Hard coded vector to generate output based on box size and position along with box coloring.  
* Added parsed vector fiancial values to box visualization complementary behavior to ofApp.cpp.
* Added constructor to scope vectors from file reader to ofApp cpp file in a live setting.
* Changed block colors based on adjacent increases and decreases in stock prices via opening and closing values. 
* Able to parse vector values in project in order to complement box position with vector belonging to API calls. 
* Have oFBitMapString label corresponding to each box's opening value with a label for graphing. 
* Added x and y axis labels for graph of stock; x being timeline and y being stock prices in dollars. 
* Completed presentation of x and y labels as well as the closed and open values visualization of stock.
* Added cpp and header files for vector testing since ofApp does not allow its existence for test cases.
* Added appropriate test cases for testing sub vectors and vectors. 
* Cleared magic numbers across ofApp cpp and file reader cpp files. 
* Added commenting and proper C++ documentation across cpp and header files. 