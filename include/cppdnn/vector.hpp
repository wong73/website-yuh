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

	template<