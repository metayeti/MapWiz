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
//  abstract_map.cpp
//
////////////////////////////////////////////////////////////////////////////////

#include "abstract_map.h"

mw::AbstractMap::AbstractMap()
{
}

mw::AbstractMap::~AbstractMap()
{
}

std::string const& mw::AbstractMap::GetName() const
{
	return name;
}

void mw::AbstractMap::SetName(std::string name)
{
	this->name = name;
}

void mw::AbstractMap::RaiseLayer(size_t index)
{
}

void mw::AbstractMap::LowerLayer(size_t index)
{
}

void mw::AbstractMap::MoveLayer(size_t index, size_t indexTo)
{
}

void mw::AbstractMap::SwapLayers(size_t indexFirst, size_t indexSecond)
{
}