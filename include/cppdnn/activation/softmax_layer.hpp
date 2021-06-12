#ifndef CPPDNN_HEADER_ACTIVATION_SOFTMAX_LAYER_HPP
#define CPPDNN_HEADER_ACTIVATION_SOFTMAX_LAYER_HPP

#include <cppdnn/activation/activation_layer.hpp>

namespace cppdnn
{
	template<typename Ty_>
	class basic_softmax_layer : public basic_activation_layer<Ty_>
	{
	public:
		basic_softmax_layer() noexcept = default;
		basic_softmax_layer(cons