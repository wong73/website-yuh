#ifndef CPPDNN_HEADER_EXCEPTION_HPP
#define CPPDNN_HEADER_EXCEPTION_HPP

#include <stdexcept>
#include <string>

namespace cppdnn
{
#define ERROR(base, name)										\
	class name : public std:: base								\
	{															\
	public:														\
		using std:: base :: base;								\
	}
#d