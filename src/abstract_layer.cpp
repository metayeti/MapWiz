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
//  abstract_layer.cpp
//
////////////////////////////////////////////////////////////////////////////////

#include <string>

#include "abstract_layer.h"

mw::AbstractLayer::AbstractLayer()
{
}

mw::AbstractLayer::~AbstractLayer()
{
}

std::string const& mw::AbstractLayer::GetName() const
{
	return name;
}

void mw::AbstractLayer::SetName(std::string name)
{
	this->name = name;
}
