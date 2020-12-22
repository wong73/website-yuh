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
		basic_activation_layer(const basic_activation_layer& layer) = delete;
		basic_activation_layer(basic_activation_layer&& layer) = delete;
		virtual ~basic_activation_layer() override = default;

	protected:
		basic_activation_layer() noexcept = default;

	public:
		basic_activation_lay