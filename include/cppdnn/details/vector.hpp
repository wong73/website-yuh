
#ifndef CPPDNN_HEADER_DETAILS_VECTOR_HPP
#define CPPDNN_HEADER_DETAILS_VECTOR_HPP

#include <cppdnn/exception.hpp>
#include <cppdnn/utility.hpp>

#include <algorithm>
#include <type_traits>
#include <utility>

namespace cppdnn
{
	template<typename Ty_>
	basic_vector<Ty_>::basic_vector(std::size_t size)
	{
		data_.resize(size);
	}
	template<typename Ty_>
	basic_vector<Ty_>::basic_vector(const std::vector<Ty_>& vector)
		: data_(vector)
	{}
	template<typename Ty_>
	basic_vector<Ty_>::basic_vector(std::vector<Ty_>&& vector) noexcept
		: data_(std::move(vector))
	{}
	template<typename Ty_>
	basic_vector<Ty_>::basic_vector(const basic_vector& vector)
		: data_(vector.data_)
	{}
	template<typename Ty_>
	basic_vector<Ty_>::basic_vector(basic_vector&& vector) noexcept
		: data_(vector.data_)
	{}
	template<typename Ty_>
	basic_vector<Ty_>::basic_vector(std::initializer_list<Ty_> list)
		: data_(list)
	{}

	template<typename Ty_>
	basic_vector<Ty_>& basic_vector<Ty_>::operator=(const basic_vector& vector)
	{
		data_ = vector.data_;
		return *this;
	}
	template<typename Ty_>
	basic_vector<Ty_>& basic_vector<Ty_>::operator=(basic_vector&& vector) noexcept
	{
		data_ = std::move(vector.data_);
		return *this;
	}
	template<typename Ty_>
	bool basic_vector<Ty_>::operator==(const basic_vector& vector) const
	{
		if (data_.size() != vector.data_.size()) return false;

		return std::equal(data_.begin(), data_.end(), vector.data_.begin(), vector.data_.end());
	}
	template<typename Ty_>
	bool basic_vector<Ty_>::operator!=(const basic_vector& vector) const
	{
		if (data_.size() != vector.data_.size()) return true;

		return !std::equal(data_.begin(), data_.end(), vector.data_.begin(), vector.data_.end());
	}
	template<typename Ty_>
	const Ty_& basic_vector<Ty_>::operator[](std::size_t index) const noexcept
	{
		return data_[index];
	}
	template<typename Ty_>
	Ty_& basic_vector<Ty_>::operator[](std::size_t index) noexcept
	{
		return data_[index];
	}

	template<typename Ty_>
	basic_object<Ty_>& basic_vector<Ty_>::operator=(const basic_object<Ty_>& object)
	{
		if (!instance_of<basic_vector<Ty_>>(&object))
			throw invalid_type("Argument 'object' can't be converted to cppdnn::basic_vector.");