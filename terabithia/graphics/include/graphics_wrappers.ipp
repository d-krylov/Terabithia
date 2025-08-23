#ifndef GRAPHICS_WRAPPERS_IPP
#define GRAPHICS_WRAPPERS_IPP

namespace Terabithia {

#ifdef GL_DEBUG
template <typename FUNCTION, typename... ARGUMENTS>
inline auto GL_CALL(FUNCTION &&function, ARGUMENTS &&...arguments) {
  if constexpr (std::is_void_v<std::invoke_result_t<FUNCTION, ARGUMENTS...>>) {
    std::forward<FUNCTION>(function)(std::forward<ARGUMENTS>(arguments)...);
    auto error = GetError();
    CORE_ASSERT(error == ErrorCode::NO_ERROR, ToString(error));
  } else {
    auto result = std::forward<FUNCTION>(function)(std::forward<ARGUMENTS>(arguments)...);
    auto error = GetError();
    CORE_ASSERT(error == ErrorCode::NO_ERROR, ToString(error));
    return result;
  }
}
#else
#define GL_CALL(function, ...) function(__VA_ARGS__)
#endif

template <typename... T>
inline void Enable(T... capabilities) {
  (Enable(capabilities), ...);
}

template <typename... T>
inline void Disable(T... capabilities) {
  (Disable(capabilities), ...);
}

} // namespace Terabithia

#endif // GRAPHICS_WRAPPERS_IPP