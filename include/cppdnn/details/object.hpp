
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
	}
	template<typename Ty_>
	void basic_object<Ty_>::print() const
	{
		print(std::cout, true);
	}
	template<typename Ty_>
	void basic_object<Ty_>::print(bool detail) const
	{
		print(std::cout, detail);
	}
	template<typename Ty_>
	void basic_object<Ty_>::print(std::ostream& stream) const
	{
		print(stream, true);
	}
	template<typename Ty_>
	void basic_object<Ty_>::print(std::ostream& stream, bool detail) const
	{
		stream << to_string(detail);
	}
	template<typename Ty_>
	void basic_object<Ty_>::println() const
	{
		println(std::cout, true);
	}
	template<typename Ty_>
	void basic_object<Ty_>::println(bool detail) const
	{
		println(std::cout, detail);
	}
	template<typename Ty_>
	void basic_object<Ty_>::println(std::ostream& stream) const
	{
		println(stream, true);
	}
	template<typename Ty_>
	void basic_object<Ty_>::println(std::ostream& stream, bool detail) const
	{
		stream << to_string(detail) << '\n';