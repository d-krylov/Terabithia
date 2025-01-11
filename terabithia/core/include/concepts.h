#ifndef TERABITHIA_CONCEPTS_H
#define TERABITHIA_CONCEPTS_H

#include <concepts>
#include <ranges>

namespace Terabithia {

// Ranges

template <typename R>
concept ContiguousSizedRange = std::ranges::contiguous_range<R> && std::ranges::sized_range<R>;

template <typename R, typename T>
concept ContiguousSizedRangeT = ContiguousSizedRange<R> && std::same_as<std::ranges::range_value_t<R>, T>;

template <typename T>
concept PodType = std::is_standard_layout_v<T>;

// Functions

template <typename T> struct FunctionTraits;
template <typename R, typename... Args> struct FunctionTraits<R(Args...)> {
  using Arguments = std::tuple<Args...>;
};

template <typename F, typename... ARGS>
concept CallableWithExactArgs =
  std::same_as<typename FunctionTraits<std::remove_pointer_t<std::decay_t<F>>>::Arguments, std::tuple<std::remove_cvref_t<ARGS>...>>;

// Enums

template <typename T>
concept ScopedEnum = std::is_enum_v<T> && !
std::is_convertible_v<T, std::underlying_type_t<T>>;

template <ScopedEnum T> struct is_allowed_enum : std::false_type {};

template <typename T>
concept AllowedBitmaskEnum = ScopedEnum<T> && is_allowed_enum<T>::value;

template <AllowedBitmaskEnum Enum> constexpr Enum operator|(Enum LHS, Enum RHS) {
  using U = std::underlying_type_t<Enum>;
  return static_cast<Enum>(static_cast<U>(LHS) | static_cast<U>(RHS));
}

template <AllowedBitmaskEnum Enum> constexpr Enum operator&(Enum LHS, Enum RHS) {
  using U = std::underlying_type_t<Enum>;
  return static_cast<Enum>(static_cast<U>(LHS) & static_cast<U>(RHS));
}

#define ALLOW_BITMASK_ENUM(EnumType)                                                                                                       \
  template <> struct is_allowed_enum<EnumType> : std::true_type {};

template <ScopedEnum Enum> constexpr auto Cast(Enum e) noexcept { return static_cast<std::underlying_type_t<Enum>>(e); }

} // namespace Terabithia

#endif // TERABITHIA_CONCEPTS_H