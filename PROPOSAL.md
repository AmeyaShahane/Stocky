# Proposal 
* I am planning to make a project that incorporates the ofxBox2d library.
This is for displaying data from an API via blocks for data that is financial; stocks of top companies.
* Each block will have a logo of the stock as well as a small description of the data collected for the respective
stock.  In addition, the ratio of block sizes will account for how big the stock is with respect to other blocks.
As such, there will be around 50 blocks denoting each stock along with labels with their respective logos. 
* I also plan to add music to the project in order to make it a visually aesthetic and interactive display.
* I will denote the sizes of each block - this is a task that relies on the data collection techniques
via an API.  The API usage will allow me to convert data in ratios respective of the box sizes via the OfBoxSize method
of the library.  I also feel the need to make this display more interactive by having the boxes change shapes in a 
live setting; reformatting and adjusting as per the live API data results converted into sizes respective of the 
data being collected.  For example, if I want to distill data for companies across stock, I will use an API 
that allows me to filter this data and then simultaneously convert this data into ratios to transform into 50 block
sizes; each with a label classifying the stock logos. 
* In case a live setting of the API data extraction is not possible, I will decide to use an upper bound of the 
highest value of stock on a particular day with no outliers.  I will also ensure that the selected day is recent;
in order to make the data extraction and visualization more relevant to recent times.  
* I can also dramaticize the effects of the live stock data by having dramatic sound effects in case there is
a very large difference in the live readings of the data; momentarily.  In addition, I can also tweak the graphic
display background of visualizer in order to ensure that my design is not bland based on the severity of outliers
present in the data being recorded.  
* In addition, I can also mark the outline of each block based on gains and losses.  Ideally, I think
I will use a stocks API for this type of data collection; the Quandl API.  
* If the position interferes greatly with identifying the block sizes, I will decide to keep the blocks stable
in order to ensure that the blocks do not zoom in or out; creating a false perception of the block sizes. 
* In terms of the visualization aspect, I also plan to attach a string message of the block description in a small
yet legibile font that clarifies the company label via its name, date of founding, CEO, and company type.
* In terms of the position aspect of the blocks moving in an empty space, I plan to adjust the mouse and camera 
settings in order to stabilize the blocks to show that the ratios are stabilized as well.  In addition, this is
important to consider with the fact that the string message of each block's label should also be stabilized for
issues concerning readibility and logistics.  
* In all, I got the inspiration for this project using the example Openframeworks library 
using ofxBox2d; given in the assignment details.  
## Links under speculation: 
* https://www.quandl.com/tools/api
* https://docs.quandl.com/
* https://www.exaptive.com/blog/exploring-tech-stocks-a-data-application-versus-data-visualization

* Decided to have closed graph to incorporate ofxBox2d and API correctly. 