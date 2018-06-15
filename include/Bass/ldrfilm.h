#include "Bass/film.h"

#pragma once
#ifndef _J_LDR
#define _J_LDR
class ldrfilm : public film {
protected:
	unsigned int mFormat;


public:

	ldrfilm();
	ldrfilm(int weigth, int height, unsigned int type);
	~ldrfilm();
	virtual void save(const std::string &filename, float *ptr);
	int GetFormat();
	void SetFormat(int type);
};

#endif