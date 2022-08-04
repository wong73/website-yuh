
#ifndef CPPDNN_HEADER_TRAINING_DATA_HPP
#define CPPDNN_HEADER_TRAINING_DATA_HPP

#include <cppdnn/object.hpp>

#include <cstddef>
#include <memory>
#include <utility>
#include <vector>

namespace cppdnn
{
	template<typename Ty_>
	class basic_training_set_base
	{
	public:
		basic_training_set_base(const basic_training_set_base& set) = delete;
		basic_training_set_base(basic_training_set_base&& set) = delete;
		virtual ~basic_training_set_base() = default;

	protected:
		basic_training_set_base() noexcept = default;

	public:
		basic_training_set_base& operator=(const basic_training_set_base& set) = delete;
		basic_training_set_base& operator=(basic_training_set_base&& set) = delete;
		bool operator==(const basic_training_set_base& set) = delete;
		bool operator!=(const basic_training_set_base& set) = delete;
		
	public:
		virtual basic_object_ptr<Ty_> input() const = 0;
		virtual basic_object_ptr<Ty_> output() const = 0;
	};

	using training_set_base = basic_training_set_base<double>;
	template<typename Ty_>
	using basic_training_set_base_ptr = std::shared_ptr<basic_training_set_base<Ty_>>;
	using training_set_base_ptr = basic_training_set_base_ptr<double>;

	template<typename Ty_>
	class basic_training_data final
	{