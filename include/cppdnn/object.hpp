#ifndef CPPDNN_HEADER_OBJECT_HPP
#define CPPDNN_HEADER_OBJECT_HPP

#include <cstddef>
#include <functional>
#include <memory>
#include <ostream>
#include <string>
#include <type_traits>
#include <utility>

namespace cppdnn
{
	template<typename Ty_>
	class basic_value;

	template<typename Ty_>
	class basic_object
	{
	public:
		basic_object(const basic_object& object) = delete;
		basic_object(basic_object&& object) = delete;
		virtual ~basic_object() = default;
		
	protected:
		basic_object() = default;

	public:
		virtual basic_object& operator=(const basic_object& object) = 0;
		virtual basic_object& operator=(basic_object&& object) = 0;
		virtual bool operator==(const basic_object& object) const = 0;
		virtual bool operator!=(const basic_object& object) const;

		virtual std::shared_ptr<basic_object<Ty_>> operator+(const basic_object& object) const = 0;
		virtual std::shared_ptr<basic_object<Ty_>> operator*(const basic_object& object) const = 0;
		virtual basic_object& operator+=(const basic_object& object) = 0;
		virtual basic_object& operator*=(const basic_object& object) = 0;

	public:
		virtual bool is_value() const noexcept;

		virtual std::shared_ptr<basic_object<Ty_>> copy() const = 0;
		virtual void for_each(const std::function<void(std::shared_ptr<basic_object<Ty_>>)>& func) const = 0;
		virtual void apply(const std::function<void(const std::shared_ptr<basic_object<Ty_>>&)>& func) = 0;

	protected:
		virtual std::string to_string_priv(bool detail) const = 0;

	public:
		std::string to_string() const;
		std::string to_string(bool detail) const;
		void print() const;
		void print(bool detail) const;
		void print(std::ostream& stream) const;
		void print(std::ostream& stream, bool detail) const;
		void println() const;
		void println(bool detail) const;
		void println(std::ostream& stream) const;
		void println(std::ostream& stream, bool detail) const;
	};

	using object = basic_object<double>;
	template<typename Ty_>
	using basic_object_ptr = std::shared_ptr<basic_object<Ty_>>;
	using object_ptr = basic_object_ptr<double>;

	template<typename Ty_>
	