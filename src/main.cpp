#include <iostream>
#include <cstdint>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
#include <unordered_map>

uint64_t regs[2048]; // haha turing complete go brrrr

#define checkptr do { if (ptr < 0 || ptr >= 2048) { std::cerr << "PTR out of bounds" << std::endl; return 1; } } while (0)

inline char safeget(std::string &str, int i) {
	if (i < 0 || i >= str.size()) return 0;
	return str[i];
}

inline std::string substr(std::string &str, int i, int len) {
	if (i < 0 || len < 0 || i+len > str.size()) return "";
	return str.substr(i, len);
}

int main(int argc, char *argv[]) {
	if (argc != 2 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
		std::cout << "Usage: " << argv[0] << " <code file>" << std::endl;
		return 1;
	}
	std::ifstream f(argv[1]);
	if (!f.is_open()) {
		std::cerr << "Failed to open file" << std::endl;
		return 1;
	}

	std::vector<std::string> instrs;
	std::string buf;

	while (std::getline(f, buf)) {
		std::string curr = "";
		for (int i = 0; i < buf.size(); i++) {
			if (buf[i] == ' ' || buf[i] == '\t' || buf[i] == '\n' || buf[i] == '\r') {
				if (curr.size() > 0) {
					instrs.push_back(curr);
					curr = "";
				}
			} else {
				curr += buf[i];
			}
		}
		if (curr.size() > 0) instrs.push_back(curr);
	}

	int ptr = 0;
	std::unordered_map<std::string, int> labels;
	for (int is = 0; is < instrs.size(); is++) {
		int i = 0;
		if (instrs[is] == "plap") ptr++;
		else if (instrs[is] == "crot") ptr--;
		else if (instrs[is] == "cunny") std::cout << (char)regs[ptr];
		else if (instrs[is] == "breasts") while (is < instrs.size() && instrs[is] != "thighs") is++;
		else if (substr(instrs[is], 0, 4) == "loli") labels[instrs[is].substr(4)] = is;
		else if (substr(instrs[is], 0, 11) == "getpregnant") {
			checkptr;
			if (regs[ptr] != 0) is = labels[instrs[is].substr(11)];
		} else if (substr(instrs[is], i, 2) == "uo") {
			checkptr;
			i += 2;
			while (safeget(instrs[is], i) == 'h') {
				regs[ptr]++;
				i++;
			}
			if (i != instrs[is].size()) {
				std::cerr << "Invalid instruction " << instrs[is] << std::endl;
				return 1;
			}
		} else if (safeget(instrs[is], 0) == 'o') {
			checkptr;
			i++;
			while (safeget(instrs[is], i) == 'u') {
				regs[ptr]--;
				i++;
			}
			if (i != instrs[is].size()) {
				std::cerr << "Invalid instruction " << instrs[is] << std::endl;
				return 1;
			}
		} else {
			std::cerr << "Invalid instruction " << instrs[is] << std::endl;
		}
	}
	return 0;
}