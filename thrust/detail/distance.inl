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


/*! \file distance.inl
 *  \brief Inline file for distance.h
 */

#include <thrust/advance.h>
#include <thrust/detail/backend/generic/select_system.h>
#include <thrust/detail/backend/generic/distance.h>
#include <thrust/iterator/iterator_traits.h>

namespace thrust
{

template<typename InputIterator>
  inline typename thrust::iterator_traits<InputIterator>::difference_type
    distance(InputIterator first, InputIterator last)
{
  using thrust::detail::backend::generic::select_system;
  using thrust::detail::backend::generic::distance;

  typedef typename thrust::iterator_space<InputIterator>::type space;

  return distance(select_system(space()), first, last);
} // end distance()

} // end namespace thrust

