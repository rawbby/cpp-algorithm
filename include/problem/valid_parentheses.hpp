#pragma once

#include <iostream> // std::cout
#include <stack>    // std::stack
#include <string>   // std::string

namespace problem {
namespace impl {
// adapts the stack pattern: use a stack to track open brackets and ensure they
// are closed in the correct order by the corresponding closing bracket
inline auto
is_valid(
  std::string const& s) -> bool
{
  auto st = std::stack<char>{};
  for (auto const c : s) {
    if (c == '(') st.push(')');
    else if (c == '{') st.push('}');
    else if (c == '[') st.push(']');
    else if (st.empty() || st.top() != c) return false;
    else st.pop();
  }
  return st.empty();
}
} // namespace impl

inline void
valid_parentheses()
{
  auto const s_in = std::string{ "()[]{}" };

  std::cout << "Valid Parentheses problem (stack simulation pattern)\n";
  std::cout << "time-complexity:  O(N)\n";
  std::cout << "space-complexity: O(N) auxiliary\n";

  std::cout << "In:         " << s_in << '\n';
  std::cout << "Is Valid:   " << (impl::is_valid(s_in) ? "true" : "false") << '\n';
}
} // namespace problem
