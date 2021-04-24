#ifndef CPPDNN_HEADER_ACTIVATION_DETAILS_SOFTMAX_LAYER_HPP
#define CPPDNN_HEADER_ACTIVATION_DETAILS_SOFTMAX_LAYER_HPP

#include <cmath>

namespace cppdnn
{
	template<typename Ty_>
	void basic_softmax_layer<Ty_>::forward(const basic_object_ptr<Ty_>& input, basic_object_ptr<Ty_>& output) const
	{
		output = input->copy();

		Ty_ sum = 0;
		input->for_each([&sum](basic_object_ptr<Ty_> value) mutable
		{
			sum += std::exp(to_value_ref(value)->data());
		});

		output->apply([sum](const basic_object_ptr<Ty_>& value)
		{
			Ty_ temp = to_value_ref(value)->d