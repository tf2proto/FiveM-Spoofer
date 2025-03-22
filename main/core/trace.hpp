#pragma once
#include "common.hpp"

class trace
{
public:
	void setup();
	void destroy();
	void set_launch_build();
	std::string  get_launch_build();

	std::string set_folder(std::string title);
public:
	std::string m_save_path{ "save.txt" };
	std::string m_fivem_path;
	std::string m_citizen_ini_path{ "\\FiveM.app\\CitizenFX.ini" };
};

inline std::unique_ptr<trace> g_trace;