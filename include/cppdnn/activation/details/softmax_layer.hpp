#ifndef CPPDNN_HEADER_ACTIVATION_DETAILS_SOFTMAX_LAYER_HPP
#define CPPDNN_HEADER_ACTIVATION_DETAILS_SOFTMAX_LAYER_HPP

#include <cmath>

namespace cppdnn
{
	template<typename Ty_>
	void basic_softmax_layer<Ty_>::forward(const basic_object_ptr<Ty_>& input, basic_object_ptr<Ty_>& out