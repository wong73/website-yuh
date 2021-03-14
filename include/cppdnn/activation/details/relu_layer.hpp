#ifndef CPPDNN_HEADER_ACTIVATION_DETAILS_RELU_LAYER_HPP
#define CPPDNN_HEADER_ACTIVATION_DETAILS_RELU_LAYER_HPP

#include <algorithm>

namespace cppdnn
{
	template<typename Ty_>
	void basic_relu_layer<Ty_>::function(const basic_object_ptr<Ty_>& input) const
	{
		input->apply([](const basic_object_ptr<Ty_>& value)
		{
			Ty_& data = to_value_ref(value)->d