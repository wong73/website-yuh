
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
