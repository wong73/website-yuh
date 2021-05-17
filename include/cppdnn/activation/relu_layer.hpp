
#ifndef CPPDNN_HEADER_ACTIVATION_RELU_LAYER_HPP
#define CPPDNN_HEADER_ACTIVATION_RELU_LAYER_HPP

#include <cppdnn/activation/activation_layer.hpp>

namespace cppdnn
{
	template<typename Ty_>
	class basic_relu_layer : public basic_activation_layer<Ty_>
	{
	public:
		basic_relu_layer() noexcept = default;
		basic_relu_layer(const basic_relu_layer& relu) = delete;