
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
	}

	template<typename Ty_>
	std::ostream& operator<<(std::ostream& stream, const basic_object<Ty_>& object)
	{
		return object.print(stream), stream;
	}
	template<typename Ty_>
	std::ostream& operator<<(std::ostream& stream, const basic_object_ptr<Ty_>& object)
	{
		return object->print(stream), stream;
	}
}

namespace cppdnn
{
	template<typename Ty_>
	basic_value<Ty_>::basic_value(const Ty_& value) noexcept(std::is_nothrow_copy_constructible<Ty_>::value)
		: data_(value)
	{}
	template<typename Ty_>
	basic_value<Ty_>::basic_value(Ty_ && value) noexcept(std::is_nothrow_move_constructible<Ty_>::value)
		: data_(std::move(value))
	{}
	template<typename Ty_>
	basic_value<Ty_>::basic_value(const basic_value& value)noexcept(std::is_nothrow_copy_constructible<Ty_>::value)
		: data_(value.data_)
	{}
	template<typename Ty_>
	basic_value<Ty_>::basic_value(basic_value&& value) noexcept(std::is_nothrow_move_constructible<Ty_>::value)
		: data_(std::move(value.data_))
	{}

	template<typename Ty_>
	basic_value<Ty_>& basic_value<Ty_>::operator=(const basic_value& value) noexcept(std::is_nothrow_copy_assignable<Ty_>::value)
	{
		data_ = value.data_;
		return *this;
	}
	template<typename Ty_>
	basic_value<Ty_>& basic_value<Ty_>::operator=(basic_value&& value) noexcept(std::is_nothrow_move_assignable<Ty_>::value)
	{
		data_ = std::move(value.data_);
		return *this;
	}
	template<typename Ty_>
	bool basic_value<Ty_>::operator==(const basic_value& value) const noexcept(noexcept(std::declval<Ty_>() == std::declval<Ty_>()))
	{
		return data_ == value.data_;
	}
	template<typename Ty_>
	bool basic_value<Ty_>::operator!=(const basic_value& value) const noexcept(noexcept(std::declval<Ty_>() != std::declval<Ty_>()))
	{
		return data_ != value.data_;
	}

	template<typename Ty_>
	basic_object<Ty_>& basic_value<Ty_>::operator=(const basic_object<Ty_>& object)
	{
		if (!instance_of<basic_value>(&object))
			throw invalid_type("Argument 'object' can't be converted to cppdnn::basic_value.");

		return operator=(dynamic_cast<const basic_value&>(object));
	}
	template<typename Ty_>
	basic_object<Ty_>& basic_value<Ty_>::operator=(basic_object<Ty_>&& object)
	{
		if (!instance_of<basic_value>(&object))
			throw invalid_type("Argument 'object' can't be converted to cppdnn::basic_value.");

		return operator=(dynamic_cast<basic_value&&>(object));
	}
	template<typename Ty_>
	bool basic_value<Ty_>::operator==(const basic_object<Ty_>& object) const
	{
		if (!instance_of<basic_value>(&object))
			throw invalid_type("Argument 'object' can't be converted to cppdnn::basic_value.");

		return operator==(dynamic_cast<const basic_value&>(object));
	}
	template<typename Ty_>
	bool basic_value<Ty_>::operator!=(const basic_object<Ty_>& object) const
	{
		if (!instance_of<basic_value>(&object))
			throw invalid_type("Argument 'object' can't be converted to cppdnn::basic_value.");

		return operator!=(dynamic_cast<const basic_value&>(object));
	}

	template<typename Ty_>
	basic_value<Ty_> basic_value<Ty_>::operator+(const basic_value& value) const noexcept(noexcept(std::declval<Ty_>() + std::declval<Ty_>()))
	{
		return basic_value(data_ + value.data_);
	}
	template<typename Ty_>
	basic_value<Ty_> basic_value<Ty_>::operator+(const basic_value_ref<Ty_>& value) const noexcept(noexcept(std::declval<Ty_>() + std::declval<Ty_>()))
	{
		return basic_value(data_ + value.data());
	}
	template<typename Ty_>
	basic_value<Ty_> basic_value<Ty_>::operator-(const basic_value& value) const noexcept(noexcept(std::declval<Ty_>() - std::declval<Ty_>()))
	{
		return basic_value(data_ - value.data_);
	}
	template<typename Ty_>
	basic_value<Ty_> basic_value<Ty_>::operator-(const basic_value_ref<Ty_>& value) const noexcept(noexcept(std::declval<Ty_>() - std::declval<Ty_>()))
	{
		return basic_value(data_ - value.data());
	}
	template<typename Ty_>
	basic_value<Ty_> basic_value<Ty_>::operator*(const basic_value& value) const noexcept(noexcept(std::declval<Ty_>() * std::declval<Ty_>()))
	{
		return basic_value(data_ * value.data_);
	}
	template<typename Ty_>
	basic_value<Ty_> basic_value<Ty_>::operator*(const basic_value_ref<Ty_>& value) const noexcept(noexcept(std::declval<Ty_>() * std::declval<Ty_>()))
	{