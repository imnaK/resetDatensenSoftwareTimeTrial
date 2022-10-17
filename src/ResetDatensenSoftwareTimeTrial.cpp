#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;

vector<string> readConfig(const string config_path) {
	vector<string> data;
	std::ifstream input_file(config_path);
    if (input_file.fail() || input_file.bad())
        std::cerr << "Error: Cannot read config file." << std::endl;
	string line;
	for (int i = 0; std::getline(input_file, line); ++i)
		data.push_back(&line[0]);
	input_file.close();
	return data;
}

bool writeToFile(const string file_path, const long long& millis_since_unix_epoch) {
	std::ofstream output_file(file_path);
    if (output_file.fail() || output_file.bad()) {
        std::cerr << "Error: Cannot write to output file." << std::endl;
		return false;
	}
	output_file << std::to_string(millis_since_unix_epoch);
	output_file.close();
	return true;
}

int main(const int argc, const char* argv[]) {
	const long long millis_since_unix_epoch = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

	if (argc < 2){
		std::cerr << "Error: Please add a path to the config file as first argument." << std::endl;
		return 1;
	}

	const vector<string> files_to_change = readConfig(argv[1]);
	for (int i = 0; i < files_to_change.size(); ++i)
		cout << (writeToFile(files_to_change.at(i), millis_since_unix_epoch) ? ("File \"" + files_to_change.at(i) + "\" sucessfully changed.") : ("Failed to change file \"" + files_to_change.at(i) + "\".")) << std::endl;

    return 0;
}