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
		 * Load the default configuration data. Only implemented as a fallback.
		 */
		void LoadDefaults();

	public:
		using T_IntPair = std::pair<int64_t, int64_t>;
		using T_UnsignedIntPair = std::pair<uint64_t, uint64_t>;

		/**
		 * Get a boolean value.
		 */
		bool GetBool(std::string const& category, std::string const& key) const;

		/**
		 * Set a boolean value.
		 */
		void SetBool(std::string const& category, std::string const& key, bool value);

		/**
		 * Get a string value.
		 */
		std::string GetString(std::string const& category, std::string const& key) const;

		/**
		 * Set a string value.
		 */
		void SetString(std::string const& category, std::string const& key, std::string value);

		/**
		 * Get an integer value.
		 */
		int64_t GetInt(std::string const& category, std::string const& key) const;

		/**
		 * Set an integer value.
		 */
		void SetInt(std::string const& category, std::string const& key, int64_t value);

		/**
		 * Get an unsigned integer value.
		 */
		uint64_t GetUnsignedInt(std::string const& category, std::string const& key) const;

		/**
		 * Set an unsigned integer value.
		 */
		void SetUnsignedInt(std::string const& category, std::string const& key, uint64_t value);

		/**
		 * Get an integer pair.
		 */
		T_IntPair GetIntPair(std::string const& category, std::string const& key) const;

		/**
		 * Set an integer pair.
		 */
		void SetIntPair(std::string const& category, std::string const& key, T_IntPair value);

		/**
		 * Get an unsigned integer pair value.
		 */
		T_UnsignedIntPair GetUnsignedIntPair(std::string const& category, std::string const& key) const;

		/**
		 * Set an unsigned integer pair.
		 */
		void SetUnsignedIntPair(std::string const& category, std::string const& key, T_UnsignedIntPair value);

		/**
		 * Read the configuration from the configuration file. If the file doesn't exist,
		 * a default file will be created. If the file cannot be read, use default values.
		 */
		void Read();

		/**
		 * Write the configuration to the configuration file.
		 */
		void Write();
	};
}

#endif // MW_CONFIG_H
