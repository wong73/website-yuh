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
		template<template