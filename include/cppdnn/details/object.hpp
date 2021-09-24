
#ifndef CPPDNN_HEADER_DETAILS_OBJECT_HPP
#define CPPDNN_HEADER_DETAILS_OBJECT_HPP

#include <cppdnn/exception.hpp>
#include <cppdnn/utility.hpp>

namespace cppdnn
{
	template<typename Ty_>
	bool basic_object<Ty_>::operator!=(const basic_object& object) const
	{
		return !operator==(object);
	}

	template<typename Ty_>
	bool basic_object<Ty_>::is_value() const noexcept
	{
		return false;
	}

	template<typename Ty_>
	std::string basic_object<Ty_>::to_string() const
	{
		return to_string(true);
	}
	template<typename Ty_>
	std::string basic_object<Ty_>::to_string(bool detail) const
	{
		return to_string_priv(detail);