#ifndef CPPDNN_HEADER_OBJECT_HPP
#define CPPDNN_HEADER_OBJECT_HPP

#include <cstddef>
#include <functional>
#include <memory>
#include <ostream>
#include <string>
#include <type_traits>
#include <utility>

namespace cppdnn
{
	template<typename Ty_>
	class basic_value;

	template<typename Ty_>
	class basic_object
	{
	public:
		basic_object(const b