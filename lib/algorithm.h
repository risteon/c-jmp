// -- BEGIN LICENSE BLOCK ----------------------------------------------
// -- END LICENSE BLOCK ------------------------------------------------
//----------------------------------------------------------------------
/*!\file
 *
 * \author  Christoph Rist <rist.christoph@gmail.com>
 * \date    2017-10-30
 *
 */
//----------------------------------------------------------------------

#ifndef JMP_ALGORITHM_H
#define JMP_ALGORITHM_H

#include <cstdint>
#include <type_traits>
#include <limits>
#include <iterator>
#include <memory>
#include <cassert>


namespace jmp {


/*! @brief Kadane's algorithm. Runs in O(n)
 */
template<typename Iterator>
auto maxContiguousSubarray(Iterator begin, Iterator end,
                           Iterator* sub_begin = nullptr, Iterator* sub_end = nullptr)
-> typename std::decay<decltype(*begin)>::type
{
  assert(begin != end && "Not defined for empty array.");

  using Scalar = typename std::decay<decltype(*begin)>::type;
  Scalar max_so_far = *begin;
  Scalar max_ending_here = *begin;
  Scalar v;

  Iterator sb_so_far = begin;
  Iterator sb_ending_here = begin;
  Iterator se = begin;

  ++begin;
  for ( ; begin != end; ++begin)
  {
    v = max_ending_here + *begin;
    if (v > 0)
    {
      if (max_ending_here == 0)
        sb_ending_here = begin;
      max_ending_here = v;
    }
    else
      max_ending_here = 0;

    if (max_so_far < max_ending_here)
    {
      max_so_far = max_ending_here;
      sb_so_far = sb_ending_here;
      se = begin + 1;
    }

    if (max_ending_here < static_cast<Scalar>(0))
      max_ending_here = static_cast<Scalar>(0);
  }

  if (sub_begin != nullptr)
    *sub_begin = sb_so_far;
  if (sub_end != nullptr)
    *sub_end = se;

  return max_so_far;
};


} //< ns jmp

#endif //< JMP_ALGORITHM_H
