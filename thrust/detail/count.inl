/*
 *  Copyright 2008-2011 NVIDIA Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */


/*! \file count.inl
 *  \brief Inline file for count.h.
 */

#include <thrust/detail/config.h>
#include <thrust/count.h>
#include <thrust/iterator/iterator_traits.h>
#include <thrust/detail/backend/generic/select_system.h>
#include <thrust/detail/backend/generic/count.h>

namespace thrust
{

template <typename InputIterator, typename EqualityComparable>
typename thrust::iterator_traits<InputIterator>::difference_type
count(InputIterator first, InputIterator last, const EqualityComparable& value)
{
  using thrust::detail::backend::generic::select_system;
  using thrust::detail::backend::generic::count;

  typedef typename thrust::iterator_space<InputIterator>::type space;

  return count(select_system(space()), first, last, value);
} // end count()

template <typename InputIterator, typename Predicate>
typename thrust::iterator_traits<InputIterator>::difference_type
count_if(InputIterator first, InputIterator last, Predicate pred)
{
  using thrust::detail::backend::generic::select_system;
  using thrust::detail::backend::generic::count_if;

  typedef typename thrust::iterator_space<InputIterator>::type space;

  return count_if(select_system(space()), first, last, pred);
} // end count_if()

} // end namespace thrust

