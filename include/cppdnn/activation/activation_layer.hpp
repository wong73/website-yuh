#ifndef CPPDNN_HEADER_ACTIVATION_ACTIVATION_LAYER_HPP
#define CPPDNN_HEADER_ACTIVATION_ACTIVATION_LAYER_HPP

#include <cppdnn/layer.hpp>
#include <cppdnn/object.hpp>

namespace cppdnn
{
	template<typename Ty_>
	class basic_activation_layer : public basic_layer<Ty_>
	{
	public:
		basic_activation_layer(const basic_activation_lay