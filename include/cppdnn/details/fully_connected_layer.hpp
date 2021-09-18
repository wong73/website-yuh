#ifndef CPPDNN_HEADER_DETAILS_FULLY_CONNECTED_LAYER_HPP
#define CPPDNN_HEADER_DETAILS_FULLY_CONNECTED_LAYER_HPP

#include <random>
#include <utility>

namespace cppdnn
{
	template<typename Ty_>
	basic_fully_connected_layer<Ty_>::basic_fully_connected_layer(std::size_t unit, st