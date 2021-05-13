//******************************************************
//
// Author       : tetuso 
// Last modified: 2021-02-07 15:09
// Email        : 309114982.com
// blog         : https://blog.csdn.net 
// Filename     : Nocopyable.hpp
// Description  : 
// ******************************************************
#ifndef __WD_NONCOPYABLE_H__
#define __WD_NONCOPYABLE_H__

class Noncopyable
{
protected:
	Noncopyable() {}
	~Noncopyable() {}

	Noncopyable(const Noncopyable&) = delete;
	Noncopyable & operator=(const Noncopyable &) = delete;
};


#endif

