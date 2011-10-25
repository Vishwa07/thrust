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


#pragma once

#include <thrust/detail/config.h>
#include <thrust/detail/backend/generic/tag.h>

namespace thrust
{
namespace detail
{
namespace backend
{
namespace generic
{

template<typename BidirectionalIterator>
  void reverse(tag,
               BidirectionalIterator first,
               BidirectionalIterator last);

template<typename BidirectionalIterator,
         typename OutputIterator>
  OutputIterator reverse_copy(tag,
                              BidirectionalIterator first,
                              BidirectionalIterator last,
                              OutputIterator result);

} // end namespace generic
} // end namespace backend
} // end namespace detail
} // end namespace thrust

#include <thrust/detail/backend/generic/reverse.inl>

