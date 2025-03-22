#include "network.hpp"
#include "trace.hpp"

void network::block_connection(std::string process)
{
	std::string outbound = "netsh advfirewall firewall add rule name = " + process + " dir = out program = " + process + "  action = block";
	system(outbound.c_str());

	std::string inbound = "netsh advfirewall firewall add rule name = " + process + " dir = in program = " + process + "  action = block";
	system(inbound.c_str());
}

void network::unblock_connection(std::string process)
{
	std::string outbound = "netsh advfirewall firewall delete rule name = " + process + " dir = out program = " + process;
	system(outbound.c_str());

	std::string inbound = "netsh advfirewall firewall delete rule name = " + process + " dir = in program = " + process;
	system(inbound.c_str());
}

void network::setup()
{
	// Locate FiveM.exe
	auto fivem_path = g_trace->m_fivem_path + "\\" + "FiveM.exe";
	block_connection(fivem_path);


	// Locate FiveM Subprocesses path
	auto subprocess_path = g_trace->m_fivem_path + "\\" + "FiveM.app" + "\\" + "data" + "\\" + "cache" + "\\" "subprocess";

	std::vector<std::string> gta_versions{ "b2545_", "b2372_", "b2189_", "b2060_",  "" };

	for (auto processes : gta_versions)
	{
		// Block the gta processes
		auto gta_process = subprocess_path + "\\" + "FiveM_" + processes + "GTAProcess.exe";
		block_connection(gta_process);

		// Block the steam processes
		auto steam_process = subprocess_path + "\\" + "FiveM_" + processes + "SteamChild.exe";
		
		block_connection(steam_process);
	}	// Block the steam processes
		auto steam_process = subprocess_path + "\\" + "FiveM_" + processes + "SteamChild.exe";
		block_connection(steam_process);

}


void network::destroy()
{
	// Locate FiveM.exe
	auto fivem_path = g_trace->m_fivem_path + "\\" + "FiveM.exe";
	unblock_connection(fivem_path);

	// Locate FiveM Subprocesses path
	auto subprocess_path = g_trace->m_fivem_path + "\\" + "FiveM.app" + "\\" + "data" + "\\" + "cache" + "\\" "subprocess";

	std::vector<std::string> gta_versions{ "b2545_", "b2372_", "b2189_", "b2060_",  "" };

	for (auto processes : gta_versions)
	{
		// Block the gta processes
		auto gta_process = subprocess_path + "\\" + "FiveM_" + processes + "GTAProcess.exe";
		unblock_connection(gta_process);

		// Block the steam processes
		auto steam_process = subprocess_path + "\\" + "FiveM_" + processes + "SteamChild.exe";
		unblock_connection(steam_process);
	}
}
