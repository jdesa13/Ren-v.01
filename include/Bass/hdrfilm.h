

#include "Bass/film.h"
#include <complex>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>

#include <ImfInputFile.h>
#include <ImfOutputFile.h>
#include <ImfChannelList.h>
#include <ImfStringAttribute.h>
#include <ImfVersion.h>
#include <ImfIO.h>
#include <ImfArray.h>
#include <ImfNamespace.h>

namespace IMF = OPENEXR_IMF_NAMESPACE;
#pragma once
#ifndef _J_HDR
#define _J_HDR
class hdrfilm : public film {
public:
	hdrfilm() :film(800, 600) {};
	hdrfilm(const unsigned int width, const unsigned int height) :film(width, height) {};
	~hdrfilm() {};
	virtual void save(const std::string &filename, float *ptr);

};
#endif