#ifndef CPPDNN_HEADER_DETAILS_FULLY_CONNECTED_LAYER_HPP
#define CPPDNN_HEADER_DETAILS_FULLY_CONNECTED_LAYER_HPP

#include <random>
#include <utility>

namespace cppdnn
{
	template<typename Ty_>
	basic_fully_connected_layer<Ty_>::basic_fully_connected_layer(std::size_t unit, std::size_t input)
	{
		weights_.reserve(unit);
		bias_.resize(input);

		std::random_device rd;
		std::mt19937_64 mt(rd());
		std::uniform_real_distribution<double> dist(-1, 1);

		for (std::size_t i = 0; i < unit; ++i)
		{
			std::vector<Ty_> vec;
			vec.resize(input);

			for (std::size_t j = 0; j < input; ++j)
			{
				vec[j] = dist(mt);
			}

			weights_.push_back(std::make_shared<basic_vector<Ty_>>(std::move(vec)));
		}

		for (std::size_t i = 0; i < input; ++i)
		{
