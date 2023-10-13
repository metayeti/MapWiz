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
//  config.h
//  ---
//  Configuration class for persistent storage.
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef MW_CONFIG_H_
#define MW_CONFIG_H_

#include "../thirdparty/mINI/ini.h"

namespace mw
{
	class Config
	{
	private:
		mINI::INIStructure data;

		/**
		 * Generate default configuration data.
		 */
		void GenerateDefaults();

	public:
		/*
		std::string GetStringValue(std::string const& propertyCategory, std::string const& propertyName);
		uint64_t GetUnsignedIntValue(std::string const& propertyCategory, std::string const& propertyName);
		int64_t GetSignedIntValue(std::string const& propertyCategory, std::string const& propertyName);
		*/

		/**
		 * Read the configuration from the configuration file. If it doesn't exist,
		 * a default file will be created. If the file cannot be read, default values
		 * will be generated instead.
		 */
		void Read();

		/**
		 * Write the configuration to the configuration file.
		 */
		void Write();
	};
}

#endif // MW_CONFIG_H
