#ifndef CPPDNN_HEADER_NETWORK_HPP
#define CPPDNN_HEADER_NETWORK_HPP

#include <cppdnn/layer.hpp>
#include <cppdnn/object.hpp>

#include <vector>

namespace cppdnn
{
	template<typename Ty_>
	class basic_network
	{
	public:
		basic_network() = default;
		basic_network(const basic_network& network) = delete;
		basic_network(basic_network&& network) = delete;
		~basic_network() = default;

	public:
		basic_network& operator=(const basic_network& network) = delete;
		basic_network& operator=(basic_network&& network) = delete;
		bool operator==(const basic_network& network) = delete;
		bool operator!=(const basic_network