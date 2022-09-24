#ifndef CPPDNN_HEADER_VECTOR_HPP
#define CPPDNN_HEADER_VECTOR_HPP

#include <cppdnn/object.hpp>

#include <cstddef>
#include <initializer_list>
#include <memory>
#include <vector>

namespace cppdnn
{
	namespace details
	{
		template<typename Ty_>
		struct is_object_ptr
		{
			static constexpr bool value = true;
		};
		template<template<typename> typename Ty_, typename Elem_>
		struct is_object_ptr<std::shared_ptr<Ty_<Elem_>>>
		{
			static constexpr bool value = std::is_base_of<basic_object<Elem_>, Ty_<Elem_>>::value;
		};
	}

	template<typename Ty_>
	class basic_vector : public basic_object<Ty_>
	{
	public:
		using iterator = typename std::vector<Ty_>::iterator;
		using const_iterator = typename std::vector<Ty_>::const_iterator;
		using reverse_iterator = typename std::vector<Ty_>::reverse_iterator;
		using const_reverse_iterator = typename std::vector<Ty_>::const_reverse_iterator;

	public:
		basic_vector() = default;
		basic_vector(std::size_t size);
		basic_vector(const std::vector<Ty_>& vector);
		basic_vector(std::vector<Ty_>&& vector) noexcept;
		basic_vector(const basic_vector& vector);
		basic_vector(basic_vector&& vector) noexcept;
		basic_v