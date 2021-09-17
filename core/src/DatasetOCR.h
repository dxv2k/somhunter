#include <stdio.h> 
#include <set> 
#include <vector>

#include <string>
#include <fstream>
#include <streambuf>

#include "json11.hpp"

//std::string 
void 
parse_json_dataset(const std::string& filepath){
	std::ifstream ifs(filepath);

	// Get json file content
	std::string file_contents((std::istreambuf_iterator<char>(ifs)),
					std::istreambuf_iterator<char>());

	std::string err;
	auto json{ json11::Json::parse(file_contents, err) };

	if (!err.empty()) {
		std::string msg{ "Error parsing JSON config file: " +
			         filepath };
		warn(msg);
		throw std::runtime_error(msg);
	}
	std::cout << json.dump() << std::endl; 
}

class DatasetOCR {

// *** LOADED DATASET ***	
// Parse JSON file from OCR model

// In JSON file: [Bbox, (result text, confident)]


// *** SEARCH [TEXT, THRESHOLD_LIMIT_FILTER] ***	
// Input text & threshold confidence 
// E.g: "2012"  "0.9" 


// Compute similarity between text (input & dataset) 
// Simple solution is compare string -> True/False

// Searching for similar text based on <ImageID, OCR_text> & input_text 

// Return display (look for get_topn_display() as an example)  
// Example: FramePointerRange  {function_name}(string input_text) 

private: 
	size_t n; 

	 //store <frameID, text string> 
	std::vector<string> data;  
public: 

};


