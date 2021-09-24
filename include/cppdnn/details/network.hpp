
#ifndef CPPDNN_HEADER_DETAILS_NETWORK_HPP
#define CPPDNN_HEADER_DETAILS_NETWORK_HPP

#include <utility>

namespace cppdnn
{
	template<typename Ty_>
	basic_network<Ty_>& basic_network<Ty_>::operator<<(const basic_layer_ptr<Ty_>& layer)