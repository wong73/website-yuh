
#ifndef CPPDNN_HEADER_DETAILS_TRAINING_DATA_HPP
#define CPPDNN_HEADER_DETAILS_TRAINING_DATA_HPP

#include <cppdnn/vector.hpp>

#include <utility>

namespace cppdnn
{
	template<typename Ty_>
	basic_training_data<Ty_>::basic_training_data(const std::vector<basic_training_set_base_ptr<Ty_>>& vector)
		: data_(vector)
	{}
	template<typename Ty_>
	basic_training_data<Ty_>::basic_training_data(std::vector<basic_training_set_base_ptr<Ty_>>&& vector) noexcept
		: data_(std::move(vector))
	{}
	template<typename Ty_>
	basic_training_data<Ty_>::basic_training_data(const basic_training_data& data)
		: data_(data.data_)
	{}
	template<typename Ty_>
	basic_training_data<Ty_>::basic_training_data(basic_training_data&& data) noexcept
		: data_(std::move(data.data_))
	{}

	template<typename Ty_>
	const basic_training_set_base_ptr<Ty_>& basic_training_data<Ty_>::operator[](std::size_t index) const noexcept
	{
		return data_[index];
	}
	template<typename Ty_>
	basic_training_set_base_ptr<Ty_>& basic_training_data<Ty_>::operator[](std::size_t index) noexcept
	{
		return data_[index];
	}

	template<typename Ty_>
	const Ty_& basic_training_data<Ty_>::at(std::size_t index) const noexcept
	{
		return data_.at(index);
	}
	template<typename Ty_>
	Ty_& basic_training_data<Ty_>::at(std::size_t index) noexcept
	{
		return data_.at(index);
	}
	template<typename Ty_>
	typename basic_training_data<Ty_>::iterator basic_training_data<Ty_>::begin() noexcept
	{
		return data_.begin();
	}
	template<typename Ty_>
	typename basic_training_data<Ty_>::const_iterator basic_training_data<Ty_>::begin() const noexcept
	{
		return data_.begin();
	}
	template<typename Ty_>
	typename basic_training_data<Ty_>::const_iterator basic_training_data<Ty_>::cbegin() const noexcept
	{
		return data_.cbegin();
	}
	template<typename Ty_>
	typename basic_training_data<Ty_>::iterator basic_training_data<Ty_>::end() noexcept
	{
		return data_.end();
	}
	template<typename Ty_>
	typename basic_training_data<Ty_>::const_iterator basic_training_data<Ty_>::end() const noexcept
	{
		return data_.end();
	}
	template<typename Ty_>
	typename basic_training_data<Ty_>::const_iterator basic_training_data<Ty_>::cend() const noexcept
	{
		return data_.cend();
	}
	template<typename Ty_>
	typename basic_training_data<Ty_>::reverse_iterator basic_training_data<Ty_>::rbegin() noexcept