
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
	public:
		using iterator = typename std::vector<basic_training_set_base_ptr<Ty_>>::iterator;
		using const_iterator = typename std::vector<basic_training_set_base_ptr<Ty_>>::const_iterator;
		using reverse_iterator = typename std::vector<basic_training_set_base_ptr<Ty_>>::reverse_iterator;
		using const_reverse_iterator = typename std::vector<basic_training_set_base_ptr<Ty_>>::const_reverse_iterator;

	public:
		basic_training_data() = default;
		basic_training_data(const std::vector<basic_training_set_base_ptr<Ty_>>& vector);
		basic_training_data(std::vector<basic_training_set_base_ptr<Ty_>>&& vector) noexcept;
		basic_training_data(const basic_training_data& data);
		basic_training_data(basic_training_data&& data) noexcept;
		~basic_training_data() = default;

	public:
		basic_training_data& operator=(const basic_training_data& data) = delete;
		basic_training_data& operator=(basic_training_data&& data) = delete;
		bool operator==(const basic_training_data& data) = delete;
		bool operator!=(const basic_training_data& data) = delete;
		const basic_training_set_base_ptr<Ty_>& operator[](std::size_t index) const noexcept;
		basic_training_set_base_ptr<Ty_>& operator[](std::size_t index) noexcept;

	public:
		const Ty_& at(std::size_t index) const noexcept;
		Ty_& at(std::size_t index) noexcept;
		iterator begin() noexcept;
		const_iterator begin() const noexcept;
		const_iterator cbegin() const noexcept;
		iterator end() noexcept;
		const_iterator end() const noexcept;
		const_iterator cend() const noexcept;
		reverse_iterator rbegin() noexcept;