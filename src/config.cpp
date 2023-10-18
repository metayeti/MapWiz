////////////////////////////////////////////////////////////////////////////////
//   _____         _ _ _
//  |     |___ ___| | | |_ ___   2D map editor
//  | | | | . | . | | | | |- _|  version 0.0.2 dev
//  |_|_|_|__,|  _|_____|_|___|  https://github.com/pulzed/MapWiz
//            |_|              
//
//  Licensed under GPL3 ( https://www.gnu.org/licenses/gpl-3.0.en.html )
//  Copyright (c) 2024-present Danijel Durakovic
//
//  Based on the wxWidgets library ( https://www.wxwidgets.org/ )
//
////////////////////////////////////////////////////////////////////////////////
//
//  config.cpp
//
////////////////////////////////////////////////////////////////////////////////

#include <utility>
#include <fstream>

#include "mapwiz.h"
#include "util.h"
#include "config.h"
#include "const.h"
#include "res/ini_resources.h"

void mw::Config::LoadDefaults()
{
	data.clear();
	data["startup"].set({
		{ "center", "yes" },
		{ "position", "0, 0" },
		{ "size", "800, 600" },
		{ "maximized", "no" }
	});
}

bool mw::Config::GetBool(std::string const& category, std::string const& key) const
{
	auto section = data.get(category);
	if (section.has(key))
	{
		std::string& value = section[key];
		Util::StrToLower(value);
		return (value == "yes" || value == "true");
	}
	return false;
}

void mw::Config::SetBool(std::string const& category, std::string const& key, bool value)
{
	data[category][key] = (value) ? "yes" : "no";
}

std::string mw::Config::GetString(std::string const& category, std::string const& key) const
{
	return data.get(category)[key];
}

void mw::Config::SetString(std::string const& category, std::string const& key, std::string value)
{
	data[category][key] = value;
}

int64_t mw::Config::GetInt(std::string const& category, std::string const& key) const
{
	auto section = data.get(category);
	if (section.has(key))
	{
		std::string& value = section[key];
		return std::stoll(value, nullptr, 10);
	}
	return 0;
}

void mw::Config::SetInt(std::string const& category, std::string const& key, int64_t value)
{
	data[category][key] = std::to_string(value);
}

uint64_t mw::Config::GetUnsignedInt(std::string const& category, std::string const& key) const
{
	auto section = data.get(category);
	if (section.has(key))
	{
		std::string& value = section[key];
		return std::stoull(value, nullptr, 10);
	}
	return 0U;
}

void mw::Config::SetUnsignedInt(std::string const& category, std::string const& key, uint64_t value)
{
	data[category][key] = std::to_string(value);
}

mw::Config::T_IntPair mw::Config::GetIntPair(std::string const& category, std::string const& key) const
{
	auto section = data.get(category);
	if (section.has(key))
	{
		std::string& value = section[key];
		auto splitResult = Util::SplitStr(value, ",");
		if (splitResult.size() == 2) {
			for (std::string& result : splitResult) { Util::TrimStr(result); }
			return T_UnsignedIntPair(
				std::stoll(splitResult[0], nullptr, 10),
				std::stoll(splitResult[1], nullptr, 10)
			);
		}
	}
	return T_IntPair(0, 0);
}

void mw::Config::SetIntPair(std::string const& category, std::string const& key, T_IntPair value)
{
	data[category][key] = std::to_string(value.first) + ", " + std::to_string(value.second);
}

mw::Config::T_UnsignedIntPair mw::Config::GetUnsignedIntPair(std::string const& category, std::string const& key) const
{
	auto section = data.get(category);
	if (section.has(key))
	{
		std::string& value = section[key];
		auto splitResult = Util::SplitStr(value, ",");
		if (splitResult.size() == 2) {
			for (std::string& result : splitResult) { Util::TrimStr(result); }
			return T_UnsignedIntPair(
				std::stoull(splitResult[0], nullptr, 10),
				std::stoull(splitResult[1], nullptr, 10)
			);
		}
	}
	return T_UnsignedIntPair(0U, 0U);
}

void mw::Config::SetUnsignedIntPair(std::string const& category, std::string const& key, T_UnsignedIntPair value)
{
	data[category][key] = std::to_string(value.first) + ", " + std::to_string(value.second);
}

void mw::Config::Read(bool& firstRun)
{
	if (!Util::FileExists(FILENAME_CONFIG_INI))
	{
		firstRun = true;
		// config file is missing, create one
		std::ofstream out(FILENAME_CONFIG_INI);
		out << INI_CONFIG;
		out.close();
	}
	else
	{
		firstRun = false;
	}
	// attempt to read the config file
	mINI::INIFile ini(FILENAME_CONFIG_INI);
	if (!ini.read(data)) {
		// could not read config data, load defaults instead
		LoadDefaults();
	}
}

void mw::Config::Write()
{
	mINI::INIFile ini(FILENAME_CONFIG_INI);
	ini.write(data);
}
