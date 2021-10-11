
#ifndef CPPDNN_HEADER_LAYER_HPP
#define CPPDNN_HEADER_LAYER_HPP

#include <cppdnn/object.hpp>

#include <cstddef>
#include <memory>

namespace cppdnn
{
	template<typename Ty_>
	class basic_layer
	{
	public:
		basic_layer(const basic_layer& layer) = delete;
		basic_layer(basic_layer&& layer) = delete;
		virtual ~basic_layer() = default;

	protected:
		basic_layer() noexcept = default;
	
	public:
		basic_layer& operator=(const basic_layer& layer) = delete;
		basic_layer& operator=(basic_layer&& layer) = delete;
		bool operator==(const basic_layer& layer) = delete;
		bool operator!=(const basic_layer& layer) = delete;
		
	public:
		virtual void forward(const basic_object_ptr<Ty_>& input, basic_object_ptr<Ty_>& output) const = 0;
		basic_object_ptr<Ty_> forward(const basic_object_ptr<Ty_>& input) const;