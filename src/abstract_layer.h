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
//  abstract_layer.h
//  ---
//  Abstract class for the layer concept.
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef MW_ABSTRACT_LAYER_H_
#define MW_ABSTRACT_LAYER_H_

namespace mw
{
	class AbstractLayer
	{
	protected:
		// layer name (limited in length by LAYER_NAME_MAX_LENGTH)
		std::string name;

	public:
		AbstractLayer();
		virtual ~AbstractLayer();

		////////////////////////////////////////////////////////////////////////
		//
		//  Layer management
		//
		////////////////////////////////////////////////////////////////////////

		/**
		 * Retreive layer name.
		 * 
		 * @return Layer name.
		 */
		std::string const& GetName() const;

		/**
		 * Set layer name.
		 * 
		 * @param name New layer name.
		 */
		void SetName(std::string name);

		////////////////////////////////////////////////////////////////////////
		//
		//  Serialization
		//
		////////////////////////////////////////////////////////////////////////

		virtual void SerializeBytes(void* bytes) = 0;
	};
}

#endif // MW_ABSTRACT_LAYER_H_
