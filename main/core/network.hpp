#pragma once
#include "common.hpp"

class network
{
public:
	void setup();
	void destroy();
private:
	void block_connection(std::string process);
	void unblock_connection(std::string process);
};

inline std::unique_ptr<network> g_network; 

delete 